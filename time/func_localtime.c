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
    struct tm t1 = {0};
    if (strptime("2023/06/12", "%Y/%m/%d", &t1) == NULL)
        return EXIT_FAILURE;

    printtm(&t1);

    //time_t epoch = mktime(&tm);

    char buf[255];

    time_t now = time(NULL);
    struct tm *t2 = localtime(&now);

    printtm(t2);
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", t2);
    printf("date = %s\n", buf);

    t2->tm_sec += 86400;
    mktime(t2);

    printtm(t2);

    //printf("Unix  time : %" PRIu64 "\n", epoch);

    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", t2);
    printf("date = %s\n", buf);

    return EXIT_SUCCESS;
}


