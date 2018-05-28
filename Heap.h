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
	void addNodeToHeap(int value);
	void deleteFromHeap(int value, bool test = false);
	void loadFromFileToHeap(std::string FileName);
	bool isValueInHeap(int value);//funkcja typu int zwracajaca indeks na szukany element; jezeli nie znajdzie zwraca '-1'
	void displayHeap();
	void generateHeap(int size, int* =nullptr, int randmax=1000);
	void clearHeap();
	int returnValueOfRoot();
};

