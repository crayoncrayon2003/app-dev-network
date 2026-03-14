#ifndef FILENAME
#define FILENAME

#include <stdio.h>
#include <pcap.h>
#include "analyser.h"
#include "setting.h"

static void callback(const unsigned char *args, const struct pcap_pkthdr *header, const unsigned char *packet);

#endif
