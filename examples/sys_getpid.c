#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    printf("ppid id : %d\n", getppid());
    printf("pid  id : %d\n", getpid());
    printf("thid id : %d\n", gettid());

    return EXIT_SUCCESS;
}


