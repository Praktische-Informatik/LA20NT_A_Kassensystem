// Kassensystem.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "Server.h"
#include "EasyBuy.h"
#include "CSocket.h"
#include <vector>

int main()
{

	char input;
	cout << "Server[0] oder Client[1]?: ";
	cin >> input;
	if (input == '0') {

		EasyBuy* eb = new EasyBuy();
		eb->registrierenKunde("Anton", "Anfang");
		eb->registrierenKunde("Bea", "Beispiel");
		eb->registrierenKunde("Theo", "Testmann");
		eb->hinzufuegenProdukt("Chips", 1.00, 100);
		eb->hinzufuegenProdukt("Spaghetti", 1.50, 100);
		eb->hinzufuegenProdukt("Banane", 2.50, 10);
		Server* s = new Server(7070, eb);
		
		cout << "Server startet..." << endl;
		s->runServer();
	}
	else if(input == '1'){
		CSocket* c = new CSocket("127.0.0.1", 7070);
		c->connect();
		c->write("2"); // Kundennummer
		c->write("legeInEinkaufswagen;101");
		cout << c->readLine() << endl;
		c->write("legeInEinkaufswagen;102");
		cout << c->readLine() << endl;
		c->write("beenden");
		cout << c->readLine() << endl;
	}

	
}
