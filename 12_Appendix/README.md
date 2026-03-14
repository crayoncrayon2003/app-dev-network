# パッケージのインストール

C言語のソースコードをビルドするために必要なモジュールをインストールします。

```bash
sudo apt install gcc
sudo apt install gcc
sudo apt install libpcap-dev
```

# 権限設定

1. pcap グループを作成

2. 現在のユーザーを pcap グループに追加

3. tcpdump実行ファイルの所有グループをrootからpcapに変更する

4. root と pcapグループ だけ tcpdump 実行可能な権限を設定

5. ネットワークキャプチャに必要な capability を付与する

```bash
sudo groupadd pcap
sudo usermod -a -G pcap $USER
sudo chgrp pcap /usr/sbin/tcpdump
sudo chmod 750 /usr/sbin/tcpdump
sudo setcap cap_net_raw,cap_net_admin=eip /usr/sbin/tcpdump
```

# コンフィグ

setting.h ファイルに、変数 SETTING_NIC がある。これは監視対象のNICを指定する。例えば、eth0

# ビルドと実行

make_and_run.sh にコンパイル、ビルド、実行の一連のコマンドを実行するバッチファイルを実行する

```bash
./make_and_run.sh
```