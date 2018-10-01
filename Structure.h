#pragma once
#include <string>

class Structure
{
    int cnt; //ilosc elementow w strukturze, zmienna chroniona przed przypadkowa zmiana
    public:
    void addValue(int value, int index=-1);//dodaj wartosc pod okreslony indeks, o ile takowy istnieje
    void removeValue(int value);//usun po wartosci
    void removeIndex(int index);//usun po indeksie
	bool isValue(int value);//czy wartosc znajduje sie w strukturze
	void generate(int size, int* =nullptr, int randmax=1000); // generuj strukture
	void loadFromFile(std::string FileName);// zaladuj dane z pliku do struktury
    void display();//wyswietl strukture
    void clear();//usun cala strukture
    int getCnt(){return cnt;}//zwroc cala strukture
};
