#include "ServerThread.h"
#include "Thread.h"
#include "Einkaufswagen.h"
#include "Kunde.h"
#include "Produkt.h"
#include "String.h"  // String --> Java != string --> c++
#include <string>
#include "List.h"
//#include <sstream>   
//#include <vector>
#include <iostream>
using namespace std;

ServerThread::ServerThread(CSocket* cs, EasyBuy* eb)
{
	this->eb = eb;
	this->clientSocket = cs;

}

void ServerThread::run()
{
	// Kunde anmelden
	string input = clientSocket->readLine();
	int kundennr = stoi(input);
	cout << "Kundennr: " << kundennr << endl;
	Kunde* kunde = eb->sucheKunde(kundennr);

	if (kunde == nullptr) cout << "Kunde wurde nicht erstellt!" << endl;
	
	Einkaufswagen* ew = kunde->starteEinkauf();
	clientSocket->write("+OK Willkommen\n");

	// Kommandos
	string meldung = ""; // cpp String!
	Produkt* p = nullptr;
	String line = clientSocket->readLine(); // Java String!
	
	while (!line.equals("beenden")) {
		String* cmd = line.split(";");
		String kommando = cmd[0];

		if (kommando == "legeInEinkaufswagen") {  
			cout << "1. Kommando: " << kommando << endl;
			int produktnr = stoi(cmd[1].toC_string()); 
			p = eb->sucheProdukt(produktnr);
			ew->hineinlegen(p);
			int anzahl = ew->getAnzahlInEinkaufswagen(p);
			meldung = "+OK; " + p->getBezeichnung() + "; " + to_string(anzahl) + " mal; " + to_string(p->getPreis()*anzahl) + " Euro in Einkaufwagen";
			clientSocket->write(meldung);

		}else if(kommando == "nimmAusEinkaufswagen") {
			cout << "2. Kommando: " << kommando << endl;
			//int produktnr = stoi(cmd[1].toC_string());
			//p = eb->sucheProdukt(produktnr);
			//ew->herausnehmen(p);
			//int anzahl = ew->getAnzahlInEinkaufswagen(p);
			//meldung = "+OK; " + p->getBezeichnung() + "; " + to_string(anzahl) + " mal; " + to_string(p->getPreis() * anzahl) + " Euro in Einkaufwagen";
		}
		else if (kommando == "anzeigeEinkaufswagen") {
			cout << "3. Kommando: " << kommando << endl;
			clientSocket->write(meldung);
		}
		line = clientSocket->readLine();
	}
	double gesamt = kunde->beendeEinkauf();
	clientSocket->write("+OK zu zahlen " + to_string(gesamt) + " Euro");
	clientSocket->close();
}
