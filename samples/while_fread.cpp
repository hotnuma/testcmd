#include <CString.h>
#include <CFile.h>
#include <stdio.h>
#include <print.h>

int main(int argc, char **argv)
{
    size_t bsize = 4096;

    CString buffer(bsize + 1);
    int size = 0;

    FILE *file = fopen("/var/log/syslog", "rb");
    if (!file)
        return -1;

    char *p = buffer.data();

    while (1)
    {
        size_t nb = fread(p, 1, bsize, file);
        size += nb;

        if (nb < bsize)
            break;

        buffer.resize(size + bsize + 1);
        p = buffer.data() + size;

    }

    //buffer.resize(size + 1);
    buffer.terminate(size);

    fclose(file);

    print(buffer);

    return 0;
}


