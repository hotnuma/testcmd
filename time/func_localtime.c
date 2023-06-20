#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <inttypes.h>

// https://man7.org/linux/man-pages/man3/strptime.3.html

void printtm(struct tm *tm)
{
    //printf("tm_gmtoff :  %ld\n", tm->tm_gmtoff);

    printf("tm_isdst  :  %d\n", tm->tm_isdst);
    printf("tm_yday   :  %d\n", tm->tm_yday);
    printf("tm_wday   :  %d\n", tm->tm_wday);
    printf("tm_year   :  %d\n", tm->tm_year);
    printf("tm_mon    :  %d\n", tm->tm_mon);
    printf("tm_mday   :  %d\n", tm->tm_mday);
    printf("tm_hour   :  %d\n", tm->tm_hour);
    printf("tm_min    :  %d\n", tm->tm_min);
    printf("tm_sec    :  %d\n", tm->tm_sec);
    printf("\n");
}

int main()
{
    char buf[255];

    time_t now = time(NULL);

    now -= 86400;
    struct tm *tm = localtime(&now);

    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", tm);
    printf("date = %s\n", buf);

    return EXIT_SUCCESS;
}


