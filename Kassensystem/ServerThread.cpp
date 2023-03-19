#include "ServerThread.h"
#include "Thread.h"
#include "Einkaufswagen.h"
#include "Kunde.h"
#include "Produkt.h"
#include <string>
#include "List.h"
#include <sstream>   
#include <vector>
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
	cout << input << endl;
	int kundennr = stoi(input);
	cout << "Kundennr: " << kundennr << endl;
	Kunde* kunde = eb->sucheKunde(kundennr);

	if (kunde == nullptr) cout << "Kunde wurde nicht erstellt!" << endl;
	
	Einkaufswagen* ew = kunde->starteEinkauf();
	clientSocket->write("+OK Willkommen\n");

	// Kommandos
	string meldung = "";
	Produkt* p = nullptr;
	input = clientSocket->readLine();
	
	while (input != "beenden") {

		stringstream test(input);
		string segment;
		vector<string> cmd;
		while (getline(test, segment, ';'))
		{
			cmd.push_back(segment);
		}
		string kommando = cmd[0];
		cout << "Test Kommando " << kommando << endl; 
		if (kommando == "legeInEinkaufswagen") {
			int produktnr = stoi(cmd[1]);
			p = eb->sucheProdukt(produktnr);
			
			ew->hineinlegen(p);
			int anzahl = ew->getAnzahlInEinkaufswagen(p);
			meldung = "+OK;" + p->getBezeichnung() + ";" + to_string(anzahl) + " mal;" + to_string(p->getPreis()*anzahl) + "Euro in Einkaufwagen";
			cout << meldung << endl;

		}else if(kommando == "nimmAusEinkaufswagen") {

		}
		else if (kommando == "anzeigeEinkaufswagen") {

		}

		clientSocket->write("hallo");
		input = clientSocket->readLine();
	}
	double gesamt = kunde->beendeEinkauf();
	clientSocket->write("+OK zu zahlen " + to_string(gesamt) + "Euro");
	clientSocket->close();
}
