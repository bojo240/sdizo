#pragma once
#include <string>
class Heap
{
    std::string cr,cl,cp;
    int cnt;//ilosc elementow w kopcu
    int tab[6000000]; //tablica statyczna
    int indexOfLeftChild(int index) ;
	int indexOfRightChild(int index);
	int indexOfParent(int index);
    void printHeap(std::string, std::string, int);
public:
    Heap ();
	void addNodeToHeap(int value);
	void deleteFromHeap(int value, bool test = false);
	void loadFromFileToHeap(std::string FileName);
	int isValueInHeap(int value);//funkcja typu int zwracajaca indeks na szukany element; jezeli nie znajdzie zwraca '-1'
	void displayHeap();
	void generateHeap(int size);
	void clearHeap();
	int returnValueOfRoot();
};

