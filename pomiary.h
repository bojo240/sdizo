#pragma once
#include <conio.h>
#include <string>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <ctime>
#include <typeinfo>
#include <cmath>
#include <windows.h>
#include <ratio>

typedef std::chrono::high_resolution_clock Clock;
using std::chrono::nanoseconds;
using namespace std::chrono;
class pomiary
{
    std::fstream plik;
    static const int pktypomiar = 10; //zmienna globalna okreslajaca rozdzielczosc pomiarow
    static const int powtorzenia = 100; //ile razy dokonac testow
    double pomiar[pktypomiar];

public:

    template <class T>
    T add(T typ, long range, int place, int size, std::string filename)
    {
        std::mt19937_64 gen (std::random_device{}());
        for(int i = 0; i < pktypomiar; ++i)
            pomiar[i] = 0.0;
        std::uint64_t where;
        plik.open(filename, std::ios::out); //otworzenie pliku
        if(place == 0)
            where = 0;
        if(plik.good())
        {
            for(int k = 0; k < powtorzenia; ++k)
            {
                for (int i = 0; i < pktypomiar; ++i)
                {
                    typ.generate((i + 1)*size, range);
                    auto t1 = Clock::now();
//                    for(int j=0;j<100;++j)
//                    {
//                        if (place == 1)
//                            where = gen()%((i+1)*size);
//                        else if (place == 2)
//                            where = (i+1)*size;
                    typ.addValue((gen() % 2 * range) - range, where);
//                    }
                    auto t2 = Clock::now();
                    duration<double, std::micro> time = duration_cast<duration<double>>(t2 - t1);
                    pomiar[i] = pomiar[i] + time.count(); // dodaj do odpowiedniego pola w tablicy pomiarow
                    typ.clear(); //wyczysc tablice
                }
            }
            for(int i = 0; i < pktypomiar; ++i)
                plik << (i + 1)*size << " " << pomiar[i] / powtorzenia << '\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
            plik.close();
        }
    }

    //void pomiary::addsmalltotablebegin()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=200; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("TableAddSmallToBeginning.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myTab.generateTable((i+1)*wielkoscstruktury,nullptr,100);
//                    StartCounter(); //zacznij mierzyc czas
//                    myTab.addValueToTable(0, (dist(gen)%200)-100);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myTab.clearTable(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<< fabs(pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//
//    void addsmalltotablebegin();
//    void addaveragetotablebegin();
//    void addlargetotablebegin();
//
//    void addsmalltotablerandom();
//    void addaveragetotablerandom();
//    void addlargetotablerandom();
//
//    void addsmalltotableend();
//    void addaveragetotableend();
//    void addlargetotableend();
//
//    void addsmalltolistbegin();
//    void addaveragetolistbegin();
//    void addlargetolistbegin();
//
//    void addsmalltolistrandom();
//    void addaveragetolistrandom();
//    void addlargetolistrandom();
//
//    void addsmalltolistend();
//    void addaveragetolistend();
//    void addlargetolistend();
//
//    void addsmalltoheap();
//    void addaveragetoheap();
//    void addlargetoheap();
//
//    void addsmalltoBST();
//    void addaveragetoBST();
//    void addlargetoBST();
//
//    void addsmalltoBST_DSW();
//    void addaveragetoBST_DSW();
//    void addlargetoBST_DSW();
//
//
//    void removesmallfromtablebegin();
//    void removeaveragefromtablebegin();
//    void removelargefromtablebegin();
//
//    void removesmallfromtablerandom();
//    void removeaveragefromtablerandom();
//    void removelargefromtablerandom();
//
//    void removesmallfromtableend();
//    void removeaveragefromtableend();
//    void removelargefromtableend();
//
//    void removesmallfromlistbegin();
//    void removeaveragefromlistbegin();
//    void removelargefromlistbegin();
//
//    void removesmallfromlistrandom();
//    void removeaveragefromlistrandom();
//    void removelargefromlistrandom();
//
//    void removesmallfromlistend();
//    void removeaveragefromlistend();
//    void removelargefromlistend();
//
//    void removesmallfromheap();
//    void removeaveragefromheap();
//    void removelargefromheap();
//
//    void removesmallfromBST();
//    void removeaveragefromBST();
//    void removelargefromBST();
//
//    void removesmallfromBST_DSW();
//    void removeaveragefromBST_DSW();
//    void removelargefromBST_DSW();
//
//
//    void findsmallintable();
//    void findavarageintable();
//    void findlargeintable();
//
//    void findsmallinlist();
//    void findavarageinlist();
//    void findlargeinlist();
//
//    void findsmallinheap();
//    void findavarageinheap();
//    void findlargeinheap();
//
//    void findsmallinBST();
//    void findavarageinBST();
//    void findlargeinBST();

    //  int iloscpomiarow;
};
