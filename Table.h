#pragma once
#include <string>
class Table
{
	int *tab; //tablica dynamiczna
public:
    int cnt; //ilosc elementow w tablicy
    Table();
	void loadFromFileToTable(std::string FileName);
    void displayTable();
    void clearTable();
	bool isValueInTable(int val);
	void addValueToTable(int index, int value);
	void deleteFromTable(int index);
	void generateTable(int size);
	void testAdd(int size);
};
