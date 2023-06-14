#define _XOPEN_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define STRSIZE 10

bool finddate(const char *part)
{
    if (!part || strlen(part) != STRSIZE)
        return false;

    char inbuff[STRSIZE+1];

    strcpy(inbuff, part);
    inbuff[STRSIZE-2] = '0';
    inbuff[STRSIZE-1] = '1';

    struct tm tm;
    memset(&tm, 0, sizeof(tm));

    strptime(inbuff, "%Y-%m-%d", &tm);

    tm.tm_mday -= 1;
    mktime(&tm);

    // Saturday
    if (tm.tm_wday == 6)
    {
        tm.tm_mday -= 1;
        mktime(&tm);
    }

    // Sunday
    else if (tm.tm_wday == 0)
    {
        tm.tm_mday -= 2;
        mktime(&tm);
    }

    char outbuff[STRSIZE+1];

    strftime(outbuff, STRSIZE+1, "%Y-%m-%d", &tm);
    printf("%s\t%s\n", part, outbuff);

    return true;
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return EXIT_FAILURE;

    int n = 1;

    printf("orig\t\tresult\n");

    while (n < argc)
    {
        finddate(argv[n]);

        ++n;
    }

    fflush(stdout);

    return EXIT_SUCCESS;
}


