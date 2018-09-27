#pragma once
#include <string>
class Table
{
	int *tab; //tablica dynamiczna // jedyne prywatne pole
public:
    int cnt; //ilosc elementow w tablicy
    Table(); //konstruktor
    void addValue(int index, int value);
    void remove(int index);
	bool isValue(int val);
	void generate(int size, int* =nullptr, int randmax=1000);
	void loadFromFile(std::string FileName);
    void display();
    void clear();
};
