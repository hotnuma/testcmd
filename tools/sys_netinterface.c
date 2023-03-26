#include <asm/types.h>
#include <netinet/ether.h>
#include <netinet/in.h>
#include <net/if.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/netlink.h>
#include <linux/rtnetlink.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 8192

// https://stackoverflow.com/questions/15668653/

typedef struct _route_info route_info;
void printRoute(route_info *rtInfo);

struct _route_info
{
    u_int dstAddr;
    u_int srcAddr;
    u_int gateWay;
    char ifName[IF_NAMESIZE];
};

int readNlSock(int sockFd, char *bufPtr, int seqNum, int pId)
{
    struct nlmsghdr *nlHdr;
    int msgLen = 0;

    do
    {
        /* Receive response from the kernel */
        int readLen = recv(sockFd, bufPtr, BUFSIZE - msgLen, 0);
        if (readLen < 0)
        {
            perror("SOCK READ: ");
            return -1;
        }

        nlHdr = (struct nlmsghdr*) bufPtr;

        /* Check if the header is valid */
        if ((NLMSG_OK(nlHdr, (unsigned int) readLen) == 0)
            || (NLMSG_ERROR == nlHdr->nlmsg_type))
        {
            perror("Error in received packet");
            return -1;
        }

        /* Check if it is the last message */
        if (NLMSG_DONE == nlHdr->nlmsg_type)
        {
            break;
        }

        /* Else move the pointer to buffer appropriately */
        bufPtr += readLen;
        msgLen += readLen;

        /* Check if its a multi part message; return if it is not. */
        if ((nlHdr->nlmsg_flags & NLM_F_MULTI) == 0)
        {
            break;
        }
    }
    while((nlHdr->nlmsg_seq != (unsigned int) seqNum)
          || (nlHdr->nlmsg_pid != (unsigned int) pId));

    return msgLen;
}

/* For parsing the route info returned */
void parseRoutes(struct nlmsghdr *nlHdr, route_info *rtInfo)
{
    struct rtmsg *rtMsg = (struct rtmsg*) NLMSG_DATA(nlHdr);

    /* If the route is not for AF_INET or does not belong to main routing table
    then return. */
    if ((rtMsg->rtm_family != AF_INET) || (rtMsg->rtm_table != RT_TABLE_MAIN))
        return;

    /* get the rtattr field */
    struct rtattr *rtAttr = (struct rtattr*) RTM_RTA(rtMsg);
    int rtLen = RTM_PAYLOAD(nlHdr);

    for (; RTA_OK(rtAttr, rtLen); rtAttr = RTA_NEXT(rtAttr, rtLen))
    {
        switch (rtAttr->rta_type)
        {
        case RTA_OIF:
            if_indextoname(*(int*) RTA_DATA(rtAttr), rtInfo->ifName);
            break;

        case RTA_GATEWAY:
            rtInfo->gateWay = *(u_int*) RTA_DATA(rtAttr);
            break;

        case RTA_PREFSRC:
            rtInfo->srcAddr = *(u_int*) RTA_DATA(rtAttr);
            break;

        case RTA_DST:
            rtInfo->dstAddr = *(u_int*) RTA_DATA(rtAttr);
            break;
        }
    }

    printRoute(rtInfo);
}

/* For printing the routes. */
void printRoute(route_info *rtInfo)
{
    if (rtInfo->dstAddr == 0)
    {
        printf("%s\n", rtInfo->ifName);
    }

}

int main()
{
    /* Create Socket */
    int sock = socket(PF_NETLINK, SOCK_DGRAM, NETLINK_ROUTE);

    if (sock < 0)
        perror("Socket Creation: ");

    /* Initialize the buffer */
    char msgBuf[BUFSIZE];
    memset(msgBuf, 0, BUFSIZE);

    /* point the header and the msg structure pointers into the buffer */
    struct nlmsghdr *nlMsg = (struct nlmsghdr*) msgBuf;

    /* Fill in the nlmsg header*/
    nlMsg->nlmsg_len = NLMSG_LENGTH(sizeof(struct rtmsg)); // Length of message.
    nlMsg->nlmsg_type = RTM_GETROUTE; // Get the routes from kernel routing table .

    nlMsg->nlmsg_flags = NLM_F_DUMP | NLM_F_REQUEST; // The message is a request for dump.

    int msgSeq = 0;
    nlMsg->nlmsg_seq = msgSeq++; // Sequence of the message packet.

    int pid = getpid();
    nlMsg->nlmsg_pid = pid; // PID of process sending the request.

    /* Send the request */
    if (send(sock, nlMsg, nlMsg->nlmsg_len, 0) < 0)
    {
        printf("Write To Socket Failed...\n");
        return -1;
    }

    /* Read the response */
    int len = readNlSock(sock, msgBuf, msgSeq, pid);

    if (len < 0)
    {
        printf("Read From Socket Failed...\n");
        return -1;
    }

    /* Parse and print the response */
    route_info *rtInfo = (route_info*) malloc(sizeof(route_info));

    for (; NLMSG_OK(nlMsg, (unsigned int) len); nlMsg = NLMSG_NEXT(nlMsg, len))
    {
        memset(rtInfo, 0, sizeof(route_info));
        parseRoutes(nlMsg, rtInfo);
    }

    free(rtInfo);
    close(sock);

    return 0;
}


