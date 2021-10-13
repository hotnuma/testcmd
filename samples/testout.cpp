#include <stdio.h>
#include <unistd.h>

int main()
{
    int count = 10;

    while (count)
    {
        --count;

        fprintf(stdout, "%i stdout\n", count);
        fflush(stdout);
        
        //fprintf(stderr, "%i stderr\n", count);
        //fflush(stderr);

        sleep(1);
    }
}

