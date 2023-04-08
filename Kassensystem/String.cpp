#include "String.h"

ostream& operator<<(ostream& os, const String& x) {
	os << x.text;
	return os;
};


bool String::equals(String str)
{
	return *this == str;
}

String* String::split(String splitPoint)
{
	string sp = splitPoint.text;
	int anz = 0;
	string text(this->text);
	auto anzahl = [=, &anz]() mutable {
		while (text.find(sp) <= text.length()) {
			text.erase(text.find(sp), sp.length());
			anz++;
		}
	};
	anzahl();
	String* allsp = new String[anz+1];
	
	auto splittext = [=]() mutable {
		for (int i = 0; i < anz + 1; i++) {
			allsp[i] = text.substr(0, text.find(sp));
			text.erase(0, text.find(sp) + sp.length());
		}
	};
	splittext();
	return allsp;
}

bool String::startsWith(String str)
{
	return str == text.substr(0, str.length());
}

bool String::isEmpty()
{
	return (text.length() == 0) ? true : false;
}

int String::length()
{
	return text.length();
}

String::String()
{
	text = "";
}

String::String(string str) : text(str)
{
}

String::String(char* str) : text(str)
{
}


String::String(const char* str) : text(str)
{
}


String::String(const String& str)
{
	text = str.text;
}
