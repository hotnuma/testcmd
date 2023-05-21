#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;

    int timeout = 0;

    int n = 1;
    while (n < argc)
    {
        const char *part = argv[n];

        timeout = atoi(part);

        n++;
    }

    if (timeout < 1)
        return 1;

    timeout *= 60;

    printf("suspend after %d seconds...\n", timeout);

    sleep(timeout);

    printf("suspend\n");

    int ret = system("systemctl suspend");

    return ret;
}


