# include <Siv3D.hpp>
# include "Client/Client.h"

void Main()
{
	Client client;
	client.connect();

	while (System::Update())
	{
		client.receive();

		client.reconnect();

		if (Input::KeyEscape.clicked)
		{
			System::Exit();
		}
	}
}