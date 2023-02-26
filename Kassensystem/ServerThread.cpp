#include "ServerThread.h"
#include "Thread.h"
#include "Einkaufswagen.h"
#include "Kunde.h"
#include "Produkt.h"
#include <string>
#include <list>
#include <sstream>   
#include <vector>
#include <iostream>
using namespace std;

ServerThread::ServerThread(CSocket* cs, EasyBuy* eb)
{
	this->eb = eb;
	this->s = cs;

}

void ServerThread::run()
{
	string input = s->readLine();
	cout << input << endl;
	int kundennr = stoi(input);
	Kunde* kunde = eb->sucheKunde(kundennr);
	if (kunde == nullptr) cout << "null" << endl;
	Einkaufswagen* ew = kunde->starteEinkauf();
	s->write("+OK Willkommen\n");

	string output = "null";
	Produkt* p = nullptr;
	input = s->readLine();
	
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
			cout << "Test produktnr " << produktnr << endl;
			p = eb->sucheProdukt(produktnr);
			cout << "Test Produkt " << p->getBezeichnung() << endl;
			
			ew->hineinlegen(p);
			int anzahl = ew->getAnzahlInEinkaufswagen(p);
			output = "+OK;" + p->getBezeichnung() + ";" + to_string(anzahl) + " mal;" + to_string(p->getPreis()*anzahl) + "Euro in Einkaufwagen";
			cout << "Test output " << output << endl;

		}else if(kommando == "nimmAusEinkaufswagen") {

		}
		else if (kommando == "anzeigeEinkaufswagen") {

		}

		s->write("hallo");
		input = s->readLine();
	}
	double gesamt = kunde->beendeEinkauf();
	s->write("+OK zu zahlen " + to_string(gesamt) + "Euro");
	s->close();
}
