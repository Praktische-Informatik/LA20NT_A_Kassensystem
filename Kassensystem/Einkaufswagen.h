#pragma once
class Kunde;
class PositionImEinkaufswagen;
class Produkt;
#include "List.h"
using namespace std;

class Einkaufswagen
{
private:
	Kunde* kunde;
	List<PositionImEinkaufswagen*> pie;
public:
	Einkaufswagen(Kunde*);
	void hineinlegen(Produkt*);
	bool herausnehmen(Produkt*);
	double berechneEinkaufswert();
	int getAnzahlInEinkaufswagen(Produkt*);

};

