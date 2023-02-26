#pragma once

class Kunde;
class Produkt;
#include <string>
#include <list>
using namespace std;


class EasyBuy {
private:
	list<Produkt*> produkte;
	list<Kunde*> kunden;
public:
	EasyBuy();
	Kunde* registrierenKunde(string, string);
	Produkt* sucheProdukt(int);
	Kunde* sucheKunde(int);
	void hinzufuegenProdukt(string, double, int);
};

