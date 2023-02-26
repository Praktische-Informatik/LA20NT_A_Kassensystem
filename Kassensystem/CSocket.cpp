#include "CSocket.h"

/* Socket() - erzeugt einen Socket */
CSocket::CSocket(std::string host, int port)
{
	this->port = port;
	this->host = host;
	// WinSock-DLL einbinden
	WSADATA m_wsa;
	WSAStartup(MAKEWORD(2, 0), &m_wsa);
	// CSocket erzeugen
	this->socket = ::socket(AF_INET, SOCK_STREAM, 0);
}

/* Socket(socket) - wird zur Socketerzeugung beim CServerSocket benoetigt*/
CSocket::CSocket(SOCKET socket)
{
	this->socket = socket;
}


/*
connect()
stellt eine Verbindet zu der bei der Socket-Erzeugung angegebenen IP- Adresse und
Port her; liefert 1, wenn die eine Verbindung hergestellt werden konnte.
*/
bool CSocket::connect()
{
	SOCKADDR_IN addr; //Struktur mit den Elementen 1) Adressfamilie (IPv4), 2) Port und 3) IP-Adresse
	memset(&addr, 0, sizeof(SOCKADDR_IN));

	addr.sin_family = AF_INET;
	addr.sin_port = htons((short)this->port);
	addr.sin_addr.s_addr = inet_addr(this->host.c_str());

	// Verbindung herstellen
	int rc = ::connect(socket, (SOCKADDR*)&addr, sizeof(SOCKADDR));

	return rc != SOCKET_ERROR;
}


/*
dataAvailable()
liefert die Anzahl der Byte, die vom Socket gelesen werden können.
*/
int CSocket::dataAvailable()
{
	//Die dataAvailable-Funktion wurde mit dem Select-Befehl so modifiziert, 
	//dass sie nicht mehr blockierend ist. Sie wartet nur noch 1 Sekunde!

	/* //Ursprünglicher Code
	const int len = 1024;
	char b[len];
	return recv(socket, b, len, MSG_PEEK);
	*/

	fd_set set;
	FD_ZERO(&set);
	FD_SET(socket, &set);
	timeval timeout;
	timeout.tv_sec = long(1); //Wartezeit von einer halben Sekunde
	return select(0, &set, NULL, NULL, &timeout);
}


/*
write(int)
schreibt ein Byte (0..255) auf den Socket; ist keine Verbindung hergestellt, geschieht nichts.
*/
void CSocket::write(int b)
{
	//Im Zuge dessen, dass die write-Funktion vortäuschte ein Integer zu übertragen,
	//doch letztlich nur 8 Bits (1 Byte/Char) übertrug, wurde die Funktion
	//so umgeändert, dass ein Integer (32 Bits) übertragen wird

	/* //Ursprünglicher Code
	char tmp[1];
	tmp[0] = (char)b;
	send(socket, tmp, 1, 0);
	*/

	char tmp[4];

	//Die jeweiligen Umrechnung, damit ein Char jeweils 4 bits enthält/trägt
	tmp[0] = unsigned char(b & 0xFF);
	tmp[1] = unsigned char((b & 0xFF00) / 256);
	tmp[2] = unsigned char((b & 0xFF0000) / 65536);
	tmp[3] = unsigned char((b & 0xFF000000) / 16777216);
	send(socket, tmp, 4, 0);
}

/*
write(char, int)
schreibt len Bytes zum Socket; ist keine Verbindung hergestellt, geschieht nichts.
*/
void CSocket::write(char* b, int len)
{
	//strcat_s(b, "\n"); //Strings verketten. Hier wird ein Absatz angehängt.
	send(socket, b, len, 0);
}

/*
write(string)
schreibt einen String zum Socket; ist die Schnittstelle nicht geöffnet geschieht nichts.
*/
void CSocket::write(std::string s)
{
	s += '\n';
	send(socket, s.c_str(), s.length(), 0);
}

/*
read()
liest ein Byte (0..255) vom Socket; ist kein Byte verfügbar, liefert sie -1.
*/
int CSocket::read()
{
	//Diese Funktion musste ebenfalls angepasst werden, damit sie einen Integer empfängt/ausliest,
	//um mit der oben modifizierten write-Funtkion kompatibel zu sein

	/* //Ursprünglicher Code
	char tmp[1];
	recv(socket, tmp, 1, 0);
	return tmp[0];
	*/

	int returnInteger;
	char tmp[4];

	recv(socket, tmp, 4, 0);
	returnInteger = unsigned char(tmp[0]) + unsigned char(tmp[1]) * 256 + unsigned char(tmp[2]) * 65536 + unsigned char(tmp[3]) * 16777216;

	return returnInteger;
}

/*
read(char* , int)
liest bis zu len Bytes vom Socket in ein Byte-Array; die Anzahl der tatsächlich gelesenen Bytes wird als zurückgeliefert
oder -1, wenn keine Bytes verfügbar sind.
*/
int CSocket::read(char* b, int len)
{
	return recv(socket, b, len, 0);
}

/*
readLine()
liest eine Zeile von der serielle Schnittstelle; eine Zeile wird durch ein Zeilenendezeichen abgeschlossen;
das Zeilenendezeichen wird jedoch nicht in den zurückgegebene String übernommen.
*/
std::string CSocket::readLine()
{
	char buffIn[256];
	int pos = -1;
	do
	{
		pos++;
		recv(socket, buffIn + pos, 1, 0);
	} while (buffIn[pos] != '\n');

	buffIn[pos] = '\0';  // echo-std::string ist mit '\n' abgechlossen
	return std::string(buffIn);
}

/*
close() - löst die Verbingung auf.
*/
void CSocket::close()
{
	closesocket(socket);
}