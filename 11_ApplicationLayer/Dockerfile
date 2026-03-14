FROM ubuntu:22.04

# インストール中の対話プロンプトを無効化
ENV DEBIAN_FRONTEND=noninteractive

# ネットワーク管理・診断ツールのインストール
RUN apt-get update && \
    apt-get install -y \
        iproute2 \
        iputils-ping \
        tcpdump \
        net-tools \
        iptables \
        netcat-openbsd \
        curl \
        python3 \
        python3-scapy \
    && apt-get clean

# スクリプトのコピーと権限設定
COPY entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

# エントリポイントの設定
ENTRYPOINT ["/entrypoint.sh"]

# コンテナを維持するためのデフォルトコマンド
CMD ["sleep", "infinity"]

