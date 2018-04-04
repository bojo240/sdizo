#include "Table.h"
#include <iostream>
#include <fstream>
#include <random>
//---------------------------------------------------------------------wyglada, ze gotowe.
Table::Table() : tab(nullptr), cnt(0){;}

bool Table::isValueInTable(int val)
{
    for(int i=0; i<cnt; ++i)
    {
        if(tab[i]==val)
            return true;
    }
    return false;
}

void Table::addValueToTable(int index, int value)
{
    if(index>cnt||index<0) // zabezpieczenie przed nieprawidlowym indeksem
    {
        std::cout<<"\nNieprawidlowy index. Indeksujemy od 0.\n";
        return;
    }//pare operacji, ponizej n operacji
    int *NewTab = new int[cnt+1]; //nowa tablica
    for(int i=0;i<index;i++) // kopiuje wartosci przed indexem
        NewTab[i]=tab[i];
    NewTab[index]=value; //na index wstawiam zadana wartosc
    for(int i=index+1;i<cnt+1;++i) // i kopiuje reszte
        NewTab[i]=tab[i-1];
    delete[] tab; //zwalniam pamiec
    ++cnt; // zwiekszam licznik
    tab=NewTab; // przypisuje wskaznik na nowa tablice.
}

void Table::deleteFromTable(int index)
{
    if(index>=cnt||index<0) //zabezpieczenie
    {
        std::cout<<"\nNieprawidlowy index. Indeksujemy od 0.\n";
        return;
    }
    if(index==cnt-1)//jezeli ostatni element
    {
        delete &tab[index];//po prostu go usun
        --cnt;
        return;
    }//pare operacji, ponizej n operacji
    int *NewTab = new int[cnt-1]; //nowa tablica
    for(int i=0;i<index;++i) //kopiuje wartosci przed indexem
        NewTab[i]=tab[i];
    for(int i=index;i<cnt-1;++i)//kopiuje wartosci po indexie
        NewTab[i]=tab[i+1];
    delete[] tab; //zwalniam pamiec zajmowana przez poprzednia tablice
    --cnt; //zmniejszam licznik
    tab=NewTab;//przypisuje wskaznik na nowa tablice
}

void Table::clearTable()
{
    if(cnt==0)
        return;
    delete[] tab;
    tab=nullptr;
    cnt=0;
}
void Table::generateTable(int size)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 1000000);
    clearTable();
    tab=new int[size]; // deklaruje pamiec
    for(int i=0;i<size;++i) //przypisuje losowe wartosci do tablicy.
        tab[i]=dist(gen);
    cnt=size; // ustawiam licznik
}

void Table::displayTable()
{
    std::cout<<"\nIlosc elementow w tablicy: "<<cnt<<".\n";
    for(int i=0; i<cnt; ++i)
    {
        std::cout<<"\n"<<i<<". "<<tab[i];
    }
    std::cout<<"\n";
}

void Table::loadFromFileToTable(std::string FileName)
{
    std::fstream plik; //tworze zmienna plikowa
    plik.open(FileName,std::ios::in); //otwieram plik
    if(plik.good()) //zabezpieczenie
    {
        delete[] tab; //zwalniam pamiec
        int i=0, a;
        while(plik>>a)//nie podoba mi sie to...
            ++i;//licznik sluzacy okresleniu ilosci danych w pliku
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

void Table::testAdd(int size)
{

}
