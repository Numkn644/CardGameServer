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

	// �T�[�o�[�ɐڑ�
	void connect();

	// �T�[�o�[����ؒf
	void disconnect();

	// �T�[�o�[�ɍĐڑ�
	void reconnect();

	// �T�[�o�[�Ƀf�[�^�𑗐M
	void send(String sendData);

	// �T�[�o�[����f�[�^����M
	void receive();
};