#pragma once
#include <iostream>
using namespace std;

class String
{
private:
	string text;
public:
	bool equals(String str);		// liefert true, wenn beide Strings gleich sind, ansonsten false.
	String* split(String splitPoint);		// teilt einen String am Trennzeichen str. Die Teil-Strings werden in einem Feld zurückgeliefert.
	bool startsWith(String str);	// liefert true, wenn der String mit str beginnt, ansonsten false.
	bool isEmpty();
	int length();

	String();
	String(string str);
	String(char* str);
	String(const String& str);
	String(const char* str);

	string toC_string() { string t = text; return t; }
	String operator=(const String& str) { text = str.text; return *this; }
	friend ostream& operator<<(ostream& os, const String& x);
	String operator+ (const String& x2) { text += x2.text; return *this; }
	bool operator< (const String& x2) { return text < x2.text; }
	bool operator> (const String& x2) { return text > x2.text; }
	bool operator== (const String& x2) { return text == x2.text; }
	bool operator!= (const String& x2) { return text != x2.text; }

};
