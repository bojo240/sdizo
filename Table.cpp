#include "Table.h"
#include <iostream>
#include <fstream>
#include <random>

Table::Table() : tab(nullptr), cnt(0)
{
    ;   //lista inicjalizacyjna
}

void Table::addValue(int value, int index) //dodaj do tablicy
{
    if(index > cnt || index < 0) // zabezpieczenie przed nieprawidlowym indeksem
    {
        std::cout << "\nIndex wynosi:" << index << "CNT:" << cnt << "\nNieprawidlowy index. Indeksujemy od 0.\n";
        return;
    }
    int* newtab;
    ++cnt;
    newtab = new int [cnt]; // utworz nowa tablice o rozmiarze o 1 wiekszym
    for(int i = 0; i < index; ++i) // i skopiuj elementy do nowej tablicy
        newtab[i] = tab[i];
    newtab[index] = value;
    for(int i = index; i < cnt; ++i)
        newtab[i + 1] = tab[i];
    if(tab)// jezeli istnieje
        delete[] tab;// usun stara
    tab = newtab;
}

void Table::removeValue(int value)
{
    if(tab[cnt - 1] == value) //jezeli to ostatni element
    {
        --cnt;
        delete &tab[cnt];//po prostu go usun
        return;
    }
    int i = 0;
    for(; i < cnt; ++i) //znajdz element
        if(tab[i] == value)
            break;
    if(i == cnt && tab[i - 1] != value) //jezeli nie znalazles
    {
        std::cout << "Podanej wartosci nie ma w tablicy.";
        return;
    }
    --cnt;
    int* newtab = new int[cnt];
    for (int j = 0; j < i; ++j)
        newtab[j] = tab[j];
    for (int j = i + 1; j < cnt + 1; ++j)
        newtab[j - 1] = tab[j];
    delete[] tab;
    tab = newtab;
}

void Table::removeIndex(int index) //usun z tabeli po indeksie
{
    if(index >= cnt || index < 0) //zabezpieczenie
    {
        std::cout << "\nNieprawidlowy index. Indeksujemy od 0.\n";
        return;
    }
    --cnt;
    int* newtab = new int[cnt];
    for (int i = 0; i < index; ++i)
        newtab[i] = tab[i];
    for (int i = index + 1; i < cnt + 1; ++i)
        newtab[i - 1] = tab[i];
    delete[] tab;
    tab = newtab;
}

bool Table::isValue(int val) // funkcja bool sprawdzajaca czy wartosc jest w tablicy
{
    for(int i = 0; i < cnt; ++i) // sprawdz czy jest w tablicy
        if(tab[i] == val)
            return true;
    return false;
}

void Table::generate(int size, long randmax) // tworzenie tablicy i ustawianie losowych wartosci, wzglednie --- jezeli to test: kopiowanie wartosci z przekazanej tablicy do funkcji
{
    clear(); // wyczysc tablice
    tab = new int[size]; // deklaruje pamiec
    for(int i = 0; i < size; ++i) //przypisuje losowe wartosci do tablicy.
        tab[i] = rand() % (2 * randmax) - randmax;
    cnt = size; // ustawiam licznik
}

void Table::loadFromFile(std::string FileName) // funkcja ladujaca wartosci do tablicy
{
    std::fstream plik; //tworze zmienna plikowa
    plik.open(FileName, std::ios::in); //otwieram plik
    if(plik.good()) //zabezpieczenie
    {
        clear(); // czyszcze pamiec po wczesniejszej tablicy
        plik >> cnt;
        tab = new int[cnt]; //deklaruje pamiec
        int a, i = 0;
        while(plik >> a) //wczytuje wartosci
        {
            tab[i] = a;
            ++i;
        }
        plik.close(); //zamykam plik
    }
    else
        std::cout << "Cos poszlo nie tak...\n";
}

void Table::display() // funkcja wyswietlajaca tablice
{
    std::cout << "\nIlosc elementow w tablicy: " << cnt << ".\n";
    for(int i = 0; i < cnt; ++i)
    {
        std::cout << "\n" << i << ". " << tab[i];
    }
    std::cout << "\n";
}

void Table::clear() // funkcja usuwajaca wszystkie elementy w strukturze
{
    if(!tab || cnt == 0) // jezeli jest pusta
        return;
    delete[] tab; // inaczej zwolnij pamiec
    tab = nullptr; //wyczysc wskaznik
    cnt = 0; // wyzeruj licznik
}
