#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 80

int main()
{
    const char *filepath = "/proc/meminfo";

    FILE *fp = fopen(filepath, "r");

    if (!fp)
    {
        printf("Cannot open file %s\n", filepath);
        return EXIT_FAILURE;
    }

    char buffer[MAX_LENGTH];

    while (fgets(buffer, MAX_LENGTH, fp))
    {
        printf("buffer = %s", buffer);
    }

    fclose(fp);

    return EXIT_SUCCESS;
}


