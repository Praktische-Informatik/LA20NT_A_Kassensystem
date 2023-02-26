#pragma once
class Produkt;

class PositionImEinkaufswagen
{
private:
	int anzahl;
	Produkt* produkt;
public:
	PositionImEinkaufswagen(Produkt*);
	void erhoeheAnzahl();
	void reduziereAnzahl();
	Produkt* getProdukt();
	int getAnzahl();
};

