#include "Produkt.h"

int Produkt::autowert = 100;

Produkt::Produkt(string bezeichnung, double preis, int bestand)
{
	this->bezeichnung = bezeichnung;
	this->preis = preis;
	this->bestand = bestand;
	this->produktnr = autowert++;
}

void Produkt::reduziereBestand()
{
	if (bestand > 0) {
		bestand--;
	}
}

void Produkt::erhoeheBestand()
{
	bestand++;
}

double Produkt::getPreis()
{
	return preis;
}

int Produkt::getProduktNr()
{
	return produktnr;
}

string Produkt::getBezeichnung()
{
	return bezeichnung;
}
int Produkt::getBestand()
{
	return bestand;
}
