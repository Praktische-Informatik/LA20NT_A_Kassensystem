#include "EasyBuy.h"
#include "Kunde.h"
#include "Produkt.h"
#include <iostream>
using namespace std;

EasyBuy::EasyBuy()
{
}

Kunde* EasyBuy::registrierenKunde(string name, string vorname)
{
	Kunde* kunde = new Kunde(name, vorname);
	this->kunden.add(kunde);
	cout << "Kunde erstellt mit Kunden NR: " + to_string(kunde->getKundenNr()) << endl;
	return kunde;
}

Produkt* EasyBuy::sucheProdukt(int produktnr)
{
	for (int i = 0; i < produkte.size(); i++) {
		if (produkte.get(i)->getProduktNr() == produktnr) {
			cout << "Produkt gefunden" << endl;
			return produkte.get(i);
		}
	}
	cout << "produkt nicht gefunden" << endl;
	return nullptr;
}

Kunde* EasyBuy::sucheKunde(int kundennr)
{
	for (int i = 0; i < kunden.size(); i++) {
		if (kunden.get(i)->getKundenNr() == kundennr) {
			return kunden.get(i);
		}
	}
	return nullptr;
}
void EasyBuy::hinzufuegenProdukt(string bz, double pr, int be)
{
	Produkt* p = new Produkt(bz, pr, be);
	this->produkte.add(p);
}
