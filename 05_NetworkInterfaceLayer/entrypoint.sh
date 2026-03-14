#!/bin/bash
if [ -n "$MAC_ADDRESS" ]; then
  ip link set eth0 down
  ip link set eth0 address "$MAC_ADDRESS"
  ip link set eth0 up
fi
exec "$@"