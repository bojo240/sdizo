#include "Table.h"
#include <iostream>
#include <fstream>
#include <random>

Table::Table() : tab(nullptr), cnt(0) {;} //lista inicjalizacyjna

static std::random_device rd;
static std::mt19937 gen(rd());
static std::uniform_int_distribution<> dist(1, 1000000);

void Table::addValue(int value, int index) //dodaj do tablicy
{
    //std::cout<<tab;
    //std::cout<<"Halo";
    int* newtab;
    if(index>cnt||index<0) // zabezpieczenie przed nieprawidlowym indeksem
    {
        std::cout<<"\nNieprawidlowy index. Indeksujemy od 0.\n";
        return;
    }
    ++cnt;
    newtab = new int [cnt]; // utworz nowa tablice o rozmiarze o 1 wiekszym
    for(int i=0;i<index;++i) // i skopiuj elementy do nowej tablicy
        newtab[i]=tab[i];
    //std::cout<<"dalej";
    newtab[index] = value;
    for(int i=index+1;i<cnt;++i)
        newtab[i+1]=tab[i];
    //std::cout<<"asd";
    if(tab)
        delete[] tab;// usun stara
    tab = newtab;
    //std::cout<<"jeszcze";
}

void Table::removeValue(int value)
{
    if(tab[cnt-1]==value)//jezeli to ostatni element
    {
        --cnt;
        delete &tab[cnt];//po prostu go usun
        return;
    }
    int i=0;
    for(;i<cnt;++i)//znajdz element
        if(tab[i]==value)
            break;
    if(i==cnt&&tab[i-1]!=value)//jezeli nie znalazles
    {
        std::cout<<"Podanej wartosci nie ma w tablicy.";
        return;
    }
    --cnt;
    int* newtab = new int[cnt];
    for (int j=0;j<i;++j)
        newtab[j] = tab[j];
    for (int j=i+1;j<cnt+1;++j)
        newtab[j-1] = tab[j];
    delete[] tab;
    tab = newtab;
}

void Table::removeIndex(int index) //usun z tabeli po indeksie
{
    if(index>=cnt||index<0) //zabezpieczenie
    {
        std::cout<<"\nNieprawidlowy index. Indeksujemy od 0.\n";
        return;
    }
    --cnt;
    int* newtab = new int[cnt];
    for (int i=0;i<index;++i)
        newtab[i] = tab[i];
    for (int i=index+1;i<cnt+1;++i)
        newtab[i-1] = tab[i];
    delete[] tab;
    tab = newtab;
}

bool Table::isValue(int val) // funkcja bool sprawdzajaca czy wartosc jest w tablicy
{
    for(int i=0; i<cnt; ++i) // sprawdz czy jest w tablicy
        if(tab[i]==val)
            return true;
    return false;
}

void Table::generate(int size, int* t, int randmax) // tworzenie tablicy i ustawianie losowych wartosci, wzglednie --- jezeli to test: kopiowanie wartosci z przekazanej tablicy do funkcji
{
    clear(); // wyczysc tablice
    tab = new int[size]; // deklaruje pamiec
    if(t) //jezeli jest to test
        for(int i=0;i<size;++i)
            tab[i]=t[i];// to zapisz do tablicy wartosci z tablicy przekazanej do funkcji
    else
        for(int i=0;i<size;++i) //przypisuje losowe wartosci do tablicy.
            tab[i]=dist(gen)%(2*randmax)-randmax;
    cnt=size; // ustawiam licznik
}

void Table::loadFromFile(std::string FileName) // funkcja �adujaca wartosci do tablicy
{
    std::fstream plik; //tworze zmienna plikowa
    plik.open(FileName,std::ios::in); //otwieram plik
    if(plik.good()) //zabezpieczenie
    {//najpierw przechodze przez caly plik, zeby dowiedziec sie ile jest elementow do wczytania
        clear();
        int i=0, a;
        while(plik>>a)
            ++i;//licznik sluzacy okresleniu ilosci danych w pliku
        //potem deklaruje pamiec i wczytuje dane z pliku do tablicy
        tab=new int[i]; //deklaruje pamiec
        cnt=i;//ustawiam licznik
        i=0; // zeruje indeks
        plik.close(); //otwieram plik na nowo
        plik.open(FileName,std::ios::in);
        while(plik>>a)//wczytuje wartosci
        {
            tab[i]=a;
            ++i;
        }
        plik.close(); //zamykam plik
    }
    else
        std::cout<<"Cos poszlo nie tak...\n";
}

void Table::display() // funkcja wyswietlajaca tablice
{
    std::cout<<"\nIlosc elementow w tablicy: "<<cnt<<".\n";
    for(int i=0; i<cnt; ++i)
    {
        std::cout<<"\n"<<i%1000<<". "<<tab[i];
    }
    std::cout<<"\n";
}

void Table::clear() // funkcja usuwajaca wszystkie elementy w strukturze
{
    if(cnt==0) // jezeli jest pusta
        return;
    delete[] tab; // inaczej zwolnij pamiec
    tab=nullptr; //wyczysc wskaznik
    cnt=0; // wyzeruj licznik
}
