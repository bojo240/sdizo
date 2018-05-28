#include "Heap.h"
#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>

Heap::Heap () : cr("  "), cl("  "), cp ("  ")//konstruktor - skoro elementy kopca przetrzymywane sa w tablicy,
//tworze statyczna tablice, nadajac jej elementom wartosci 0, ulatwia to kolejne operacje.
{
    cnt=0;
    maxsize=1;
    tab=nullptr;
    cr[0] = 218; cr[1] = 196;
    cl[0] = 192; cl[1] = 196;
    cp[0] = 179;
}

static std::random_device rd;
static std::mt19937 gen(rd());
static std::uniform_int_distribution<> dist(1, 1000000);

//funkcje obliczajace indeksy dzieci oraz rodzica.
int Heap::indexOfLeftChild(int index) {return 2*index+1;}
int Heap::indexOfRightChild(int index) {return 2*(index+1);}
int Heap::indexOfParent (int index) {if(index==0)return 0; return (index-1)/2;}

int Heap::returnValueOfRoot(){return tab[0];}

void Heap::addNodeToHeap(int value)
{
    int* newtab; //nowy wskaznik
    if(cnt+1>=maxsize) //jezeli juz nie ma miejsca
    {
        maxsize*=2; // zwieksz maxsize dwukrotnie
        newtab = new int [maxsize]; // utworz nowa, dwukrotnie wieksza tablice
        for(int i=0;i<cnt;++i) // i skopiuj elementy do nowej tablicy
            newtab[i]=tab[i];
        if(tab)
            delete[] tab;// usun stara
    }
    else // jezeli jest wciaz miejsce
        newtab = tab; // nowy wskaznik ustaw na stara tablice.
    newtab[cnt]=value; //przypisz kolejnemu elementowi klucz
    //przywrocenie wlasnosci kopca
    for (int i=cnt ; newtab[i] > newtab [indexOfParent(i) ] ; i=indexOfParent(i)) //petla dopoki klucz rodzica<klucz dziecka,
    { //na poczatku i=cnt, po wykonaniu i=i/2 (rodzic staje sie dzieckiem dla jego rodzica)
        int temp=newtab[indexOfParent(i)]; //do zmiennej temp przypisuje klucz rodzica
        newtab[indexOfParent(i)] = newtab[i]; //-}
        newtab[i]=temp; //---------------------------}zmieniam klucze rodzica z dzieckiem.
    }
    ++cnt; // zwieksz licznik kopca.
    tab=newtab;// i zmien wskaznik obiektu na nowa tablice
}

bool Heap::isValueInHeap(int value)
{
    if(value>tab[0]) // jezel value jest wieksze od klucza korzenia, zwroc -1
        return false;
    for (int i=0;i<cnt;++i)
        if(value==tab[i])
            return true;
    return false;
}

void Heap::deleteFromHeap(int value, bool test)
{
    int index=0;
    bool is=false;
    if(value<=tab[0]) // jezel value jest wieksze od klucza korzenia, zwroc false
        for (index=0;index<cnt;++index)
            if(value==tab[index])
            {
                is=true;
                break;
            }

    if(is) // jezeli istnieje ten element
    {
        tab[index]=tab[cnt-1]; //zamieniam korzeñ z ostatnim lisciem w kopcu
        int* newtab; //tworze nowy wskaznik

        if((cnt-1)<=(maxsize/2))// jezeli nowy rozmiar tablicy jest na tyle maly ze pamiec mozna zmniejszyc o polowe
        {
            maxsize/=2; // to zmniejsz maxsize
            newtab=new int[maxsize/2]; //i zadeklaruj nowa tablice
            for(int j=0;j<(cnt-1);++j)
                newtab[j]=tab[j];
            delete[] tab;
        }
        else
            newtab=tab;
        --cnt;//zmniejszam licznik
        int temp;

        //----------------------------------- Przywracanie w³asoœci kopca.
        index=0;
        while(((indexOfLeftChild(index)<cnt)&&(newtab[index]<newtab[indexOfLeftChild(index)])) ||
               ((indexOfRightChild(index)<cnt)&&(newtab[index]<newtab[indexOfRightChild(index)])))//tak dlugo jak rodzic będzie miał mniejszy klucz od dziecka
        {
            if(newtab[indexOfLeftChild(index)]<=newtab[indexOfRightChild(index)])//jezeli prawe dziecko jest wieksze od rodzica
            {//zamień jego wartosc z rodzicem
                temp=newtab[index];//zapisz sobie jedna z wartosci
                newtab[index]=newtab[indexOfRightChild(index)];//zamien wartosci
                newtab[indexOfRightChild(index)] = temp;//zamien wartosci
                index=indexOfRightChild(index);//rozpatruj dziecko
            }
            else if (newtab[indexOfRightChild(index)]<newtab[indexOfLeftChild(index)])//analogicznie jezeli lewe dziecko jest wieksze.
            {
                temp=newtab[index];
                newtab[index]=newtab[indexOfLeftChild(index)];
                newtab[indexOfLeftChild(index)] = temp;
                index=indexOfLeftChild(index);
            }
        }
        tab=newtab;
    }
    else
        std::cout<<"Cos poszlo nie tak...\n";
}

void Heap::printHeap(std::string sp, std::string sn, int v) //funkcja wyswietlająca strukture drzewa z portalu eduinf.waw.pl/inf
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
    if(tab)
        delete[] tab;
    tab=nullptr;
    maxsize=1;
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

void Heap::generateHeap(int size, int* table, int randmax)
{
    clearHeap();//wyczysc poprzednie dane
    if(table)
        for (int i=0;i<size;++i)//zapelnij nowymi.
            addNodeToHeap(table[i]);
    else
        for (int i=0;i<size;++i)//zapelnij nowymi.
            addNodeToHeap(dist(gen)%(2*randmax)-randmax);
}
