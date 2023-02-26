#pragma once
#include "Kunde.h"
class VIPKunde : public Kunde
{
private:
	int rabattSatz;
public:
	VIPKunde(string, string);
	double beendeEinkauf();
};

