FROM ubuntu:22.04

RUN apt-get update && \
    apt-get install -y \
        iproute2 \
        iputils-ping \
        tcpdump \
        python3 \
        python3-scapy \
    && apt-get clean

COPY entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

ENTRYPOINT ["/entrypoint.sh"]
CMD ["sleep", "infinity"]