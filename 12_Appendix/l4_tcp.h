#ifndef TCP_H
#define TCP_H

#include <stdio.h>
#include <netinet/in.h>
#include <netinet/tcp.h>

static void printTcp(struct tcphdr *tcp);
extern int analyserTcp(const unsigned char *frame);

#endif