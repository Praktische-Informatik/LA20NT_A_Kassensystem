#include "Kunde.h"
#include "Einkaufswagen.h"
#include <iostream>

int Kunde::autowert = 1;

Kunde::Kunde(string name, string vorname)
{
	this->kundennr = autowert++;
	this->angemeldet = false;
	this->einkaufswagen = nullptr;
	this->name = name;
	this->vorname = vorname;
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
	double ergebnis = einkaufswagen->berechneEinkaufswert();
	delete einkaufswagen;
	this->einkaufswagen = nullptr;
	return ergebnis;
}

int Kunde::getKundenNr()
{
	return kundennr;
}
