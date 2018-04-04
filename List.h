#pragma once
#include <string>
struct Elements
{
    int Value; //klucz
    Elements *Next;//wskaznik na nastepny Elements
    Elements *Prev;//wskaznik na poprzedni Elements
    Elements(); //konstruktor/lista inicjalizacyjna
};

class List
{
    //ilosc Elementsow w liscie
    Elements *Head; //wskaznik na Head
    Elements *Tail; //wskaznik na Tail

public:
    int cnt;
    List ();//konstruktor/lista inicjalizacyjna
    void loadFromFileToList(std::string FileName);
	bool isValueInList(int value);
	void addValueToList(int index, int value);
	void deleteFromList(int index, bool test=false);
	void displayList();
	void generateList(int size);
	void clearList();
	int returnValue(int index);
};
