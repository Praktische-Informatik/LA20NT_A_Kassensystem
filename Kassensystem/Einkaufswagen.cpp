#include "Einkaufswagen.h"
#include "PositionImEinkaufswagen.h"
#include "Produkt.h"
#include "List.h"
#include <iostream>

Einkaufswagen::Einkaufswagen(Kunde* kunde)
{
	this->kunde = kunde;
}

void Einkaufswagen::hineinlegen(Produkt* produkt)
{
	bool imEinkaufswagen = false;

	for (int i = 0; i < pie.size(); i++) {
		if (produkt == pie.get(i)->getProdukt()) {
			pie.get(i)->erhoeheAnzahl();
			imEinkaufswagen = true;
		}
	}

	if (imEinkaufswagen == false) {
		pie.add(new PositionImEinkaufswagen(produkt));
		produkt->reduziereBestand();
	}
}

bool Einkaufswagen::herausnehmen(Produkt* produkt)
{
	for(int i = 0; i < pie.size(); i++) {
		if (produkt == pie.get(i)->getProdukt()) {
			pie.get(i)->reduziereAnzahl();
			if (pie.get(i)->getAnzahl() == 0) {
				pie.remove(pie.get(i));
			}
			produkt->erhoeheBestand();
		}
		return true;
	}
	return false;
}

double Einkaufswagen::berechneEinkaufswert()
{
	double betrag = 0.0;
	for (int i = 0; i < pie.size(); i++) {
		betrag = betrag + pie.get(i)->getProdukt()->getPreis() * pie.get(i)->getAnzahl();
	}
	return betrag;
}

int Einkaufswagen::getAnzahlInEinkaufswagen(Produkt* produkt)
{
	int anzahl = 0;
	for (int i = 0; i < pie.size(); i++) {
		if (produkt->getBezeichnung() == pie.get(i)->getProdukt()->getBezeichnung()) {
			anzahl = pie.get(i)->getAnzahl();
			//cout << anzahl << endl;
		}
	}
	return anzahl;
}
