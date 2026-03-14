#ifndef ETHER_H
#define ETHER_H

#include <stdio.h>
#include <netinet/in.h>
#include <net/ethernet.h>

static char *mac_ntoa(unsigned char *d);
static void printEther(struct ether_header *eth);
extern int analyserEther(const unsigned char *frame);

#endif