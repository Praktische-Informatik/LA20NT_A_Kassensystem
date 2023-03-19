// Kassensystem.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "Server.h"
#include "EasyBuy.h"
#include "CSocket.h"
//#include "Einkaufswagen.h"
//#include "Kunde.h"
//#include "Produkt.h"

int main()
{

	char input;
	cout << "Server[1] oder Client[2]?: ";
	cin >> input;
	if (input == '1') {

		EasyBuy* eb = new EasyBuy();
		eb->registrierenKunde("Anton", "Anfang");
		eb->registrierenKunde("Bea", "Beispiel");
		eb->registrierenKunde("Theo", "Testmann");
		eb->hinzufuegenProdukt("Chips", 1.00, 80);
		eb->hinzufuegenProdukt("Spaghetti", 1.50, 50);
		eb->hinzufuegenProdukt("Banane", 2.50, 10);
		
		Server* s = new Server(7070, eb);
		
		cout << "Server startet..." << endl;
		s->runServer();
	}
	else if(input == '2'){
		CSocket* kundenwunsch = new CSocket("127.0.0.1", 7070);
		while (!kundenwunsch->connect()) cout << "suche Server " << endl; // zum Debuggen wichtig
		kundenwunsch->write("2"); // Kundennummer
		kundenwunsch->write("legeInEinkaufswagen;100");
		cout << kundenwunsch->readLine() << endl;
		kundenwunsch->write("legeInEinkaufswagen;101");
		cout << kundenwunsch->readLine() << endl;
		kundenwunsch->write("legeInEinkaufswagen;100");
		cout << kundenwunsch->readLine() << endl;
		//cout << kundenwunsch->readLine() << endl;
		kundenwunsch->write("anzeigeEinkaufswagen;0");
		cout << kundenwunsch->readLine() << endl;

		kundenwunsch->write("beenden");
		cout << "beenden gesendet" << endl;
		cout << kundenwunsch->readLine() << endl;
	}

	
}
