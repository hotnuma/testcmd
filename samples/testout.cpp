#include <stdio.h>
#include <unistd.h>

int main()
{
    int count = 10;

    while (count)
    {
        --count;

        fprintf(stdout, "stdout : %d\n", count);
        fflush(stdout);

        fprintf(stderr, "stderr : %d\n", count);
        fflush(stderr);

        sleep(1);
    }
    
    return 0;
}


