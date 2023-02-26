#include "EasyBuy.h"
#include "Kunde.h"
#include "Produkt.h"
#include <iostream>

EasyBuy::EasyBuy()
{
}

Kunde* EasyBuy::registrierenKunde(string name, string vorname)
{
	Kunde* kunde = new Kunde(name, vorname);
	this->kunden.push_back(kunde);
	cout << "Kunde erstellt mit Kunden NR: " + to_string(kunde->getKundenNr()) << endl;
	return kunde;
}

Produkt* EasyBuy::sucheProdukt(int produktnr)
{
	for (Produkt* p : this->produkte) {
		if (p->getProduktNr() == produktnr) {
			//out << "produkt gefunden" << endl;
			return p;
			
		}
	}
	cout << "produkt nicht gefunden" << endl;
	return nullptr;
}

Kunde* EasyBuy::sucheKunde(int kundennr)
{
	//cout << "suche Kunde...";
	for (Kunde* k : this->kunden) {
		if (k->getKundenNr() == kundennr) {
			return k;
		}
	}
	return nullptr;
}
void EasyBuy::hinzufuegenProdukt(string bz, double pr, int be)
{
	Produkt* p = new Produkt(bz, pr, be);
	this->produkte.push_back(p);
}
