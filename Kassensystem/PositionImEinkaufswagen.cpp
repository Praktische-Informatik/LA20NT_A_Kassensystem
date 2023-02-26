#include "PositionImEinkaufswagen.h"
#include "Produkt.h"

PositionImEinkaufswagen::PositionImEinkaufswagen(Produkt* produkt)
{
	this->produkt = produkt;
	this->anzahl = produkt->getBestand();
}

void PositionImEinkaufswagen::erhoeheAnzahl()
{
	anzahl++;
}

void PositionImEinkaufswagen::reduziereAnzahl()
{
	if (anzahl > 0) {
		anzahl--;
	}
}

Produkt* PositionImEinkaufswagen::getProdukt()
{
	return produkt;
}

int PositionImEinkaufswagen::getAnzahl()
{
	return anzahl;
}
