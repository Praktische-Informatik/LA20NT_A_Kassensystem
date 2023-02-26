#include "CServerSocket.h"
#include "CSocket.h"
#include <iostream>
CServerSocket::CServerSocket(int port)
{
  this->port = port;
  // WinSock-DLL einbinden
  WSADATA wsa;
  WSAStartup(MAKEWORD(2,0),&wsa);

  // 1) Server-Socket erzeugen
  this->serverSocket = ::socket(AF_INET, SOCK_STREAM, 0); // Scope-Operator! Ruft den Konstruktor socket(SOCKET socket) von der Klasse CSocket auf. Kann auch gelöscht wwerden.
  if (this->serverSocket <= 0) 
  {
    std::cerr << "Error: Socket\n";
    return;
  }

  // Erzeuge die Socketadresse des Servers
  SOCKADDR_IN myAddr;
  memset( &myAddr, 0, sizeof(SOCKADDR_IN));
  myAddr.sin_family = AF_INET;
  myAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  myAddr.sin_port = htons((short)this->port);

  // 2) Erzeuge die Bindung an die Serveradresse
  // (d.h. an einen bestimmten Port)
  if (bind(serverSocket, (SOCKADDR*)&myAddr, sizeof(SOCKADDR_IN)) == -1) 
  { 
    closesocket(serverSocket);
    std::cerr << "Error: bind\n"; //std::cerr ist nicht gepuffert, und deshalb für Fehlerausgaben geeignet (wenn z.B. das Programm mitten in der Ausgabe hängen bleibt, dass trotzdem so viel wie möglich ausgegeben wird).
    return;
  }
  // 3) Teile dem Socket mit, dass Verbindungswunsch
  // eines Clients entgegengenommen wird
  if (listen(serverSocket, 5) == -1) 
  {
    closesocket(serverSocket);
    std::cerr << "Error: listen\n";
    return;
  }
}

CSocket* CServerSocket::accept()
{
  SOCKADDR_IN remoteAddr; //Struktur mit den Elementen 1) Adressfamilie (IPv4), 2) Port und 3) IP-Adresse
  int len = sizeof(SOCKADDR_IN);
  SOCKET clientSocket = ::accept(serverSocket, (SOCKADDR*)&remoteAddr, &len); // Verbindung annehmen und Arbeitssocket (clientSocket) erstellen
  if (clientSocket > 0) // wenn -1, dann ERROR -> Rückgabe NULL
  {
    return new CSocket(clientSocket); // Rückgabe ist durch die dynamische Speicherung ein Zeiger. 
  }
  return NULL;
}

void CServerSocket::close()
{
  closesocket(serverSocket);
}
/*
#include "CServerSocket.h"
#include <Ws2tcpip.h>
#include <iostream>

CServerSocket::CServerSocket(int port)
{
    this->port = port;
    // WinSock-DLL einbinden
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 0), &wsa);
    // Server-Socket erzeugen
    this->serverSocket = ::socket(AF_INET, SOCK_STREAM, 0);
    if (this->serverSocket <= 0)
    {
        std::cerr << "Error: Socket\n";
        return;
    }

    // Erzeuge die Socketadresse des Servers
    SOCKADDR_IN myAddr;
    memset(&myAddr, 0, sizeof(SOCKADDR_IN));
    myAddr.sin_family = AF_INET;
    myAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    myAddr.sin_port = htons((short)this->port);

    // Erzeuge die Bindung an die Serveradresse
    // (d.h. an einen bestimmten Port)
    if (bind(serverSocket, (SOCKADDR*)&myAddr, sizeof(SOCKADDR_IN)) == -1)
    {
        closesocket(serverSocket);
        std::cerr << "Error: bind\n";
        return;
    }
    // Teile dem Socket mit, dass Verbindungswunsch
    // eines Clients entgegengenommen wird
    if (listen(serverSocket, 5) == -1)
    {
        closesocket(serverSocket);
        std::cerr << "Error: listen\n";
        return;
    }
}

CSocket* CServerSocket::accept()
{
    // Bearbeite die Verbindungswunsch von Clients
    // Der Aufruf von accept() blockiert solange,
    // bis ein Client Verbindung aufnimmt
    SOCKADDR_IN remoteAddr;
    int len = sizeof(SOCKADDR_IN);
    SOCKET clientSocket = ::accept(serverSocket, (SOCKADDR*)&remoteAddr, &len);
    if (clientSocket > 0)
    {
        return new CSocket(clientSocket);
    }
    return NULL;
}

void CServerSocket::close()
{
    closesocket(serverSocket);
}
*/