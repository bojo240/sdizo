#include "Table.h"
#include <iostream>
#include <fstream>
#include <random>

Table::Table() : tab(nullptr), cnt(0){;} //lista inicjalizacyjna

static std::random_device rd;
static std::mt19937 gen(rd());
static std::uniform_int_distribution<> dist(1, 1000000);

void Table::addValue(int index, int value) //dodaj do tablicy
{
    if(index>cnt||index<0) // zabezpieczenie przed nieprawidlowym indeksem
    {
        std::cout<<"\nNieprawidlowy index. Indeksujemy od 0.\n";
        return;
    }
    int *NewTab = new int[cnt+1]; //nowa tablica
    for(int i=0;i<index;i++) // kopiuje wartosci przed indeksem
        NewTab[i]=tab[i];
    NewTab[index]=value; //na index wstawiam zadana wartosc
    for(int i=index+1;i<cnt+1;++i) // i kopiuje reszte
        NewTab[i]=tab[i-1];
    delete[] tab; //zwalniam pamiec
    ++cnt; // zwiekszam licznik
    tab=NewTab; // przypisuje wskaznik na nowa tablice z przekazana wartoscia
}

void Table::removeValue(int value)
{
    int i=0;
    for(;i<cnt;++i)
        if(tab[i]==value)
            break;
    //std::cout<<"cnt to:"<<cnt<<"a i to:"<<i<<'\n';
    if(i==cnt&&tab[i-1]!=value)
    {
        std::cout<<"Podanej wartosci nie ma w tablicy.";
        return;
    }
    else if(tab[cnt-1]==value)
    {
        delete &tab[i];//po prostu go usun
        --cnt;
        return;
    }
    int *NewTab = new int[cnt-1];
    for(int j=0;j<i;++j)
        NewTab[j]=tab[j];
    for(int j=i+1;j<cnt;++j)
        NewTab[j-1]=tab[j];
        delete[] tab;
    --cnt;
    tab=NewTab;

}

void Table::removeIndex(int index) //usun z tabeli
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

bool Table::isValue(int val) // funkcja bool sprawdzajaca czy wartosc jest w tablicy
{
    for(int i=0; i<cnt; ++i) // funkcja przechodzi po wszystkich elementach tablicy, cnt to publiczna zmienna mowiaca o ilosci elementow w tablicy
    {
        if(tab[i]==val)
            return true;
    }
    return false;
}

void Table::generate(int size, int* t, int randmax) // tworzenie tablicy i ustawianie losowych wartosci, wzglednie --- jezeli to test: kopiowanie wartosci z przekazanej tablicy do funkcji
{
    clear(); // wyczysc tablice
    tab=new int[size]; // deklaruje pamiec
    if(t) //jezeli jest to test
        for(int i=0;i<size;++i)
            tab[i]=t[i];// to zapisz do tablicy wartosci z tablicy przekazanej do funkcji
    else
        for(int i=0;i<size;++i) //przypisuje losowe wartosci do tablicy.
            tab[i]=dist(gen)%(2*randmax)-randmax;
    cnt=size; // ustawiam licznik
}

void Table::loadFromFile(std::string FileName) // funkcja ³adujaca wartosci do tablicy
{
    std::fstream plik; //tworze zmienna plikowa
    plik.open(FileName,std::ios::in); //otwieram plik
    if(plik.good()) //zabezpieczenie
    {
        //najpierw przechodze przez caly plik, zeby dowiedziec sie ile jest elementow do wczytania
        delete[] tab; //zwalniam pamiec
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
