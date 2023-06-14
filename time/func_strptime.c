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

    time_t epoch = mktime(&tm);

    printf("Unix  time : %" PRIu64 "\n", epoch);

    char buf[255];
    strftime(buf, sizeof(buf), "%Y-%m-%d", &tm);

    printf("date = %s\n", buf);

    return EXIT_SUCCESS;
}


