
#define PCAP_NOLIMIT_LOOP  -1

#include "17_NetworkWatch.h"

int main(int argc, char **argv) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    handle = pcap_open_live(SETTING_NIC, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
      fprintf(stderr, "error: pcap_open_live %s: %s\n", SETTING_NIC, errbuf);
      return -1;
    }

    if( pcap_loop( handle, PCAP_NOLIMIT_LOOP, analyser,  NULL) < 0 ){
      fprintf(stderr, "error: pcap_loop %s: %s\n", SETTING_NIC, errbuf);
    }

    pcap_close(handle);

    return 0;
}