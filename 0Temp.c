#if 0

typedef struct DataStats {
    unsigned long rx_packets;
    unsigned long rx_errors;
    int rx_over;
    unsigned long tx_packets;
    unsigned long tx_errors;
    int tx_over;
    double rx_bytes;
    double tx_bytes;
    double rx_bytes_comp;
    double tx_bytes_comp;
    double rx_packets_led;
    double tx_packets_led;
    unsigned long connect_time;
    unsigned long current_time;
    float top_speed;
    int online_days;
    int online_hour;
    int online_min;
    int online_sec;
    unsigned long rx_packets_off;
    unsigned long rx_errors_off;
    int rx_over_off;
    unsigned long tx_packets_off;
    unsigned long tx_errors_off;
    int tx_over_off;
    double rx_bytes_off;
    double tx_bytes_off;
    double rx_bytes_comp_off;
    double tx_bytes_comp_off;
} DataStats;

    /* Print Destination address */
    printf("%s\t", rtInfo->dstAddr ? ntoa(rtInfo->dstAddr) : "0.0.0.0  ");

    /* Print Gateway address */
    printf("%s\t", rtInfo->gateWay ? ntoa(rtInfo->gateWay) : "*.*.*.*");

    /* Print Interface Name */
    printf("%s\t", rtInfo->ifName);

    /* Print Source address */
    printf("%s\n", rtInfo->srcAddr ? ntoa(rtInfo->srcAddr) : "*.*.*.*");

    if (0 == rtInfo->dstAddr)
    {

        printf("ifname = %s\t", rtInfo->ifName);
        printf("\t\t\t^^^^^ here it is!\n");
    }

char* ntoa(int addr)
{
    static char buffer[18];

    sprintf(buffer, "%d.%d.%d.%d",
            (addr & 0x000000FF),
            (addr & 0x0000FF00) >>  8,
            (addr & 0x00FF0000) >> 16,
            (addr & 0xFF000000) >> 24);

    return buffer;
}

#endif


