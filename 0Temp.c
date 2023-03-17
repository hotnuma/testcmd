#if 0

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


