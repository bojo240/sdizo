#pragma once
#include <string>
struct Elements
{
    int Value; //klucz
    Elements *Next;//wskaznik na nastepny Elements
    Elements *Prev;//wskaznik na poprzedni Elements
    Elements(); //konstruktor
};

class List
{
    Elements *Head; //wskaznik na Head
    Elements *Tail; //wskaznik na Tail
public:
    int cnt;  //ilosc Elementow w liscie
    List ();//konstruktor/lista inicjalizacyjna
    void loadFromFileToList(std::string FileName);
	Elements* isValueInList(int value);
	void addValueToList(int index, int value);
	void deleteFromList(int value, bool test=false);
	void displayList();
	void generateList(int size, int * = nullptr, int randmax=1000);
	void clearList();
	int returnValue(int index);
};
