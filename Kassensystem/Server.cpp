#include "Server.h"
#include "CServerSocket.h"
#include "ServerThread.h"
#include <iostream>

Server::Server(int port, EasyBuy* eb)
{
	//CServerSocket* serverS = new CServerSocket(port);
	this->ss = new CServerSocket(port);
	this->eb = eb;

}

void Server::runServer()
{
	while (true) {
		cout << "Client wird gesucht..." << endl;
		ServerThread* st = new ServerThread(ss->accept(), eb);
		cout << "Client verbunden" << endl;
		st->run();
	}
}
