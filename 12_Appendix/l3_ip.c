#include "l3_ip.h"
#include "l4_tcp.h"
#include "l4_udp.h"
#include "l4_icmp.h"

static char *ip_ntoa(u_int32_t ip){
	unsigned char *d = (unsigned char *)&ip;
	static char str[15];
	sprintf(str,"%d.%d.%d.%d",d[0],d[1],d[2],d[3]);
    fflush(stdout);
	return str;
}

static void printIp(struct iphdr *ip){
    printf("     IP  : %s \t=> %s\n",ip_ntoa(ip->saddr), ip_ntoa(ip->daddr));
    fflush(stdout);
}

int analyserIp(const unsigned char *frame){
    struct iphdr *ip_header;
    unsigned char *ip_payload;

    /* get ip header */
    ip_header = (struct iphdr *)frame;

    /* print ip header */
    printIp(ip_header);

    /* get ip payload */
    ip_payload = ((unsigned char *)frame + sizeof(struct iphdr));

    /* determine UpperProtocol */
    switch(ip_header->protocol){
        case IP_ICMP:
            analyserIcmp(ip_payload);
            break;
        case IP_TCP:
            analyserTcp(ip_payload);
            break;
        case IP_UDP:
            analyserUdp(ip_payload);
            break;
        default:
            printf("\nIP protocol unknown analyse stop\n");
    }
}