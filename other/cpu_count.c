#include <stdio.h>
#include <unistd.h>

int main()
{
    long numofcpus = sysconf(_SC_NPROCESSORS_ONLN);

    printf("%ld\n", numofcpus);

    return 0;
}
