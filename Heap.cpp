#include "Heap.h"
#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>

Heap::Heap () : cr("  "), cl("  "), cp ("  ")//konstruktor - skoro elementy kopca przetrzymywane sa w tablicy
{
    cnt = 0;
    cr[0] = 218;
    cr[1] = 196;
    cl[0] = 192;
    cl[1] = 196;
    cp[0] = 179;
}

static std::random_device rd;
static std::mt19937 gen(rd());
static std::uniform_int_distribution<> dist(1, 1000000);

//funkcje obliczajace indeksy dzieci oraz rodzica.
int Heap::indexOfLeftChild(int index)
{
    return 2 * index + 1;
}
int Heap::indexOfRightChild(int index)
{
    return 2 * (index + 1);
}
int Heap::indexOfParent (int index)
{
    if(index == 0)return 0;
    return (index - 1) / 2;
}

void Heap::addValue(int value, int index)
{
    tab[cnt] = value; //przypisz kolejnemu elementowi klucz
    //przywrocenie wlasnosci kopca
    for (int i = cnt ; tab[i] > tab [indexOfParent(i) ] ; i = indexOfParent(i)) //petla dopoki klucz rodzica<klucz dziecka,
    {
        //na poczatku i=cnt, po wykonaniu i=i/2 (rodzic staje sie dzieckiem dla jego rodzica)
        int temp = tab[indexOfParent(i)]; //do zmiennej temp przypisuje klucz rodzica
        tab[indexOfParent(i)] = tab[i]; //-}
        tab[i] = temp; //---------------------------}zmieniam klucze rodzica z dzieckiem.
    }
    ++cnt; // zwieksz licznik kopca.
}

bool Heap::isValue(int value)
{
    if(value > tab[0]) // jezel value jest wieksze od klucza korzenia, zwroc -1
        return false;
    for (int i = 0; i < cnt; ++i)
        if(value == tab[i])
            return true;
    return false;
}

void Heap::removeValue(int value, bool test)
{
    int index = 0;
    bool is = false;
    if(value <= tab[0]) // jezel value jest wieksze od klucza korzenia, zwroc false
        for (index = 0; index < cnt; ++index)
            if(value == tab[index])
            {
                is = true;
                break;
            }

    if(is) // jezeli istnieje ten element
    {
        tab[index] = tab[cnt - 1]; //zamieniam klucz usuwanego elementu z ostatnim lisciem w kopcu
        --cnt;//zmniejszam licznik
        int temp;

        //----------------------------------- Przywracanie wlasosci kopca.
        //std::cout<<"\ncnt:"<<cnt<<"\nindex:"<<index<<"\nindexofleftchild:"<<indexOfLeftChild(index)<<"\nindexofrightchild:"<<indexOfRightChild(index);
        //std::cout<<"\ntab[index]:"<<tab[index]<<"\ntab[indexofleftchild(index)]"<<tab[indexOfLeftChild(index)]<<"\ntab[indexofrightchild(index)]"<<tab[indexOfRightChild(index)]<<'\n';
        while(((indexOfLeftChild(index) < cnt) && (tab[index] <= tab[indexOfLeftChild(index)])) ||
                ((indexOfRightChild(index) < cnt) && (tab[index] <= tab[indexOfRightChild(index)]))) //tak dlugo jak rodzic bêdzie mia³ mniejszy klucz od dziecka
        {
            //display();
            if((indexOfLeftChild(index) < cnt) && tab[indexOfLeftChild(index)] <= tab[indexOfRightChild(index)]) //jezeli prawe dziecko jest wieksze od rodzica
            {
                //zamieñ jego wartosc z rodzicem
                temp = tab[index]; //zapisz sobie jedna z wartosci
                tab[index] = tab[indexOfRightChild(index)]; //zamien wartosci
                tab[indexOfRightChild(index)] = temp;//zamien wartosci
                index = indexOfRightChild(index); //rozpatruj dziecko
            }
            else if ((indexOfRightChild(index) < cnt) && tab[indexOfRightChild(index)] <= tab[indexOfLeftChild(index)]) //analogicznie jezeli lewe dziecko jest wieksze.
            {
                temp = tab[index];
                tab[index] = tab[indexOfLeftChild(index)];
                tab[indexOfLeftChild(index)] = temp;
                index = indexOfLeftChild(index);
            }
        }
    }
    else
        std::cout << "Cos poszlo nie tak...\n";
}

void Heap::pop()
{
    removeValue(tab[0]);
}

void Heap::print(std::string sp, std::string sn, int v) //funkcja wyswietlaj¹ca strukture drzewa z portalu eduinf.waw.pl/inf
{
    std::string s;

    if(v < cnt)
    {
        \
        s = sp;
        if(sn == cr) s[s.length() - 2] = ' ';
        print(s + cp, cr, 2 * v + 2);

        s = s.substr(0, sp.length() - 2);

        std::cout << s << sn << tab[v] << std::endl;

        s = sp;
        if(sn == cl) s[s.length() - 2] = ' ';
        print(s + cp, cl, 2 * v + 1);
    }
}

void Heap::display()
{
    print("", "", 0);
}

void Heap::clear()//zwolnij pamiec i ustaw pola obiektu
{
    cnt = 0; //zerowanie licznika
}

void Heap::loadFromFile(std::string FileName)//analogiczne jak w pliku table.cpp
{
    std::fstream plik;
    plik.open(FileName, std::ios::in);
    if(plik.good())
    {
        clear();
        int a;
        plik >> a;
        for(int i = 0; plik >> a; ++i)
            addValue(a);
        plik.close();
    }
    else
        std::cout << "Cos poszlo nie tak...\n";
}

void Heap::generate(int size, long randmax)
{
    clear();//wyczysc poprzednie dane
    for (int i = 0; i < size; ++i) //zapelnij nowymi.
        addValue(dist(gen) % (2 * randmax) - randmax);
}
