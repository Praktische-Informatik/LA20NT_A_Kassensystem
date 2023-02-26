#include "Kunde.h"
#include "Einkaufswagen.h"
#include <iostream>

int Kunde::autowert = 0;

Kunde::Kunde(string name, string vorname)
{
	this->autowert++;
	this->kundennr = this->autowert;
	this->angemeldet = false;
	this->einkaufswagen = nullptr;
	this->name = name;
	this->vorname = vorname;
	//cout << "Autowert: " + this->autowert << endl;
}

Einkaufswagen* Kunde::starteEinkauf()
{
	this->angemeldet = true;
	einkaufswagen = new Einkaufswagen(this);
	return einkaufswagen;
}

double Kunde::beendeEinkauf()
{
	this->angemeldet = false;
	double out = einkaufswagen->berechneEinkaufswert();
	this->einkaufswagen = nullptr;
	return out;
}

int Kunde::getKundenNr()
{
	return kundennr;
}
