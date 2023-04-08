#include "Server.h"
#include "CServerSocket.h"
#include "ServerThread.h"
#include <iostream>

Server::Server(int port, EasyBuy* eb)
{
	this->ss = new CServerSocket(port);
	this->eb = eb;
	this->runServer();

}

void Server::runServer()
{
	while (true) {
		cout << "Client wird gesucht..." << endl;
		CSocket* clientSocket = ss->accept();
		ServerThread* st = new ServerThread(clientSocket, eb);
		cout << "Client verbunden" << endl;
		st->start();
	}
}
