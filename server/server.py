import socket
import threading
import json


HOST = "localhost"
PORT = 8000
MAX_CLIENTS_NUM = 5
clients = []


def remove_connection(con, address):
    print(f'Disconnect!{address}')
    con.close()
    clients.remove((con, address))


def server_start():
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    # サーバーpcが持っている全てのアドレスで接続できる
    sock.bind(('', PORT))
    sock.listen(MAX_CLIENTS_NUM)

    while True:
        con, address = sock.accept()
        print(f'Connect!{address}')
        clients.append((con, address))
        handle_thread = threading.Thread(target=handler, args=(con, address), daemon=True)
        handle_thread.start()


def handler(con, address):
    f = open("../data/test.json", "r")
    data_dict = json.load(f)
    msg = json.dumps(data_dict)

    # jsonデータを全クライアントに送信
    try:
        for c in clients:
            c[0].sendto(msg.encode('utf-8'), c[1])
            print(f'send to {c[1]}')
    except ConnectionResetError:
        remove_connection(con, address)
    """
    # 受信したメッセージを全クライアントに送信する
    while True:
        try:
            data = con.recv(4096)
            for c in clients:
                c[0].sendto(data, c[1])
        except ConnectionResetError:
            remove_connection(con, address)
            break
        else:
            if data:
                print(f'Received{address} - {data.decode("utf-8")}')
    """

if __name__ == '__main__':
    server_start()
