#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/un.h>

// https://stackoverflow.com/questions/5339200/how-to-create-a-single-instance-application-in-c-or-c

#define SOCKET_NAME "/tmp/exampled"

static int socket_fd = -1;
static bool isdaemon = false;
static bool run = true;

/* returns
 *   -1 on errors
 *    0 on successful server bindings
 *   1 on successful client connects
 */
int singleton_connect(const char *name)
{
    int len, tmpd;
    struct sockaddr_un addr = {0};

    if ((tmpd = socket(AF_UNIX, SOCK_DGRAM, 0)) < 0) {
        printf("Could not create socket: '%s'.\n", strerror(errno));
        return -1;
    }

    /* fill in socket address structure */
    addr.sun_family = AF_UNIX;
    strcpy(addr.sun_path, name);
    len = offsetof(struct sockaddr_un, sun_path) + strlen(name);

    int ret;
    unsigned int retries = 1;
    do {
        /* bind the name to the descriptor */
        ret = bind(tmpd, (struct sockaddr *)&addr, len);
        /* if this succeeds there was no daemon before */
        if (ret == 0)
        {
            socket_fd = tmpd;
            isdaemon = true;
            return 0;
        }
        else
        {
            if (errno == EADDRINUSE)
            {
                ret = connect(tmpd, (struct sockaddr *) &addr, sizeof(struct sockaddr_un));

                if (ret != 0)
                {
                    if (errno == ECONNREFUSED)
                    {
                        printf("Could not connect to socket - assuming daemon died.\n");
                        unlink(name);
                        continue;
                    }

                    printf("Could not connect to socket: '%s'.\n", strerror(errno));
                    continue;
                }

                printf("Daemon is already running.\n");
                socket_fd = tmpd;
                return 1;
            }

            printf("Could not bind to socket: '%s'.\n", strerror(errno));
            continue;
        }

    } while (retries-- > 0);

    printf("Could neither connect to an existing daemon nor become one.\n");
    close(tmpd);

    return -1;
}

static void cleanup(void)
{
    if (socket_fd >= 0)
    {
        if (isdaemon)
        {
            if (unlink(SOCKET_NAME) < 0)
                printf("Could not remove FIFO.\n");
        }
        else
        {
            close(socket_fd);
        }
    }
}

static void handler(int sig)
{
    run = false;
}

int main(int argc, char **argv)
{
    switch (singleton_connect(SOCKET_NAME))
    {
    case 0:
    {
        /* Daemon */

        struct sigaction sa;
        sa.sa_handler = &handler;
        sigemptyset(&sa.sa_mask);

        if (sigaction(SIGINT, &sa, NULL) != 0
            || sigaction(SIGQUIT, &sa, NULL) != 0
            || sigaction(SIGTERM, &sa, NULL) != 0)
        {
            printf("Could not set up signal handlers!\n");
            cleanup();
            return EXIT_FAILURE;
        }

        struct msghdr msg = {0};
        struct iovec iovec;
        int client_arg;
        iovec.iov_base = &client_arg;
        iovec.iov_len = sizeof(client_arg);
        msg.msg_iov = &iovec;
        msg.msg_iovlen = 1;

        while (run)
        {
            int ret = recvmsg(socket_fd, &msg, MSG_DONTWAIT);

            if (ret != sizeof(client_arg))
            {
                if (errno != EAGAIN && errno != EWOULDBLOCK)
                {
                    printf("Error while accessing socket: %s\n", strerror(errno));
                    exit(1);
                }

                printf("No further client_args in socket.\n");
            }
            else
            {
                printf("received client_arg=%d\n", client_arg);
            }

            /* do daemon stuff */
            sleep(1);
        }

        printf("Dropped out of daemon loop. Shutting down.\n");

        cleanup();

        return EXIT_FAILURE;
    }

    case 1:
    {
        /* Client */

        if (argc < 2)
        {
            printf("Usage: %s <int>\n", argv[0]);
            return EXIT_FAILURE;
        }

        struct iovec iovec;

        struct msghdr msg = {0};
        int client_arg = atoi(argv[1]);
        iovec.iov_base = &client_arg;
        iovec.iov_len = sizeof(client_arg);
        msg.msg_iov = &iovec;
        msg.msg_iovlen = 1;

        int ret = sendmsg(socket_fd, &msg, 0);

        if (ret != sizeof(client_arg))
        {
            if (ret < 0)
                printf("Could not send device address to daemon: '%s'!\n", strerror(errno));
            else
                printf("Could not send device address to daemon completely!\n");

            cleanup();

            return EXIT_FAILURE;
        }

        printf("Sent client_arg (%d) to daemon.\n", client_arg);
        break;
    }

    default:
        cleanup();
        return EXIT_FAILURE;
    }

    cleanup();

    return EXIT_SUCCESS;
}


