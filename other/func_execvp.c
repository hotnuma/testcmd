#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

static bool prep_child_for_exec(bool close_stdin /*, const struct saved_cwd *wd*/)
{
    bool ok = true;

    if (close_stdin)
    {
        //const char inputfile[] = "/dev/null";

        if (close(0) < 0)
        {
            //error(0, errno, _("Cannot close standard input"));

            ok = false;
        }
        else
        {
            if (open("/dev/null", O_RDONLY
#if defined O_LARGEFILE
                                  | O_LARGEFILE
#endif
                ) < 0)
            {
                /* This is not entirely fatal, since
                 * executing the child with a closed
                 * stdin is almost as good as executing it
                 * with its stdin attached to /dev/null. */

                //error(0, errno, "%s", safely_quote_err_filename(0, inputfile));

                /* do not set ok=false, it is OK to continue anyway. */
            }
        }
    }

    /* Even if DebugSearch is set, don't announce our change of
     * directory, since we're not going to emit a subsequent
     * announcement of a call to stat() anyway, as we're about to exec
     * something. */

#if 0
    if (0 != restore_cwd(wd))
    {
        //error(0, errno, _("Failed to change directory%s%s"),
        //      (wd->desc < 0 && wd->name) ? ": " : "",
        //      (wd->desc < 0 && wd->name) ? wd->name : "");

        ok = false;
    }
#endif

    return ok;
}

bool launch(DirParser *parser, int argc, char **argv)
{
    (void) argc;

    // make sure output of command doesn't get mixed with global output.
    fflush(stdout);
    fflush(stderr);

    // make sure to listen for the kids.
    static bool first_time = true;

    if (first_time)
    {
        first_time = false;
        signal(SIGCHLD, SIG_DFL);
    }

    pid_t child_pid = fork();

    if (child_pid == -1)
        return false;

    if (child_pid == 0)
    {
        // we are the child

        //assert(NULL != execp->wd_for_exec);

        //if (!prep_child_for_exec(execp->close_stdin, execp->wd_for_exec))
        //{
        //    _exit(1);
        //}

        execvp(argv[0], argv);

        _exit(1);
    }

    while (waitpid(child_pid, &(parser->last_child_status), 0) == (pid_t)-1)
    {
        if (errno != EINTR)
        {
            return false; // fail
        }
    }

    return true;
}


