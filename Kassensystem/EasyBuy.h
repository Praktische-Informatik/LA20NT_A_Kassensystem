#pragma once

class Kunde;
class Produkt;
#include <string>
#include "List.h"
using namespace std;


class EasyBuy {
private:
	List<Produkt*> produkte;
	List<Kunde*> kunden;
public:
	EasyBuy();
	Kunde* registrierenKunde(string, string);
	Produkt* sucheProdukt(int);
	Kunde* sucheKunde(int);
	void hinzufuegenProdukt(string, double, int);
};

