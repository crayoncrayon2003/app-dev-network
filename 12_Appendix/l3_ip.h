#ifndef IP_H
#define IP_H

#include <stdio.h>
#include <netinet/ip.h>

#define IP_ICMP 0x01
#define IP_TCP  0x06
#define IP_UDP  0x17


static char *ip_ntoa(u_int32_t ip);
static void printIp(struct iphdr *ip);
extern int analyserIp(const unsigned char *frame);

#endif