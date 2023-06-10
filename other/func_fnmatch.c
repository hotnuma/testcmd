#include <stdlib.h>
#include <stdio.h>
#include <fnmatch.h>

int main()
{
    const char *filepath = "/dir.c/filename.txt";

    if (fnmatch("*.c", filepath, 0) != FNM_NOMATCH)
        printf("matches\n");

    return EXIT_SUCCESS;
}


