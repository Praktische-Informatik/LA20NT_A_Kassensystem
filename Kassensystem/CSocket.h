#pragma comment(lib,"ws2_32.lib")
#include "Winsock.h"
#include <string>

class CSocket
{
private:

  std::string	host;
  int			port;
  SOCKET		socket;

public:

				CSocket			(std::string host, int port);
				CSocket			(SOCKET socket);  // wird zur Socketerzeugung beim CServerSocket benoetigt
  bool			connect			(void);
  int			dataAvailable	(void);
  void			write			(int b);
  void			write			(char* b, int len);
  void			write			(std::string s);
  int			read			(void);
  int			read			(char* b, int len);
  std::string	readLine		(void);
  void			close			(void);
};