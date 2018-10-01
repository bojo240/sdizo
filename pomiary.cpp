#include <conio.h>
#include <string>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <ctime>
#include <windows.h>
#include "Table.h"
#include "List.h"
#include "Heap.h"
#include "BST.h"
#include "pomiary.h"

static std::fstream plik;
static std::random_device rd;
static std::mt19937 gen(rd());
static std::uniform_int_distribution<> dist(1, 1000000);

double PCFreq = 0.0;
__int64 CounterStart = 0;

template <typename T>
T add(T type, char size, char place)
{
tak na prawde nie musze wiedziec jaki obiekt jest
przekazany, wystarczy ze wszystkie metody sa ponazywane
tak saamo w kazdej klasie/strukturze.

}


void pomiary::StartCounter()
{
    LARGE_INTEGER li;
    PCFreq = double(li.QuadPart)/1000000000000.0;
    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}

double pomiary::GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}
//
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
//void pomiary::addaveragetotablebegin()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=200; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("TableAddAverageToBeginning.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myTab.generateTable((i+1)*wielkoscstruktury,nullptr,10000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myTab.addValueToTable(0, (dist(gen)%20000)-10000);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myTab.clearTable(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::addlargetotablebegin()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=200; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("TableAddLargeToBeginning.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myTab.generateTable((i+1)*wielkoscstruktury,nullptr,1000000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myTab.addValueToTable(0, (dist(gen)%2000000)-1000000);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myTab.clearTable(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::addsmalltotablerandom()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=200; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("TableAddSmallToRandom.txt" , std::ios::out); //otworzenie pliku
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
//                    myTab.addValueToTable(dist(gen)%myTab.cnt, (dist(gen)%200)-100);
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
//void pomiary::addaveragetotablerandom()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=200; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("TableAddAverageToRandom.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myTab.generateTable((i+1)*wielkoscstruktury,nullptr,10000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myTab.addValueToTable(dist(gen)%myTab.cnt, (dist(gen)%20000)-10000);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myTab.clearTable(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::addlargetotablerandom()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=200; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("TableAddLargeToRandom.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myTab.generateTable((i+1)*wielkoscstruktury,nullptr,1000000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myTab.addValueToTable(dist(gen)%myTab.cnt, (dist(gen)%2000000)-1000000);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myTab.clearTable(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::addsmalltotableend()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=200; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("TableAddSmallToEnd.txt" , std::ios::out); //otworzenie pliku
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
//                    myTab.addValueToTable(myTab.cnt, (dist(gen)%200)-100);
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
//void pomiary::addaveragetotableend()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=200; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("TableAddAverageToEnd.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myTab.generateTable((i+1)*wielkoscstruktury,nullptr,10000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myTab.addValueToTable(myTab.cnt, (dist(gen)%20000)-10000);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myTab.clearTable(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::addlargetotableend()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=200; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("TableAddLargeToEnd.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myTab.generateTable((i+1)*wielkoscstruktury,nullptr,1000000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myTab.addValueToTable(myTab.cnt, (dist(gen)%2000000)-1000000);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myTab.clearTable(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::addsmalltolistbegin()
//{
//double PCFreq = 0.0; __int64 CounterStart = 0; double pomiar[pktypomiar];
//    int wielkoscstruktury=100; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("ListAddSmallToBeginning.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myList.generateList((i+1)*wielkoscstruktury,nullptr,100);
//                    StartCounter(); //zacznij mierzyc czas
//                    myList.addValueToList(0, (dist(gen)%200)-100);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myList.clearList(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::addaveragetolistbegin()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=100; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("ListAddAverageToBeginning.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myList.generateList((i+1)*wielkoscstruktury,nullptr,10000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myList.addValueToList(0, (dist(gen)%20000)-10000);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myList.clearList(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::addlargetolistbegin()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=100; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("ListAddLargeToBeginning.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myList.generateList((i+1)*wielkoscstruktury,nullptr,1000000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myList.addValueToList(0, (dist(gen)%2000000)-1000000);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myList.clearList(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::addsmalltolistrandom()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=100; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("ListAddSmallToRandom.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myList.generateList((i+1)*wielkoscstruktury,nullptr,100);
//                    StartCounter(); //zacznij mierzyc czas
//                    myList.addValueToList((dist(gen)%myList.cnt), (dist(gen)%200)-100);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myList.clearList(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<< fabs(pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::addaveragetolistrandom()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=100; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("ListAddAverageToRandom.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myList.generateList((i+1)*wielkoscstruktury,nullptr,10000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myList.addValueToList(myList.cnt%dist(gen), (dist(gen)%20000)-10000);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myList.clearList(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::addlargetolistrandom()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=100; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("ListAddLargeToRandom.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myList.generateList((i+1)*wielkoscstruktury,nullptr,10000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myList.addValueToList(myList.cnt%dist(gen), (dist(gen)%2000000)-1000000);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myList.clearList(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::addsmalltolistend()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=100; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("ListAddSmallToEnd.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myList.generateList((i+1)*wielkoscstruktury,nullptr,100);
//                    StartCounter(); //zacznij mierzyc czas
//                    myList.addValueToList(myList.cnt%dist(gen), (dist(gen)%200)-100);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myList.clearList(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::addaveragetolistend()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=100; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("ListAddAverageToEnd.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myList.generateList((i+1)*wielkoscstruktury,nullptr,10000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myList.addValueToList(myList.cnt%dist(gen), (dist(gen)%20000)-10000);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myList.clearList(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::addlargetolistend()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=100; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("ListAddLargeToEnd.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myList.generateList((i+1)*wielkoscstruktury,nullptr,1000000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myList.addValueToList(myList.cnt%dist(gen), (dist(gen)%20000)-10000);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myList.clearList(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::addsmalltoheap()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=100; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("HeapAddSmall.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myHeap.generateHeap((i+1)*wielkoscstruktury,nullptr,100);
//                    StartCounter(); //zacznij mierzyc czas
//                    myHeap.addNodeToHeap((dist(gen)%200)-100);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myHeap.clearHeap(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<< fabs(pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::addaveragetoheap()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=100; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("HeapAddAverage.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myHeap.generateHeap((i+1)*wielkoscstruktury,nullptr,10000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myHeap.addNodeToHeap((dist(gen)%20000)-10000);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myHeap.clearHeap(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::addlargetoheap()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=100; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("HeapAddLarge.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myHeap.generateHeap((i+1)*wielkoscstruktury,nullptr,1000000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myHeap.addNodeToHeap((dist(gen)%2000000)-1000000);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myHeap.clearHeap(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::addsmalltoBST()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=100; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("BSTAddSmall.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myBST.generateBST((i+1)*wielkoscstruktury,nullptr,100);
//                    StartCounter(); //zacznij mierzyc czas
//                    myBST.addNodeToBST((dist(gen)%200)-100, false);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myBST.clearBST(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<< fabs(pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::addaveragetoBST()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=100; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("BSTAddAverage.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myBST.generateBST((i+1)*wielkoscstruktury,nullptr,10000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myBST.addNodeToBST((dist(gen)%20000)-10000, false);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myBST.clearBST(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::addlargetoBST()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=100; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("BSTAddLarge.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myBST.generateBST((i+1)*wielkoscstruktury,nullptr,1000000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myBST.addNodeToBST((dist(gen)%2000000)-1000000,false);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myBST.clearBST(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::addsmalltoBST_DSW()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=100; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("BSTAddSmallDSW.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myBST.generateBST((i+1)*wielkoscstruktury,nullptr,100);
//                    StartCounter(); //zacznij mierzyc czas
//                    myBST.addNodeToBST((dist(gen)%200)-100);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myBST.clearBST(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::addaveragetoBST_DSW()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=100; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("BSTAddAverageDSW.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myBST.generateBST((i+1)*wielkoscstruktury,nullptr,10000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myBST.addNodeToBST((dist(gen)%20000)-10000);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myBST.clearBST(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::addlargetoBST_DSW()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=100; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("BSTAddLargeDSW.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myBST.generateBST((i+1)*wielkoscstruktury,nullptr,1000000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myBST.addNodeToBST((dist(gen)%2000000)-1000000);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myBST.clearBST(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::removesmallfromtablebegin()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=200; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("TableRemoveSmallFromBeginning.txt" , std::ios::out); //otworzenie pliku
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
//                    myTab.deleteFromTable(0);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myTab.clearTable(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::removeaveragefromtablebegin()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=200; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("TableRemoveAverageFromBeginning.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myTab.generateTable((i+1)*wielkoscstruktury,nullptr,10000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myTab.deleteFromTable(0);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myTab.clearTable(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::removelargefromtablebegin()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=200; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("TableRemoveLargeFromBeginning.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myTab.generateTable((i+1)*wielkoscstruktury,nullptr,1000000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myTab.deleteFromTable(0);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myTab.clearTable(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::removesmallfromtablerandom()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=200; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("TableRemoveSmallFromRandom.txt" , std::ios::out); //otworzenie pliku
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
//                    myTab.deleteFromTable(dist(gen)%myTab.cnt);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myTab.clearTable(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::removeaveragefromtablerandom()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=200; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("TableRemoveAverageFromRandom.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myTab.generateTable((i+1)*wielkoscstruktury,nullptr,10000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myTab.deleteFromTable(dist(gen)%myTab.cnt);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myTab.clearTable(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::removelargefromtablerandom()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=200; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("TableRemoveLargeFromRandom.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myTab.generateTable((i+1)*wielkoscstruktury,nullptr,1000000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myTab.deleteFromTable(dist(gen)%myTab.cnt);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myTab.clearTable(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::removesmallfromtableend()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=200; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("TableRemoveSmallFromEnd.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myTab.generateTable((i+1)*wielkoscstruktury,nullptr,2000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myTab.deleteFromTable(myTab.cnt-1);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myTab.clearTable(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::removeaveragefromtableend()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=200; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("TableRemoveAverageFromEnd.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myTab.generateTable((i+1)*wielkoscstruktury,nullptr,10000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myTab.deleteFromTable(myTab.cnt-1);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myTab.clearTable(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::removelargefromtableend()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=200; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("TableRemoveLargeFromEnd.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myTab.generateTable((i+1)*wielkoscstruktury,nullptr,100000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myTab.deleteFromTable(myTab.cnt-1);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myTab.clearTable(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::removesmallfromlistbegin()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=100; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("ListRemoveSmallFromBeginning.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myList.generateList((i+1)*wielkoscstruktury,nullptr,100);
//                    StartCounter(); //zacznij mierzyc czas
//                    myList.deleteFromList(myList.returnValue(0));
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myList.clearList(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::removeaveragefromlistbegin()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=100; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("ListRemoveAverageFromBeginning.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myList.generateList((i+1)*wielkoscstruktury,nullptr,10000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myList.deleteFromList(myList.returnValue(0));
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myList.clearList(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::removelargefromlistbegin()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=100; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("ListRemoveLargeFromBeginning.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myList.generateList((i+1)*wielkoscstruktury,nullptr,1000000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myList.deleteFromList(myList.returnValue(0));
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myList.clearList(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::removesmallfromlistrandom()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=100; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("ListRemoveSmallFromRandom.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myList.generateList((i+1)*wielkoscstruktury,nullptr,100);
//                    StartCounter(); //zacznij mierzyc czas
//                    myList.deleteFromList(myList.returnValue(dist(gen)%myList.cnt));
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myList.clearList(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::removeaveragefromlistrandom()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=100; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("ListRemoveAverageFromRandom.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myList.generateList((i+1)*wielkoscstruktury,nullptr,10000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myList.deleteFromList(myList.returnValue(dist(gen)%myList.cnt));
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myList.clearList(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::removelargefromlistrandom()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=100; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("ListRemoveLargeFromRandom.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myList.generateList((i+1)*wielkoscstruktury,nullptr,1000000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myList.deleteFromList(myList.returnValue(dist(gen)%myList.cnt));
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myList.clearList(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::removesmallfromlistend()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=100; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("ListRemoveSmallFromEnd.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myList.generateList((i+1)*wielkoscstruktury,nullptr,2000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myList.deleteFromList(myList.returnValue(myList.cnt-1));
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myList.clearList(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::removeaveragefromlistend()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=100; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("ListRemoveAverageFromEnd.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myList.generateList((i+1)*wielkoscstruktury,nullptr,10000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myList.deleteFromList(myList.returnValue(myList.cnt-1));
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myList.clearList(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::removelargefromlistend()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=100; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("ListRemoveLargeFromEnd.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myList.generateList((i+1)*wielkoscstruktury,nullptr,100000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myList.deleteFromList(myList.returnValue(myList.cnt-1));
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myList.clearList(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::removesmallfromheap()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=100; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("HeapRemoveSmall.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myHeap.generateHeap((i+1)*wielkoscstruktury,nullptr,100);
//                    StartCounter(); //zacznij mierzyc czas
//                    myHeap.deleteFromHeap(myHeap.returnValueOfRoot(), true);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myHeap.clearHeap(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<< fabs(pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::removeaveragefromheap()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=100; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("HeapRemoveAverage.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myHeap.generateHeap((i+1)*wielkoscstruktury,nullptr,10000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myHeap.deleteFromHeap(myHeap.returnValueOfRoot(), true);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myHeap.clearHeap(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::removelargefromheap()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=100; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("HeapRemoveLarge.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    myHeap.generateHeap((i+1)*wielkoscstruktury,nullptr,1000000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myHeap.deleteFromHeap(myHeap.returnValueOfRoot(), true);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myHeap.clearHeap(); //wyczysc tablice
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::removesmallfromBST()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=50; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("BSTRemoveSmall.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    int a=(i+1)*wielkoscstruktury;
//                    int* tab = new int [a];
//                        for(int m=0;m<a;++m)
//                            tab[i]=dist(gen)%100;
//                    myBST.generateBST(a, tab, 100);
//                    StartCounter(); //zacznij mierzyc czas
//                    myBST.deleteFromBST(tab[dist(gen)%a], true, false);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myBST.clearBST(); //wyczysc tablice
//                    delete[] tab;
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::removeaveragefromBST()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=50; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("BSTRemoveAverage.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    int a=(i+1)*wielkoscstruktury;
//                    int* tab = new int [a];
//                        for(int m=0;m<a;++m)
//                            tab[i]=dist(gen)%10000;
//                    myBST.generateBST(a, tab, 10000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myBST.deleteFromBST(tab[dist(gen)%a], true, false);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myBST.clearBST(); //wyczysc tablice
//                    delete[] tab;
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::removelargefromBST()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=50; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("BSTRemoveLarge.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    int a=(i+1)*wielkoscstruktury;
//                    int* tab = new int [a];
//                        for(int m=0;m<a;++m)
//                            tab[i]=dist(gen)%1000000;
//                    myBST.generateBST(a, tab, 1000000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myBST.deleteFromBST(tab[dist(gen)%a], true, false);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myBST.clearBST(); //wyczysc tablice
//                    delete[] tab;
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::removesmallfromBST_DSW()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=50; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("BSTRemoveDSWSmall.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    int a=(i+1)*wielkoscstruktury;
//                    int* tab = new int [a];
//                        for(int m=0;m<a;++m)
//                            tab[i]=dist(gen)%100;
//                    myBST.generateBST(a, tab, 100);
//                    StartCounter(); //zacznij mierzyc czas
//                    myBST.deleteFromBST(tab[dist(gen)%a], true, true);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myBST.clearBST(); //wyczysc tablice
//                    delete[] tab;
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::removeaveragefromBST_DSW()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=50; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("BSTRemoveDSWAverage.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    int a=(i+1)*wielkoscstruktury;
//                    int* tab = new int [a];
//                        for(int m=0;m<a;++m)
//                            tab[i]=dist(gen)%10000;
//                    myBST.generateBST(a, tab, 10000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myBST.deleteFromBST(tab[dist(gen)%a], true, true);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myBST.clearBST(); //wyczysc tablice
//                    delete[] tab;
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::removelargefromBST_DSW()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=50; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("BSTRemoveDSWLarge.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    int a=(i+1)*wielkoscstruktury;
//                    int* tab = new int [a];
//                    for(int m=0;m<a;++m)
//                        tab[i]=dist(gen)%1000000;
//                    myBST.generateBST(a, tab, 1000000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myBST.deleteFromBST(tab[dist(gen)%a], true, true);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myBST.clearBST(); //wyczysc tablice
//                    delete[] tab;
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::findsmallintable()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=200; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("TableFindSmall.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    int a=(i+1)*wielkoscstruktury;
//                    int* tab = new int [a];
//                    for(int m=0;m<a;++m)
//                        tab[i]=dist(gen)%2000;
//                    myTab.generateTable(a,tab,2000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myTab.isValueInTable(tab[dist(gen)%a]);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myTab.clearTable(); //wyczysc tablice
//                    delete[] tab;
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::findavarageintable()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=200; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("TableFindAverage.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    int a=(i+1)*wielkoscstruktury;
//                    int* tab = new int [a];
//                    for(int m=0;m<a;++m)
//                        tab[i]=dist(gen)%10000;
//                    myTab.generateTable(a,tab,10000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myTab.isValueInTable(tab[dist(gen)%a]);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myTab.clearTable(); //wyczysc tablice
//                    delete[] tab;
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::findlargeintable()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=200; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("TableFindLarge.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    int a=(i+1)*wielkoscstruktury;
//                    int* tab = new int [a];
//                    for(int m=0;m<a;++m)
//                        tab[i]=dist(gen)%100000;
//                    myTab.generateTable(a,tab,100000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myTab.isValueInTable(tab[dist(gen)%a]);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myTab.clearTable(); //wyczysc tablice
//                    delete[] tab;
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::findsmallinlist()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=100; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("ListFindSmall.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    int a=(i+1)*wielkoscstruktury;
//                    int* tab = new int [a];
//                    for(int m=0;m<a;++m)
//                        tab[i]=dist(gen)%2000;
//                    myList.generateList(a,tab,2000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myList.isValueInList(tab[dist(gen)%a]);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myList.clearList(); //wyczysc tablice
//                    delete[] tab;
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::findavarageinlist()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=100; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("ListFindAvarage.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    int a=(i+1)*wielkoscstruktury;
//                    int* tab = new int [a];
//                    for(int m=0;m<a;++m)
//                        tab[i]=dist(gen)%10000;
//                    myList.generateList(a,tab,10000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myList.isValueInList(tab[dist(gen)%a]);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myList.clearList(); //wyczysc tablice
//                    delete[] tab;
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::findlargeinlist()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=100; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("ListFindLarge.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    int a=(i+1)*wielkoscstruktury;
//                    int* tab = new int [a];
//                    for(int m=0;m<a;++m)
//                        tab[i]=dist(gen)%100000;
//                    myList.generateList(a,tab,100000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myList.isValueInList(tab[dist(gen)%a]);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myList.clearList(); //wyczysc tablice
//                    delete[] tab;
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::findsmallinheap()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=100; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("HeapFindSmall.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    int a=(i+1)*wielkoscstruktury;
//                    int* tab = new int [a];
//                    for(int m=0;m<a;++m)
//                        tab[i]=dist(gen)%2000;
//                    myHeap.generateHeap(a,tab,2000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myHeap.isValueInHeap(tab[dist(gen)%a]);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myHeap.clearHeap(); //wyczysc tablice
//                    delete[] tab;
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::findavarageinheap()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=100; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("HeapFindAvarage.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    int a=(i+1)*wielkoscstruktury;
//                    int* tab = new int [a];
//                    for(int m=0;m<a;++m)
//                        tab[i]=dist(gen)%10000;
//                    myHeap.generateHeap(a,tab,10000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myHeap.isValueInHeap(tab[dist(gen)%a]);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myHeap.clearHeap(); //wyczysc tablice
//                    delete[] tab;
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::findlargeinheap()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=100; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("HeapFindLarge.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    int a=(i+1)*wielkoscstruktury;
//                    int* tab = new int [a];
//                    for(int m=0;m<a;++m)
//                        tab[i]=dist(gen)%100000;
//                    myHeap.generateHeap(a,tab,100000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myHeap.isValueInHeap(tab[dist(gen)%a]);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myHeap.clearHeap(); //wyczysc tablice
//                    delete[] tab;
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::findsmallinBST()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=50; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("BSTFindSmall.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    int a=(i+1)*wielkoscstruktury;
//                    int* tab = new int [a];
//                    for(int m=0;m<a;++m)
//                        tab[i]=dist(gen)%2000;
//                    myBST.generateBST(a,tab,2000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myBST.isValueInBST(tab[dist(gen)%a]);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myBST.clearBST(); //wyczysc tablice
//                    delete[] tab;
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::findavarageinBST()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=50; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("BSTFindAvarage.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    int a=(i+1)*wielkoscstruktury;
//                    int* tab = new int [a];
//                    for(int m=0;m<a;++m)
//                        tab[i]=dist(gen)%10000;
//                    myBST.generateBST(a,tab,10000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myBST.isValueInBST(tab[dist(gen)%a]);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myBST.clearBST(); //wyczysc tablice
//                    delete[] tab;
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
//
//void pomiary::findlargeinBST()
//{
//    double PCFreq = 0.0;
//    __int64 CounterStart = 0;
//    double pomiar[pktypomiar];
//    for(int i=0;i<pktypomiar;++i)
//        pomiar[i]=0.0;
//    int wielkoscstruktury=50; // zmienna mówiaca co ile elementow ma dokonac pomiaru czasu
//    plik.open("BSTFindLarge.txt" , std::ios::out); //otworzenie pliku
//    if(plik.good())
//    {
//        for(int k=0;k<powtorzenia;++k)
//        {
//            for (int i=0;i<pktypomiar;++i)
//            {
//                for(int j=0;j<wielkoscstruktury;++j)
//                {
//                    int a=(i+1)*wielkoscstruktury;
//                    int* tab = new int [a];
//                    for(int m=0;m<a;++m)
//                        tab[i]=dist(gen)%100000;
//                    myBST.generateBST(a,tab,100000);
//                    StartCounter(); //zacznij mierzyc czas
//                    myBST.isValueInBST(tab[dist(gen)%a]);
//                    czas=GetCounter();// skoncz mierzyc czas
//                    pomiar[i]= pomiar[i]+czas; // dodaj do odpowiedniego pola w tablicy pomiarow
//                    myBST.clearBST(); //wyczysc tablice
//                    delete[] tab;
//                }
//            }
//        }
//        for(int i=0;i<pktypomiar;++i)
//            plik<<(i+1)*wielkoscstruktury<<" "<<fabs( pomiar[i]/powtorzenia)<<'\n'; // zapisz je w pliku, pamietajac o tym, ze testy byly przeprowadzane stukrotnie
//    }
//    plik.close(); //zamknij plik
//}
