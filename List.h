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

	void addValue(int index, int value);
	void remove(int value, bool test=false);
	Elements* isValue(int value);
    void generate(int size, int * = nullptr, int randmax=1000);
    void loadFromFile(std::string FileName);
	void display();
	void clear();
	int returnValue(int index);
};
