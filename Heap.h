#pragma once
#include <string>
class Heap
{
    std::string cr,cl,cp;
    int cnt;//ilosc elementow w kopcu
    int* tab; //tablica dynamiczna
    int maxsize;
    int indexOfLeftChild(int index); //funkcje wyliczajace indeksy rodzica oraz dzieci elementu
	int indexOfRightChild(int index);
	int indexOfParent(int index);
    void print(std::string, std::string, int); // funkcja sluzaca do wyswietlania drzewa  --  z portalu eduinf.waw.pl/inf
public:
    Heap ();
	void addValue(int value);
	void removeValue(int value, bool test = false);
    void pop();
	bool isValue(int value);
    void generate(int size, int* =nullptr, int randmax=1000);
	void loadFromFile(std::string FileName);
	void display();
	void clear();
	int returnValueOfRoot();
};

