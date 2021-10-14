#include <CString.h>
#include <CFile.h>
#include <stdio.h>

#include <print.h>

int main()
{
    size_t bsize = 4096;

    CString buffer(bsize + 1);
    int size = 0;

    FILE *fp = fopen("/var/log/syslog", "rb");
    if (!fp)
        return -1;

    char *p = buffer.data();

    while (1)
    {
        size_t nb = fread(p, 1, bsize, fp);
        size += nb;

        if (nb < bsize)
            break;

        buffer.resize(size + bsize + 1);
        p = buffer.data() + size;

    }

    //buffer.resize(size + 1);
    buffer.terminate(size);

    fclose(fp);

    print(buffer);

    return 0;
}


