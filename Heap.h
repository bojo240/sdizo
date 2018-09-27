#pragma once
#include <string>
class Heap
{
    std::string cr,cl,cp;
    int cnt;//ilosc elementow w kopcu
    int* tab; //tablica statyczna
    int maxsize;
    int indexOfLeftChild(int index); //funkcje wyliczajace indeksy rodzica oraz dzieci elementu
	int indexOfRightChild(int index);
	int indexOfParent(int index);
    void printHeap(std::string, std::string, int); // funkcja sluzaca do wyswietlania drzewa  --  z portalu eduinf.waw.pl/inf
public:
    Heap ();
	void addValue(int value);
	void remove(int value, bool test = false);
	bool isValue(int value);
    void generate(int size, int* =nullptr, int randmax=1000);
	void loadFromFile(std::string FileName);
	void display();
	void clear();
	int returnValueOfRoot();
};

