#include "l4_udp.h"

static void printUdp(struct udphdr *ptr){
	printf(" UDP PORT: %u    \t\t=> %u \n",ntohs(ptr->source), ntohs(ptr->dest));
    fflush(stdout);
}

int analyserUdp(const unsigned char *frame){
    struct udphdr *udp_header;
    unsigned char *udp_payload;

    /* get udp header */
    udp_header = (struct udphdr *)frame;

    /* print udp header */
    printUdp(udp_header);

    /* get udp payload */
    udp_payload = ((unsigned char *)frame + sizeof(struct udphdr));

    /* determine UpperProtocol  etc... */
}