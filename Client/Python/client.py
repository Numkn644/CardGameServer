# -*- coding:utf-8 -*-
import socket
import json

# ホスト名
# host = socket.gethostname()
host = 'localhost'
# ポート番号
port = 8000

# ソケットを作成
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s :
    # サーバーに接続
    s.connect((host, port))

    # データの送信
    # s.sendall(b'Hello, world!')

    # データの受信
    bytesData = s.recv(4096)

    print(repr(bytesData))

    # データを文字列に変換
    stringData = bytesData.decode("utf-8")

    # 文字列を辞書型に変換
    jsonData = json.loads(stringData)

    print('Received : {}'.format(type(jsonData)))