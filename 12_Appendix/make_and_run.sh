rm -f NetworkWatch

gcc analyser.c l2_ether.c l3_ip.c l3_arp.c l4_icmp.c l4_tcp.c l4_udp.c NetworkWatch.c -o NetworkWatch -lpcap
sudo ./NetworkWatch