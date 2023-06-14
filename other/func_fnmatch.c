#include <stdlib.h>
#include <stdio.h>
#include <fnmatch.h>

int main()
{
    const char *filepath = "/temp/dir.c/filename.txt";

    if (fnmatch("*.c", filepath, 0) != FNM_NOMATCH)
        printf("match\n");
    else
        printf("no match\n");

    return EXIT_SUCCESS;
}


