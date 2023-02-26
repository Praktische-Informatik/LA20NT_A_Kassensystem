#pragma once
class Einkaufswagen;

#include <string>

using namespace std;

class Kunde
{
protected:
	Einkaufswagen* einkaufswagen;
	int kundennr;
	static int autowert;
	string name;
	string vorname;
	bool angemeldet;
public:
	Kunde(string, string);
	Einkaufswagen* starteEinkauf();
	double beendeEinkauf();
	int getKundenNr();
};

