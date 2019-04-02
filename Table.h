#pragma once
#include <string>
class Table
{
    int *tab; //tablica dynamiczna
    int cnt; //ilosc elementow w tablicy
public:
    Table(); //konstruktor
    void addValue(int, int);
    void removeValue(int value);
    void removeIndex(int index);
    bool isValue(int value);
    void generate(int size = 100, long randmax = 1000);
    void loadFromFile(std::string FileName);
    void display();
    void clear();
    int getCnt()
    {
        return cnt;
    }
};
