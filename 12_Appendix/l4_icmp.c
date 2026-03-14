#include "l4_icmp.h"

static void printIcmp(struct icmp *icmp){
    printf("Message Type   : 0x%02x\n", icmp->icmp_type);
    printf("Type sub-code  : 0x%02x\n", icmp->icmp_code);
    printf("Checksum       : 0x%04x\n", htons(icmp->icmp_cksum));

    fflush(stdout);
}

int analyserIcmp(const unsigned char *frame){
    struct icmp *icmp_header;
    unsigned char *icmp_payload;

    /* get icmp header */
    icmp_header = (struct icmp *)frame;

    /* print icmp header */
    printIcmp(icmp_header);

    /* get icmp payload */
    icmp_payload = ((unsigned char *)frame + sizeof(struct icmp));

    /* determine UpperProtocol  etc... */
    switch(icmp_header->icmp_type){
        case ICMP_ECHOREPLY:
            break;
        case ICMP_DEST_UNREACH:
            break;
        case ICMP_SOURCE_QUENCH:
            break;
        case ICMP_REDIRECT:
            break;
        case ICMP_ECHO:
            break;
        case ICMP_TIME_EXCEEDED:
            break;
        default:
            printf("\nIP protocol unknown analyse stop\n");
    }

}