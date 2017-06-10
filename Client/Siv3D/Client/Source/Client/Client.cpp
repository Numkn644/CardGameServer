# include "Client.h"

Client::Client()
{
	// �|�[�g�ԍ��w��
	this->port = 8000;
}

/*
	�T�[�o�[�ɐڑ�
*/
void Client::connect()
{
	// �z�X�g���w��
	client.connect(IPv4::localhost(), port);
	//client.connect(IPv4(0, 0, 0, 0), port);
}

/*
	�T�[�o�[����ؒf
*/
void Client::disconnect()
{
	client.disconnect();
}

/*
	�T�[�o�[�ɍĐڑ�
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
	�T�[�o�[�Ƀf�[�^�̑��M
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
	�T�[�o�[����f�[�^����M
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