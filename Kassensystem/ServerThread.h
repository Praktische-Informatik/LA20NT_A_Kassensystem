#pragma once
#include "EasyBuy.h"
#include "CSocket.h"
#include "Thread.h"
class EasyBuy;
class CSocket;
class Kunde;
class Thread;

class ServerThread : public CThread
{
private:
	EasyBuy* eb;
	CSocket* clientSocket;
public:
	ServerThread(CSocket*, EasyBuy*);
	void run();
};

