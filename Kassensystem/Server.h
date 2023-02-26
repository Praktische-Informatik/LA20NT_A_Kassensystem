#pragma once
class CServerSocket;
class EasyBuy;

class Server {
private:
	CServerSocket* ss;
	EasyBuy* eb;
public:
	Server(int, EasyBuy*);
	void runServer();
};
