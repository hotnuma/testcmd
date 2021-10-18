#include <stdio.h>
#include <string.h>

#include <print.h>

#define BUFFSIZE 1024

int main()
{
    char buffer[BUFFSIZE];

    FILE *fp = fopen("/home/hotnuma/ps_aux.txt", "rb");

    while (fgets(buffer, BUFFSIZE - 1, fp))
    {
        int len = strlen(buffer);
        if (len < 1)
            continue;

        if (buffer[len - 1] == '\n')
        {
            buffer[len - 1] = '\0';
        }

        printf("line = %s\n", buffer);
    }

    fclose(fp);

    return 0;
}


