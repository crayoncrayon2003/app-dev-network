#ifndef ICMP_H
#define ICMP_H

#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>

static void printIcmp(struct icmp *icmp);
extern int analyserIcmp(const unsigned char *frame);

#endif