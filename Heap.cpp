#include "Heap.h"
#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>

Heap::Heap () : cr("  "), cl("  "), cp ("  ")//konstruktor - skoro elementy kopca przetrzymywane sa w tablicy,
//tworze statyczna tablice, nadajac jej elementom wartosci 0, ulatwia to kolejne operacje.
{
    cnt=0;
    for (int i=0;i<6000000;i++)
        tab[i]=0;
    cr[0] = 218; cr[1] = 196;
    cl[0] = 192; cl[1] = 196;
    cp[0] = 179;
}

//funkcje obliczajace indeksy dzieci oraz rodzica.
int Heap::indexOfLeftChild(int index) {return 2*index+1;}
int Heap::indexOfRightChild(int index) {return 2*(index+1);}
int Heap::indexOfParent (int index) {if(index==0)return 0; return (index-1)/2;}

int Heap::returnValueOfRoot(){return tab[0];}

void Heap::addNodeToHeap(int value)
{
    tab[cnt]=value; //przypisz kolejnemu elementowi klucz
    //przywrocenie wlasnosci kopca
    for (int i=cnt ; tab[i] > tab [indexOfParent(i) ] ; i=indexOfParent(i)) //petla dopoki klucz rodzica<klucz dziecka,
    { //na poczatku i=cnt, po wykonaniu i=i/2 (rodzic staje sie dzieckiem dla jego rodzica)
        int temp=tab[indexOfParent(i)]; //do zmiennej temp przypisuje klucz rodzica
        tab[indexOfParent(i)] = tab[i]; //-}
        tab[i]=temp; //---------------------------}zmieniam klucze rodzica z dzieckiem.
    }
    ++cnt; // zwieksz licznik kopca.
}

int Heap::isValueInHeap(int value)
{
    if(value>tab[0]) // jezel value jest wieksze od klucza korzenia, false.
        return -1;
    for (int i=0;i<cnt;++i)
        if(value==tab[i])
            return i;
    return -1;
}

void Heap::deleteFromHeap(int value, bool test)
{
    int i=isValueInHeap(value);
    if(i!=(-1))
    {
        tab[i]=tab[cnt-1]; //zamieniam korzeñ z ostatnim lisciem w kopcu
        tab[cnt-1]=0; //'usuwam' lisc
        --cnt;//zmniejszam licznik
        int temp;

        //----------------------------------- Przywracanie w³asoœci kopca.

        while(tab[i]<tab[indexOfRightChild(i)] || tab[i]<tab[indexOfLeftChild(i)])//tak dlugo jak rodzic będzie miał mniejszy klucz od dziecka
        {
            if(tab[indexOfLeftChild(i)]<tab[indexOfRightChild(i)])//jezeli prawe dziecko jest wieksze od rodzica
            {//zamień jego wartosc z rodzicem
                temp=tab[i];//zapisz sobie jedna z wartosci
                tab[i]=tab[indexOfRightChild(i)];//zamien wartosci
                tab[indexOfRightChild(i)] = temp;//zamien wartosci
                i=indexOfRightChild(i);//rozpatruj dziecko
            }
            else//analogicznie jezeli lewe dziecko jest wieksze.
            {
                temp=tab[i];
                tab[i]=tab[indexOfLeftChild(i)];
                tab[indexOfLeftChild(i)] = temp;
                i=indexOfLeftChild(i);
            }
        }
    }
    else
        std::cout<<"Cos poszlo nie tak...\n";
}

void Heap::printHeap(std::string sp, std::string sn, int v)
{
    std::string s;

    if(v < cnt)
    {
    s = sp;
    if(sn == cr) s[s.length() - 2] = ' ';
    printHeap(s + cp, cr, 2 * v + 2);

    s = s.substr(0,sp.length()-2);

    std::cout << s << sn << tab[v] << std::endl;

    s = sp;
    if(sn == cl) s[s.length() - 2] = ' ';
    printHeap(s + cp, cl, 2 * v + 1);
    }
}

void Heap::displayHeap()
{
    printHeap("","",0);
}

void Heap::clearHeap()
{
    for(int i=0;i<cnt;++i) //'czyszczenie' kopca - tablica statyczna.
        tab[i]=0; // zerowanie elementow tablicy
    cnt=0; //zerowanie licznika
}

void Heap::loadFromFileToHeap(std::string FileName)//analogiczne jak w pliku table.cpp
{
    std::fstream plik;
    plik.open(FileName,std::ios::in);
    if(plik.good())
    {
        clearHeap();
        for(int i=0, a ; plik>>a ; ++i)
            addNodeToHeap(a);
        plik.close();
    }
    else
        std::cout<<"Cos poszlo nie tak...\n";
}

void Heap::generateHeap(int size)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 1000000);
    clearHeap();//wyczysc poprzednie dane
    for (int i=0;i<size;++i)//zapelnij nowymi.
        addNodeToHeap(dist(gen)+1);
}
