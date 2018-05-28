#pragma once
#include <string>
class Table
{
	int *tab; //tablica dynamiczna // jedyne prywatne pole
public:
    int cnt; //ilosc elementow w tablicy
    Table(); //konstruktor
    void addValueToTable(int index, int value);
	void loadFromFileToTable(std::string FileName);
    void displayTable();
    void clearTable();
	bool isValueInTable(int val);
	void deleteFromTable(int index);
	void generateTable(int size, int* =nullptr, int randmax=1000);
};
