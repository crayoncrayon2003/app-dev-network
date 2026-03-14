
#include "l2_ether.h"
#include "l3_ip.h"
#include "l3_arp.h"

static char *mac_ntoa(unsigned char *d){
    static char str[18];
    sprintf(str,"%02x:%02x:%02x:%02x:%02x:%02x",d[0],d[1],d[2],d[3],d[4],d[5]);
    fflush(stdout);
    return str;
}

static void printEther(struct ether_header *eth){
    printf("     MAC : %17s \t=> %17s \n",mac_ntoa(eth->ether_dhost), mac_ntoa(eth->ether_shost));
    fflush(stdout);
}

int analyserEther(const unsigned char *frame){
    struct ether_header *eth_header;
    unsigned char *eth_payload;

    /* get ether header */
    eth_header = (struct ether_header *)frame;

    /* print ether header */
    printEther(eth_header);

    /* get ether payload */
    eth_payload = ((unsigned char *)frame + sizeof(struct ether_header));

    /* determine UpperProtocol */
    switch(ntohs(eth_header->ether_type)){
        case ETH_P_IP:
            analyserIp(eth_payload);
            break;
        case ETH_P_IPV6:
            printf("\nEther Type IPv6 analyse stop \n");
            break;
        case ETH_P_ARP:
            analyserArp(eth_payload);
            break;
        default:
            printf("\nEther Type unknown analyse stop\n");
    }

}