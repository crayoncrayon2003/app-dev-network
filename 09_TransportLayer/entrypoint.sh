#!/bin/bash
set -e

echo "--- Network Configuration Starting ---"

# --- MACアドレスの設定 ---
if [ -n "$MAC_ADDRESS_ETH0" ]; then
    echo "Setting MAC address for eth0 to $MAC_ADDRESS_ETH0..."
    ip link set eth0 down
    ip link set eth0 address "$MAC_ADDRESS_ETH0"
    ip link set eth0 up
fi

if [ -n "$MAC_ADDRESS_ETH1" ]; then
    echo "Setting MAC address for eth1 to $MAC_ADDRESS_ETH1..."
    ip link set eth1 down
    ip link set eth1 address "$MAC_ADDRESS_ETH1"
    ip link set eth1 up
fi

# --- Node用: デフォルトゲートウェイの設定 ---
if [ -n "$DEFAULT_GW" ]; then
    echo "Setting default gateway to $DEFAULT_GW..."
    ip route del default 2>/dev/null || true
    ip route add default via "$DEFAULT_GW"
fi

# --- Router用: デフォルトゲートウェイの削除 ---
if [ "$REMOVE_DEFAULT_GW" = "true" ]; then
    echo "Removing Docker default bridge gateway..."
    ip route del default 2>/dev/null || true
fi

echo "--- Current Routing Table ---"
ip route
echo "------------------------------"

exec "$@"