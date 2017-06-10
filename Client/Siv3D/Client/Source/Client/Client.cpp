# include "Client.h"

Client::Client()
{
	// ポート番号指定
	this->port = 8000;
}

/*
	サーバーに接続
*/
void Client::connect()
{
	// ホスト名指定
	client.connect(IPv4::localhost(), port);
	//client.connect(IPv4(0, 0, 0, 0), port);
}

/*
	サーバーから切断
*/
void Client::disconnect()
{
	client.disconnect();
}

/*
	サーバーに再接続
*/
void Client::reconnect()
{
	if (client.hasError())
	{
		client.disconnect();

		client.connect(IPv4::localhost(), port);
	}
}

/*
	サーバーにデータの送信
*/
void Client::send(String sendData)
{
	if (client.isConnected())
	{
		const auto str = ToUTF8(sendData);
		client.send(str.data(), sizeof(char) * str.length());
	}
};

/*
	サーバーからデータを受信
*/
void Client::receive()
{
	for (;;)
	{
		char c;

		if (!client.read(c))
		{
			Println(L"Receive: ", FromUTF8(receivedData));
			receivedData.clear();

			WaitKey();

			break;
		}

		receivedData.push_back(c);
	}
}