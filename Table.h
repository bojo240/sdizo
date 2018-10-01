#pragma once
#include <string>
class Table
{
	int *tab; //tablica dynamiczna
    int cnt; //ilosc elementow w tablicy
public:
    Table(); //konstruktor
    void addValue(int index, int value);
    void removeValue(int value);
    void removeIndex(int index);
	bool isValue(int value);
	void generate(int size, int* =nullptr, int randmax=1000);
	void loadFromFile(std::string FileName);
    void display();
    void clear();
    int getCnt(){return cnt;}
};
