#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <inttypes.h>

// https://man7.org/linux/man-pages/man3/strptime.3.html

int main()
{
    struct tm tm = {0};
    if (strptime("2023/06/12", "%Y/%m/%d", &tm) == NULL)
        return EXIT_FAILURE;

    tm.tm_isdst = -1;

    char buf[255];

    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &tm);
    printf("date = %s\n", buf);

    tm.tm_sec += 86400 - 1;
    mktime(&tm);

    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &tm);
    printf("date = %s\n", buf);

    return EXIT_SUCCESS;
}


