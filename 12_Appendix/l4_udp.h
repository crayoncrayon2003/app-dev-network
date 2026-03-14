#ifndef UDP_H
#define UDP_H

#include <stdio.h>
#include <netinet/in.h>
#include <netinet/udp.h>

static void printUdp(struct udphdr *udp);
extern int analyserUdp(const unsigned char *frame);

#endif