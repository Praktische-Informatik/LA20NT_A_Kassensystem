#pragma once
#include <list>
using namespace std;

// Eine Liste für eine beliebige Klasse T
template<class T> class List
{
private:
	list <T> * meineListe;
public:
	List()			//Konstruktor mit dynamischer Erzeugung einer Liste vom Typ list 
	{
		meineListe = new list<T>;
	}
	~List() { 
		//delete meineListe; // @Aeneas: gelöscht, da sonst eine Liste in der Liste gelöscht wird (siehe Aquarium Lebewesenliste)
	}

	void add(T);		// hängt das Objekt obj vom Typ T am Ende der Liste an.

	void add(int index, T obj);  //fügt das Objekt obj vom Typ T an der Position index in die Liste ein.

	bool contains(T obj);    //liefert true, wenn das Objekt obj in der Liste enthalten ist, andernfalls false.

	T get(int index);       //liefert das Listenelement an der Position index (bei Null beginnend) zurück bzw. null, falls index negativ oder größer
						    //gleich der Anzahl der momentan enthaltenen Elemente ist.

	T remove(int index);	//entfernt das Listenelement an der Position index (bei Null beginnend).Liefert das entfernte Element zurück bzw.null,
							//falls index negativ oder größer gleich der Anzahl der momentan enthaltenen Elemente ist.

	bool remove(T obj);	//entfernt das Objekt obj aus der Liste. Falls obj mehrmals in der Liste enthalten ist, wird nur das erste
							//Vorkommen entfernt.Der Rückgabewert ist true, falls das Objekt gefunden und entfernt wurde,
							//andernfalls ist er false.
	int size();				//liefert die Anzahl der Elemente in der Liste zurück.
};





template<class T> int List<T>::size()
{
	return meineListe->size();
}


// Neues Element in die Liste einfügen
template<class T> void List<T>::add(T obj)
{
	meineListe->push_back(obj);
}

template<class T> void List<T>::add(int index, T obj)
{
	if (index < 0 || index >= meineListe->size())
		return;
	list<T>::template iterator it = meineListe->begin();
	advance(it, index);

	meineListe->insert(it, obj);
}

template<class T> bool List<T>::contains(T obj)
{
	bool found = (std::find(meineListe->begin(), meineListe->end(), obj) != meineListe->end());
	return found;
}

template<class T> T  List<T>::get(int index)
{
	if (index < 0 || index >= meineListe->size())
		return 0;
	int i = 0;

	for (auto cursor : (*meineListe))
	{
		if (i == index)
			return cursor;
		i++;
	}
	return 0;
}
template<class T> T  List<T>::remove(int index)
{
	if (index < 0 || index >= meineListe->size())
		return 0;
	T tmp = this->get(index);
	list<T>::template iterator it = meineListe->begin();
	advance(it, index);
	meineListe->erase(it);
	return tmp;
}

template<class T> bool  List<T>::remove(T obj)
{
	if (obj == 0)
		return false;

	for (std::list<T>::template iterator it = meineListe->begin(); it != meineListe->end(); ++it)
	{
		if ((*it) == obj)
		{
			meineListe->erase(it);
			return true;
		}
	}
	return false;
}
