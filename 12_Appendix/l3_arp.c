#include "l3_arp.h"

static char *mac_ntoa(unsigned char *d){
    static char str[18];
    sprintf(str,"%02x:%02x:%02x:%02x:%02x:%02x",d[0],d[1],d[2],d[3],d[4],d[5]);
    fflush(stdout);
    return str;
}
static char *ip_ntoa(unsigned char *d){
	static char str[15];
	sprintf(str,"%d.%d.%d.%d",d[0],d[1],d[2],d[3]);
    fflush(stdout);
	return str;
}
static void printArp(struct arphdr *arp){
    printf("HardwareType   : 0x%04x  0x0001 is ether\n",                        htons(arp->ar_hrd));
    printf("ProtocolType   : 0x%04x  0x0800 is ip\n",                           htons(arp->ar_pro));
    printf("HardwareLength : %d\n",                                             arp->ar_hln);
    printf("ProtocolLength : %d\n",                                             arp->ar_pln);
    printf("ARP opcode     : 0x%04x  0x0001 is request, 0x0002 is reply\n",     htons(arp->ar_op));
    fflush(stdout);
}

static void printArpPayload(unsigned char *arp_payload){
    unsigned char *sha, *tha;
    unsigned char *sip, *tip;

    sha = ((unsigned char*)((unsigned char *)arp_payload + 0                        ));
    tha = ((unsigned char*)((unsigned char *)sha         + sizeof(struct ether_addr)));
    sip = ((unsigned char*)((unsigned char *)tha         + sizeof(struct ether_addr)));
    tip = ((unsigned char*)((unsigned char *)sip         + sizeof(struct in_addr   )));

    printf("Sender MAC address: %s\n", mac_ntoa(sha));
    printf("Target MAC address: %s\n", mac_ntoa(tha));
    printf("Sender IP address : %s\n", ip_ntoa(sip));
    printf("Target ip address : %s\n", ip_ntoa(tip));
    fflush(stdout);
}

int analyserArp(const unsigned char *frame){
    struct arphdr *arp_header;
    unsigned char *arp_payload;

    /* get arp header */
    arp_header = (struct arphdr *)frame;

    /* print arp header */
    printArp(arp_header);

    if (ntohs(arp_header->ar_op) == ARPOP_REQUEST  || ntohs(arp_header->ar_op) == ARPOP_REPLY ||
        ntohs(arp_header->ar_op) == ARPOP_RREQUEST || ntohs(arp_header->ar_op) == ARPOP_RREPLY) {
        /* get arp payload */
        arp_payload = ((unsigned char *)arp_header + sizeof(struct arphdr));
        /* print arp payload */
        printArpPayload(arp_payload);
    }


}