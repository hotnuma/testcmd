#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct _timediff timediff;

struct _timediff
{
    struct timeval start;
};

void td_start(timediff *td)
{
    gettimeofday(&td->start, NULL);
}

void td_printms(timediff *td)
{
    struct timeval end;
    gettimeofday(&end, NULL);

    double elapsed = (end.tv_sec - td->start.tv_sec)
                     + ((end.tv_usec - td->start.tv_usec) / 1e6);

    printf("elapsed : %f\n", elapsed);

    td->start = end;
}

int main()
{
    timediff td;
    td_start(&td);
    usleep(500);
    td_printms(&td);

    return 0;
}


