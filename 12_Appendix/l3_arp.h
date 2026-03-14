#ifndef ARP_H
#define ARP_H

#include <stdio.h>
#include <net/if_arp.h>
#include <netinet/in.h>
#include <net/ethernet.h>

static void printArp(struct arphdr *ip);
static void printArpPayload(unsigned char *arp_payload);
extern int analyserArp(const unsigned char *frame);

#endif