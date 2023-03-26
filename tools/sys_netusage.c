#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#define PATH_NET_DEV "/proc/net/dev"
#define BUFSIZE 256

typedef struct _netdata netdata;

struct _netdata
{
    double rx_bytes;
    double rx_bytes_diff;

    double tx_bytes;

    unsigned long rx_packets;
    unsigned long rx_errors;
    int rx_over;
    unsigned long tx_packets;
    unsigned long tx_errors;
    int tx_over;
};

bool get_stat(netdata* data, const char *if_name)
{
    /* bwalle: Instead of the original code we open the file each time new. The
     * performance difference is _very_ minimal. But I don't think that it's a good
     * idea to keep the file open for a very long time for _each_ plugin instance.
     */
    FILE *fp = fopen(PATH_NET_DEV, "r");

    if (!fp)
    {
        fprintf(stderr, "cannot open %s!\nnot running Linux?\n",
            PATH_NET_DEV);

        return false;
    }

    /* backup old rx/tx values */
    unsigned long rx_o = data->rx_bytes;
    unsigned long tx_o = data->tx_bytes;

    fseek(fp, 0, SEEK_SET);

    char buffer[BUFSIZE];
    char *ptr;

    // skip the first two lines
    for (int i = 0; i < 2; ++i)
    {
        ptr = fgets(buffer, BUFSIZE-1, fp);
        (void) ptr;
    }

    int interfacefound = 0;
    char *devname;
    int dump;

    while (fgets(buffer, BUFSIZE-1, fp) != NULL)
    {
        /* find the device name and substitute ':' with '\0' */
        ptr = buffer;

        while (*ptr == ' ')
            ptr++;

        devname = ptr;

        while (*ptr != ':')
            ptr++;

        *ptr = '\0';

        ptr++;

        if (!strcmp(devname, (char*) if_name))
        {
            /* read stats and fill struct */
            sscanf(ptr, "%lg %lu %lu %d %d %d %d %d %lg %lu %lu %d %d %d %d %d",
                &(data->rx_bytes), &(data->rx_packets), &(data->rx_errors),
                &dump, &dump, &dump, &dump, &dump,
                &(data->tx_bytes), &(data->tx_packets), &(data->tx_errors),
                &dump, &dump, &dump, &dump, &dump);

            data->rx_bytes_diff = data->rx_bytes - rx_o;

            interfacefound = 1;

            continue;
        }
    }

    fclose(fp);

    if (interfacefound)
    {
        if (rx_o > data->rx_bytes)
            data->rx_over++;

        if (tx_o > data->tx_bytes)
            data->tx_over++;
    }

    return (interfacefound == 1) ? 0 : 1;
}

int main()
{
    netdata data = {0};
    get_stat(&data, "enp27s0");

    while (1)
    {
        sleep(10);

        get_stat(&data, "enp27s0");

        //printf("rx_bytes : %f\n", data.rx_bytes);

        printf("rx_bytes : %f\n", data.rx_bytes_diff);
        fflush(stdout);

    }

    return 0;
}


