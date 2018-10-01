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
    int cnt;
public:
    List ();//konstruktor/lista inicjalizacyjna
	void addValue(int index, int value);
	void removeValue(int value);
	void removeIndex(int index);
	Elements* isValue(int value);
    void generate(int size, int * = nullptr, int randmax=1000);
    void loadFromFile(std::string FileName);
	void display();
	void clear();
	int returnValue(int index);
};
