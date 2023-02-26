#pragma once
class Kunde;
class PositionImEinkaufswagen;
class Produkt;
#include <list>
using namespace std;

class Einkaufswagen
{
private:
	Kunde* kunde;
	list<PositionImEinkaufswagen*> positionenImEinkaufswagen;
public:
	Einkaufswagen(Kunde*);
	void hineinlegen(Produkt*);
	bool herausnehmen(Produkt*);
	double berechneEinkaufswert();
	int getAnzahlInEinkaufswagen(Produkt*);

};

