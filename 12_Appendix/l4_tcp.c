#include "l4_tcp.h"

static void printTcp(struct tcphdr *ptr){
	printf(" TCP PORT: %u    \t\t=> %u \n",ntohs(ptr->source),ntohs(ptr->dest));
    fflush(stdout);
}

int analyserTcp(const unsigned char *frame){
    struct tcphdr *tcp_header;
    unsigned char *tcp_payload;

    /* get tcp header */
    tcp_header = (struct tcphdr *)frame;

    /* print tcp header */
    printTcp(tcp_header);

    /* get tcp payload */
    tcp_payload = ((unsigned char *)frame + sizeof(struct tcphdr));

    /* determine UpperProtocol  etc... */
}