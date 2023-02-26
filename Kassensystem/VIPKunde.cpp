#include "VIPKunde.h"
#include "Einkaufswagen.h"

VIPKunde::VIPKunde(string name, string nachname):Kunde(name, nachname)
{
	this->rabattSatz = 80;
}

double VIPKunde::beendeEinkauf()
{
	this->angemeldet = false;
	this->einkaufswagen = nullptr;
	return this->einkaufswagen->berechneEinkaufswert() * 0.01 * this->rabattSatz;
}
