#pragma once

# include <Siv3D.hpp>

class Client
{
private:
	TCPClient client;

	uint16 port;

	std::string receivedData;

public:
	Client();

	// サーバーに接続
	void connect();

	// サーバーから切断
	void disconnect();

	// サーバーに再接続
	void reconnect();

	// サーバーにデータを送信
	void send(String sendData);

	// サーバーからデータを受信
	void receive();
};