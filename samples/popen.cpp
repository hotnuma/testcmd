#include <stdlib.h>
#include <stdio.h>

#include <print.h>

int main()
{
    FILE *fp = popen("ls -la", "r");

    if (!fp)
    {
        print("can't find program");

        exit(1);
    }

    int size = 1023;
    char readbuf[size + 1];

    while (fgets(readbuf, size, fp))
    {
        print("line = %s", readbuf);
    }

    pclose(fp);

    return 0;
}


