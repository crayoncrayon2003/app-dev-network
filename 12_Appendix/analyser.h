#ifndef ANALYSER_H
#define ANALYSER_H

#include <stdio.h>
#include <pcap.h>

extern void analyser(unsigned char *args, const struct pcap_pkthdr *header, const unsigned char *packet);

#endif
