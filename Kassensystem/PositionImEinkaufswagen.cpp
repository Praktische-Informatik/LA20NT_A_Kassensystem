#include "PositionImEinkaufswagen.h"
#include "Produkt.h"

PositionImEinkaufswagen::PositionImEinkaufswagen(Produkt* produkt)
{
	this->produkt = produkt;
	this->anzahl = 1;
}

void PositionImEinkaufswagen::erhoeheAnzahl()
{
	++anzahl;
	produkt->reduziereBestand();
}

void PositionImEinkaufswagen::reduziereAnzahl()
{
	if (anzahl > 0) {
		--anzahl;
		produkt->erhoeheBestand();
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
