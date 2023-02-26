#pragma once
#include "Winsock.h"
class CSocket;
using namespace std;


class CServerSocket
{
private:
  int			port;
  SOCKET		serverSocket;

public:
				CServerSocket	(int port);
				CSocket* accept	(void);
  void			close			(void);
};
