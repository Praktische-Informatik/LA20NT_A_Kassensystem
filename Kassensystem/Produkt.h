#pragma once
#include <string>
using namespace std;

class Produkt
{
private:
	int produktnr;
	static int autowert;
	string bezeichnung;
	int bestand;
	double preis;
public:
	Produkt(string, double, int);
	void reduziereBestand();
	void erhoeheBestand();
	double getPreis();
	int getProduktNr();
	string getBezeichnung();
	int getBestand();
};

