#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Kassenautomat
{
private:
	static vector<vector<int>> a;
public:
	vector<vector<int>> berechneWechselgeldstuecke(int);
};

/*
Hier benutze ich einen 2D Vektor, da ein 2-Dimensionales Int Array sich hierfür nicht eignet.
Wegen der Speicher allocation und deallocationm die man für ein 2D Int Array bräuchte, welches man dynamisch anlegt,
habe ich beschlossen auf ein Vektor zurückzugreifen, da dieser das im hintergrund regelt.
*/

