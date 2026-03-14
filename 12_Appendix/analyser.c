
#include "l2_ether.h"

void analyser(unsigned char *args, const struct pcap_pkthdr *header, const unsigned char *frame){
    int ret = 0;
    printf(" ----------- Analyse Start -----------\n");
    fflush(stdout);

    ret = analyserEther(frame);

    printf(" ----------- Analyse End   -----------\n");
    printf("\n\n");
    fflush(stdout);
}
