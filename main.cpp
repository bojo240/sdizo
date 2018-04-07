#include <conio.h>
#include <string>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include "Table.h"
#include "List.h"
#include "Heap.h"
#include "BST.h"
#define pktypomiar 20 //zmienna globalna okreslajaca rozdzielczosc pomiarow

//Wymagane definicje

std::chrono::high_resolution_clock::time_point start, koniec;
std::chrono::duration<double, std::milli> pomiar[pktypomiar];
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dist(1, 1000000);

//Deklaracje funkcji
void menu_table();
void menu_list();
void menu_heap();
void menu_BST();
void menu_RB();
void menu_test();
void displayMenu(std::string info);

void addtotablebegin();
void addtotablerandom();
void addtotableend();
void addtolistbegin();
void addtolistrandom();
void addtolistend();
void addtoBST();
void addtoheap();

void removefromtablebegin();
void removefromtablerandom();
void removefromtableend();
void removefromlistbegin();
void removefromlistrandom();
void removefromlistend();
void removefromheap();
void removefromBST();
//Tworzenie obiektow

Table myTab;
List myList;
Heap myHeap;
BST myBST;
//RB myRB;

//Funkcja glowna

int main()
{
    //myList.generateList(100);
    //myList.displayList();
    //for(int i=0;i<100;++i)
    //    std::cout<<myList.returnValue(i)<<'\n';
    //addtotablebegin();
    //addtotablerandom();
    //addtotableend();
    //addtolistbegin();
    //addtolistrandom();
    //addtolistend();
    //addtoheap();
    //addtoBST();
    //removefromtablebegin();
    //removefromtablerandom();
    //removefromtableend();
    //removefromlistbegin();
    //removefromlistrandom();
    //removefromlistend();
    //removefromheap();
    //removefromBST();


	char option;
	do{
		std::cout << "\n==== MENU GLOWNE ===\n";
		std::cout << "1. Tablica\n";
		std::cout << "2. Lista\n";
		std::cout << "3. Kopiec\n";
		std::cout << "4. Drzewo BST\n";
//		std::cout << "5.Drzewo RB\n";
		std::cout << "0. Wyjscie\n";
		std::cout << "\nPodaj opcje:";
		option = getche();
		std::cout << "\n";

		switch (option){
		case '1':
			menu_table();
			break;

		case '2':
			menu_list();
			break;

		case '3':
			menu_heap();
			break;
        case '4':
            menu_BST();
            break;
//        case '5':
//            menu_RB();
//            break;
        break;
		}

	} while (option != '0');


	return 0;
}

//definicje funkcji menu

void displayMenu(std::string info)
{
	std::cout << "\n";
	std::cout << info;
	std::cout << "\n1. Wczytaj z pliku\n";
	std::cout << "2. Usun\n";
	std::cout << "3. Dodaj\n";
	std::cout << "4. Znajdz\n";
	std::cout << "5. Utworz losowo\n";
	std::cout << "6. Wyswietl\n";
	std::cout << "7. Test (pomiary)\n";
	std::cout << "0. Powrot do menu\n";
	std::cout << "\nPodaj opcje:";
}

void menu_table()
{
	char opt;
	std::string fileName;
	int index, value;


	do{
		displayMenu("--- TABLICA ---");
		opt = getche();
		std::cout << "\n";
		switch (opt){
		case '1':
			std::cout << "\nPodaj nazwe zbioru:";
			std::cin >> fileName;
			myTab.loadFromFileToTable(fileName);
			myTab.displayTable();
			std::cout<<"\n";
			break;

		case '2':
			std::cout << "\nPodaj index:";
			std::cin >> index;
			myTab.deleteFromTable(index);
			myTab.displayTable();
			break;

		case '3':
			std::cout << "\nPodaj index:";
			std::cin >> index;
			std::cout << "\nPodaj wartosc:";
			std::cin >> value;
			myTab.addValueToTable(index,value);
			myTab.displayTable();
			break;

		case '4':
			std::cout << "\nPodaj wartosc:";
			std::cin >> value;
			if (myTab.isValueInTable(value))
				std::cout << "\nPodana wartosc jest w tablicy.\n";
			else
				std::cout << "\nPodanej wartosci NIE ma w tablicy.\n";
            myTab.displayTable();
			break;

		case '5':
			std::cout << "Podaj ilosc elementow tablicy:";
			std::cin >> value;
			myTab.generateTable(value);
			myTab.displayTable();
			break;

		case '6':
			myTab.displayTable();
			break;

		case '7':
                std::cout<<"\n1. Dodaj na poczatek\n";
                std::cout<<"2. Dodaj na srodek\n";
                std::cout<<"3. Dodaj na koniec\n";
                std::cout << "0. Powrot do menu\n";
                std::cout << "\nPodaj opcje:";
                char mode = getche();
                std::cout<<'\n';
                switch(mode)
                {
                case '1':
                    addtotablebegin();
                    std::cout<<"\n\nZadanie Wykonane!\n\n";
                    break;
                case '2':
                    addtotablebegin();
                    std::cout<<"\n\nZadanie Wykonane!\n\n";
                    break;
                case '3':
                    addtotablebegin();
                    std::cout<<"\n\nZadanie Wykonane!\n\n";
                    break;
                }
			break;
		}

	} while (opt != '0');
}

void menu_list()
{
	char opt;
	std::string fileName;
	int index, value;


	do{
		displayMenu("--- LISTA ---");
		opt = getche();
		std::cout << "\n";
		switch (opt){
		case '1':
			std::cout << "Podaj nazwe zbioru:";
			std::cin >> fileName;
			myList.loadFromFileToList(fileName);
			myList.displayList();
			break;

		case '2':
			std::cout << "\nPodaj wartosc:";
			std::cin >> value;
            std::cout<<"\n";
			myList.deleteFromList(value);
			myList.displayList();
			break;

		case '3':
			std::cout << "\nPodaj index:\n";
			std::cin >> index;
			std::cout << "\nPodaj wartosc:";
			std::cin >> value;

			myList.addValueToList(index,value);
			myList.displayList();
			break;

		case '4':
			std::cout << "\nPodaj wartosc:";
			std::cin >> value;
			if (myList.isValueInList(value))
				std::cout << "\nPodana wartosc jest w liscie.\n";
			else
				std::cout << "\nPodanej wartosci NIE ma w liscie.\n";
            std::cout<<"\n";
            myList.displayList();
			break;

		case '5':
			std::cout << "\nPodaj ilosc elementow listy:";
			std::cin >> value;
			myList.generateList(value);
			std::cout<<"\n";
			myList.displayList();
			break;

		case '6':
			myList.displayList();
			break;

		case '7':

            std::cout<<"\n1. Dodaj na poczatek\n";
            std::cout<<"2. Dodaj na srodek\n";
            std::cout<<"3. Dodaj na koniec\n";
            std::cout << "0. Powrot do menu\n";
            std::cout << "\nPodaj opcje:";
            char mode = getche();
            switch(mode)
            {
            case '1':
                addtolistbegin();
                std::cout<<"\n\nZadanie Wykonane!\n\n";
                break;
            case '2':
                addtolistbegin();
                std::cout<<"\n\nZadanie Wykonane!\n\n";
                break;
            case '3':
                addtolistbegin();
                std::cout<<"\n\nZadanie Wykonane!\n\n";
                break;
            }
			break;
		}

	} while (opt != '0');
}

void menu_heap()
{
	char opt;
	std::string fileName;
	int value;
	do{
		displayMenu("--- KOPIEC ---");
		opt = getche();
		std::cout << "\n";
		switch (opt){
		case '1':
			std::cout << "Podaj nazwe zbioru:";
			std::cin >> fileName;
			myHeap.loadFromFileToHeap(fileName);
			myHeap.displayHeap();
			break;

		case '2':
			std::cout << "\nPodaj wartosc:";
			std::cin >> value;
            std::cout<<"\n";
			myHeap.deleteFromHeap(value);
			myHeap.displayHeap();
			break;

		case '3':
			std::cout << "\nPodaj wartosc:";
			std::cin >> value;
			myHeap.addNodeToHeap(value);
			std::cout<<"\n";
			myHeap.displayHeap();
			break;

		case '4':
			std::cout << "\nPodaj wartosc:";
			std::cin >> value;
			if (myHeap.isValueInHeap(value))
				std::cout << "\nPodana wartosc jest w kopcu.\n";
			else
				std::cout << "\nPodanej wartosci NIE ma w kopcu.\n";
            std::cout<<"\n";
            myHeap.displayHeap();
			break;

		case '5':
			std::cout << "\nPodaj ilosc elementow kopca:";
			std::cin >> value;
			myHeap.generateHeap(value);
			std::cout<<"\n";
			myHeap.displayHeap();
			break;

		case '6':
			myHeap.displayHeap();
			break;

		case '7':
            addtoheap();
            std::cout<<"\n\nZadanie Wykonane!\n\n";
			break;
		}

	} while (opt != '0');
}

void menu_BST()
{
	char opt;
	std::string fileName;
	int value;
	do{
		displayMenu("--- BST ---");
		opt = getche();
		std::cout << "\n";
		switch (opt)
		{
            case '1':
                std::cout << "Podaj nazwe zbioru:";
                std::cin >> fileName;
                myBST.loadFromFileToBST(fileName);
                myBST.displayBST();
                break;

            case '2':
                std::cout << "\nPodaj wartosc:";
                std::cin >> value;
                std::cout<<"\n";
                myBST.deleteFromBST(value);
                std::cout<<"\n";
                myBST.displayBST();
                break;

            case '3':
                std::cout << "\nPodaj wartosc:";
                std::cin >> value;
                myBST.addNodeToBST(value);
                std::cout<<"\n";
                myBST.displayBST();
                break;

            case '4':
                std::cout << "\nPodaj wartosc:";
                std::cin >> value;
                if (myBST.isValueInBST(value))
                    std::cout << "\nPodana wartosc jest w BST.\n";
                else
                    std::cout << "\nPodanej wartosci NIE ma w BST.\n";
                std::cout<<"\n";
                myBST.displayBST();
                break;

            case '5':
                std::cout << "\nPodaj ilosc elementow BST:";
                std::cin >> value;
                myBST.generateBST(value);
                std::cout<<"\n";
                myBST.displayBST();
                break;

            case '6':
                myBST.displayBST();
                break;

            case '7':
                addtoBST();
                std::cout<<"\n\nZadanie Wykonane!\n\n";
                break;
		}

	} while (opt != '0');
}

//definicje funkcji testujacych

int iloscpomiarow;

void addtotablebegin()
{
    iloscpomiarow=1000;
    for(int i=0;i<pktypomiar;++i)
        pomiar[pktypomiar]=std::chrono::nanoseconds::zero();
    std::fstream plik;
    plik.open("TableAddBeginning.txt" , std::ios::out);
    if(plik.good())
    {
        for(int k=0;k<100;++k)
        {
            for (int i=0;i<pktypomiar;++i)
            {
                start=std::chrono::high_resolution_clock::now();
                for (int j=0;j<iloscpomiarow;++j)
                    myTab.addValueToTable(0,dist(gen));
                koniec=std::chrono::high_resolution_clock::now();
                pomiar[i]= pomiar[i]+(koniec-start);
            }
            myTab.clearTable();
        }
        for (int i=1;i<pktypomiar;++i)
            pomiar[i]+=pomiar[i-1];
        for(int i=0;i<pktypomiar;++i)
            plik<<(i+1)*iloscpomiarow<<" "<<pomiar[i].count()/100<<'\n';
    }
    plik.close();
}

void addtotablerandom()
{
    iloscpomiarow = 1000;
    for(int i=0;i<pktypomiar;++i)
        pomiar[pktypomiar]=std::chrono::nanoseconds::zero();
    std::fstream plik;
    plik.open("TableAddRandom.txt" , std::ios::out);
    if(plik.good())
    {
        for(int k=0;k<100;++k)
        {
            for (int i=0;i<pktypomiar;++i)
            {
                start=std::chrono::high_resolution_clock::now();
                for (int j=1;j<iloscpomiarow;++j)
                    myTab.addValueToTable(dist(gen)%(myTab.cnt+1),dist(gen));
                koniec=std::chrono::high_resolution_clock::now();
                pomiar[i]= pomiar[i]+(koniec-start);
            }
            myTab.clearTable();
        }
        for (int i=1;i<pktypomiar;++i)
            pomiar[i]+=pomiar[i-1];
        for(int i=0;i<pktypomiar;++i)
            plik<<(i+1)*iloscpomiarow<<" "<<pomiar[i].count()/100<<'\n';
    }
    plik.close();
}

void addtotableend()
{
    iloscpomiarow = 1000;
    for(int i=0;i<pktypomiar;++i)
        pomiar[pktypomiar]=std::chrono::nanoseconds::zero();
    std::fstream plik;
    plik.open("TableAddEnd.txt" , std::ios::out);
    if(plik.good())
    {
        for(int k=0;k<100;++k)
        {
            for (int i=0;i<pktypomiar;++i)
            {
                start=std::chrono::high_resolution_clock::now();
                for (int j=1;j<iloscpomiarow;++j)
                    myTab.addValueToTable(myTab.cnt,dist(gen));
                koniec=std::chrono::high_resolution_clock::now();
                pomiar[i]= pomiar[i]+(koniec-start);
            }
            myTab.clearTable();
        }
        for (int i=1;i<pktypomiar;++i)
            pomiar[i]+=pomiar[i-1];
        for(int i=0;i<pktypomiar;++i)
            plik<<(i+1)*iloscpomiarow<<" "<<pomiar[i].count()/100<<'\n';
    }
    plik.close();
}

void addtolistbegin()
{
    iloscpomiarow = 200000;
    for(int i=0;i<pktypomiar;++i)
        pomiar[pktypomiar]=std::chrono::nanoseconds::zero();
    std::fstream plik;
    plik.open("ListAddBeginning.txt" , std::ios::out);
    if(plik.good())
    {
        for(int k=0;k<100;++k)
        {
            for (int i=0;i<pktypomiar;++i)
            {
                start=std::chrono::high_resolution_clock::now();
                for (int j=0;j<iloscpomiarow;++j)
                    myList.addValueToList(0,dist(gen));
                koniec=std::chrono::high_resolution_clock::now();
                pomiar[i]= pomiar[i]+(koniec-start);
            }
            myList.clearList();
        }
        for (int i=1;i<pktypomiar;++i)
            pomiar[i]+=pomiar[i-1];
        for(int i=0;i<pktypomiar;++i)
            plik<<(i+1)*iloscpomiarow<<" "<<pomiar[i].count()/100<<'\n';
    }
    plik.close();
}

void addtolistrandom()
{
    iloscpomiarow = 1200;
    for(int i=0;i<pktypomiar;++i)
        pomiar[pktypomiar]=std::chrono::nanoseconds::zero();
    std::fstream plik;
    plik.open("ListAddRandom.txt" , std::ios::out);
    if(plik.good())
    {
        for(int k=0;k<100;++k)
        {
            for (int i=0;i<pktypomiar;++i)
            {
                start=std::chrono::high_resolution_clock::now();
                for (int j=0;j<iloscpomiarow;++j)
                {

                    myList.addValueToList(rand()%(myList.cnt+1),rand());
                }
                koniec=std::chrono::high_resolution_clock::now();
                pomiar[i]= pomiar[i]+(koniec-start);
            }
            myList.clearList();
        }
        for (int i=1;i<pktypomiar;++i)
            pomiar[i]+=pomiar[i-1];
        for(int i=0;i<pktypomiar;++i)
            plik<<(i+1)*iloscpomiarow<<" "<<pomiar[i].count()/100<<'\n';
    }
    plik.close();
}

void addtolistend()
{
    iloscpomiarow = 200000;
    for(int i=0;i<pktypomiar;++i)
        pomiar[pktypomiar]=std::chrono::nanoseconds::zero();
    std::fstream plik;
    plik.open("ListAddEnding.txt" , std::ios::out);
    if(plik.good())
    {
        for(int k=0;k<100;++k)
        {
            for (int i=0;i<pktypomiar;++i)
            {
                start=std::chrono::high_resolution_clock::now();
                for (int j=0;j<iloscpomiarow;++j)
                    myList.addValueToList(myList.cnt, dist(gen));
                koniec=std::chrono::high_resolution_clock::now();
                pomiar[i]= pomiar[i]+(koniec-start);
            }
            myList.clearList();
        }
        for (int i=1;i<pktypomiar;++i)
            pomiar[i]+=pomiar[i-1];
        for(int i=0;i<pktypomiar;++i)
            plik<<(i+1)*iloscpomiarow<<" "<<pomiar[i].count()/100<<'\n';
    }
    plik.close();
}

void addtoheap()
{
    iloscpomiarow = 300000;
    for(int i=0;i<pktypomiar;++i)
        pomiar[pktypomiar]=std::chrono::nanoseconds::zero();
    std::fstream plik;
    plik.open("HeapAdd.txt" , std::ios::out);
    if(plik.good())
    {
        for(int k=0;k<100;++k)
        {
            for (int i=0;i<pktypomiar;++i)
            {
                start=std::chrono::high_resolution_clock::now();
                for (int j=0;j<iloscpomiarow;++j)
                    myHeap.addNodeToHeap(dist(gen));
                koniec=std::chrono::high_resolution_clock::now();
                pomiar[i]= pomiar[i]+(koniec-start);
            }
            myHeap.clearHeap();
        }
        for (int i=1;i<pktypomiar;++i)
            pomiar[i]+=pomiar[i-1];
        for(int i=0;i<pktypomiar;++i)
            plik<<(i+1)*iloscpomiarow<<" "<<pomiar[i].count()/100<<'\n';
    }
    plik.close();
}

void addtoBST()
{
    iloscpomiarow = 300;
    for(int i=0;i<pktypomiar;++i)
        pomiar[pktypomiar]=std::chrono::nanoseconds::zero();
    std::fstream plik;
    plik.open("BSTAdd.txt" , std::ios::out);
    if(plik.good())
    {
        for(int k=0;k<100;++k)
        {
            for (int i=0;i<pktypomiar;++i)
            {
                start=std::chrono::high_resolution_clock::now();
                for (int j=0;j<iloscpomiarow;++j)
                    myBST.addNodeToBST(dist(gen));
                koniec=std::chrono::high_resolution_clock::now();
                pomiar[i]= pomiar[i]+(koniec-start);
            }
            myBST.clearBST();
        }
        for (int i=1;i<pktypomiar;++i)
            pomiar[i]+=pomiar[i-1];
        for(int i=0;i<pktypomiar;++i)
            plik<<(i+1)*iloscpomiarow<<" "<<pomiar[i].count()/100<<'\n';
    }
    plik.close();
}

void removefromtablebegin()
{
    iloscpomiarow = 1000;
    for(int i=0;i<pktypomiar;++i)
        pomiar[pktypomiar]=std::chrono::nanoseconds::zero();
    std::fstream plik;
    plik.open("TableRemoveBegin.txt" , std::ios::out);
    if(plik.good())
    {
        for(int k=0;k<100;++k)
        {
            myTab.generateTable(pktypomiar*iloscpomiarow);
            for (int i=0;i<pktypomiar;++i)
            {
                start=std::chrono::high_resolution_clock::now();
                for (int j=0;j<iloscpomiarow;++j)
                    myTab.deleteFromTable(0);
                koniec=std::chrono::high_resolution_clock::now();
                pomiar[i]= pomiar[i]+(koniec-start);
            }
            myTab.clearTable();
        }
        for (int i=1;i<pktypomiar;++i)
            pomiar[i]+=pomiar[i-1];
        for(int i=0;i<pktypomiar;++i)
            plik<<(i+1)*iloscpomiarow<<" "<<pomiar[i].count()/100<<'\n';
    }
    plik.close();
}

void removefromtablerandom()
{
    iloscpomiarow = 1000;
    for(int i=0;i<pktypomiar;++i)
        pomiar[pktypomiar]=std::chrono::nanoseconds::zero();
    std::fstream plik;
    plik.open("TableRemoveRandom.txt" , std::ios::out);
    if(plik.good())
    {
        for(int k=0;k<100;++k)
        {
            myTab.generateTable(pktypomiar*iloscpomiarow);
            for (int i=0;i<pktypomiar;++i)
            {
                start=std::chrono::high_resolution_clock::now();
                for (int j=0;j<iloscpomiarow;++j)
                    myTab.deleteFromTable(dist(gen)%myTab.cnt);
                koniec=std::chrono::high_resolution_clock::now();
                pomiar[i]= pomiar[i]+(koniec-start);
            }
            myTab.clearTable();
        }
        for (int i=1;i<pktypomiar;++i)
            pomiar[i]+=pomiar[i-1];
        for(int i=0;i<pktypomiar;++i)
            plik<<(i+1)*iloscpomiarow<<" "<<pomiar[i].count()/100<<'\n';
    }
    plik.close();
}

void removefromtableend()
{
    iloscpomiarow = 1000;
    for(int i=0;i<pktypomiar;++i)
        pomiar[pktypomiar]=std::chrono::nanoseconds::zero();
    std::fstream plik;
    plik.open("TableRemoveEnd.txt" , std::ios::out);
    if(plik.good())
    {
        for(int k=0;k<100;++k)
        {
            myTab.generateTable(pktypomiar*iloscpomiarow);
            for (int i=0;i<pktypomiar;++i)
            {
                start=std::chrono::high_resolution_clock::now();
                for (int j=0;j<iloscpomiarow;++j)
                    myTab.deleteFromTable(myTab.cnt-1);
                koniec=std::chrono::high_resolution_clock::now();
                pomiar[i]= pomiar[i]+(koniec-start);
            }
            myTab.clearTable();
        }
        for (int i=1;i<pktypomiar;++i)
            pomiar[i]+=pomiar[i-1];
        for(int i=0;i<pktypomiar;++i)
            plik<<(i+1)*iloscpomiarow<<" "<<pomiar[i].count()/100<<'\n';
    }
    plik.close();
}

void removefromlistbegin()
{
    iloscpomiarow = 1000;
    for(int i=0;i<pktypomiar;++i)
        pomiar[pktypomiar]=std::chrono::nanoseconds::zero();
    std::fstream plik;
    plik.open("ListRemoveBegin.txt" , std::ios::out);
    if(plik.good())
    {
        for(int k=0;k<100;++k)
        {
            myList.generateList(pktypomiar*iloscpomiarow);
            for (int i=0;i<pktypomiar;++i)
            {
                start=std::chrono::high_resolution_clock::now();
                for (int j=0;j<iloscpomiarow;++j)
                    myList.deleteFromList(myList.returnValue(0),true);
                koniec=std::chrono::high_resolution_clock::now();
                pomiar[i]= pomiar[i]+(koniec-start);
            }
            myList.clearList();
        }
        for (int i=1;i<pktypomiar;++i)
            pomiar[i]+=pomiar[i-1];
        for(int i=0;i<pktypomiar;++i)
            plik<<(i+1)*iloscpomiarow<<" "<<pomiar[i].count()/100<<'\n';
    }
    plik.close();
}

void removefromlistrandom()
{
    iloscpomiarow = 100;
    for(int i=0;i<pktypomiar;++i)
        pomiar[pktypomiar]=std::chrono::nanoseconds::zero();
    std::fstream plik;
    plik.open("ListRemoveRandom.txt" , std::ios::out);
    if(plik.good())
    {
        for(int k=0;k<100;++k)
        {

            myList.generateList(pktypomiar*iloscpomiarow);
            for (int i=0;i<pktypomiar;++i)
            {
                start=std::chrono::high_resolution_clock::now();
                for (int j=0;j<iloscpomiarow;++j)
                    myList.deleteFromList(myList.returnValue(dist(gen)%myList.cnt),true);
                koniec=std::chrono::high_resolution_clock::now();
                pomiar[i]= pomiar[i]+(koniec-start);
            }
            myList.clearList();
        }
        for (int i=1;i<pktypomiar;++i)
            pomiar[i]+=pomiar[i-1];
        for(int i=0;i<pktypomiar;++i)
            plik<<(i+1)*iloscpomiarow<<" "<<pomiar[i].count()/100<<'\n';
    }
    plik.close();
}

void removefromlistend()
{
    iloscpomiarow = 100;
    for(int i=0;i<pktypomiar;++i)
        pomiar[pktypomiar]=std::chrono::nanoseconds::zero();
    std::fstream plik;
    plik.open("ListRemoveEnd.txt" , std::ios::out);
    if(plik.good())
    {
        for(int k=0;k<100;++k)
        {
            myList.generateList(pktypomiar*iloscpomiarow);
            for (int i=0;i<pktypomiar;++i)
            {
                start=std::chrono::high_resolution_clock::now();
                for (int j=0;j<iloscpomiarow;++j)
                    myList.deleteFromList(myList.cnt-1,true);
                koniec=std::chrono::high_resolution_clock::now();
                pomiar[i]= pomiar[i]+(koniec-start);
            }
            myList.clearList();
        }
        for (int i=1;i<pktypomiar;++i)
            pomiar[i]+=pomiar[i-1];
        for(int i=0;i<pktypomiar;++i)
            plik<<(i+1)*iloscpomiarow<<" "<<pomiar[i].count()/100<<'\n';
    }
    plik.close();
}

void removefromheap()
{
    iloscpomiarow = 1000;
    for(int i=0;i<pktypomiar;++i)
        pomiar[pktypomiar]=std::chrono::nanoseconds::zero();
    std::fstream plik;
    plik.open("HeapRemove.txt" , std::ios::out);
    if(plik.good())
    {
        for(int k=0;k<100;++k)
        {
            myHeap.generateHeap(pktypomiar*iloscpomiarow);
            for (int i=0;i<pktypomiar;++i)
            {
                start=std::chrono::high_resolution_clock::now();
                for (int j=0;j<iloscpomiarow;++j)
                    myHeap.deleteFromHeap(myHeap.returnValueOfRoot(), true);
                koniec=std::chrono::high_resolution_clock::now();
                pomiar[i]= pomiar[i]+(koniec-start);
            }
            myHeap.clearHeap();
        }
        for (int i=1;i<pktypomiar;++i)
            pomiar[i]+=pomiar[i-1];
        for(int i=0;i<pktypomiar;++i)
            plik<<(i+1)*iloscpomiarow<<" "<<pomiar[i].count()/100<<'\n';
    }
    plik.close();
}

void removefromBST()
{
    iloscpomiarow = 100;
    for(int i=0;i<pktypomiar;++i)
        pomiar[pktypomiar]=std::chrono::nanoseconds::zero();
    std::fstream plik;
    plik.open("BSTRemove.txt" , std::ios::out);
    if(plik.good())
    {
        for(int k=0;k<100;++k)
        {
            myBST.generateBST(pktypomiar*iloscpomiarow);
            for (int i=0;i<pktypomiar;++i)
            {
                start=std::chrono::high_resolution_clock::now();
                for (int j=0;j<iloscpomiarow;++j)
                    myBST.deleteFromBST(myBST.returnValueOfRoot(), true);
                koniec=std::chrono::high_resolution_clock::now();
                pomiar[i]= pomiar[i]+(koniec-start);
            }
            myBST.clearBST();
        }
        for (int i=1;i<pktypomiar;++i)
            pomiar[i]+=pomiar[i-1];
        for(int i=0;i<pktypomiar;++i)
            plik<<(i+1)*iloscpomiarow<<" "<<pomiar[i].count()/100<<'\n';
    }
    plik.close();
}

//void menu_RB()
//{
//	char opt;
//	std::string fileName;
//	int value;
//	do{
//		displayMenu("--- RB ---");
//		opt = getche();
//		std::cout << "\n";
//		switch (opt){
//		case '1': //tutaj wczytywanie RB z pliku
//			std::cout << "Podaj nazwe zbioru:";
//			std::cin >> fileName;
//			myRB.loadFromFileToRB(fileName);
//			myRB.displayRB();
//			break;
//
//		case '2': //tutaj usuwanie elementu z RB
//			std::cout << "\nPodaj wartosc:";
//			std::cin >> value;
//            std::cout<<"\n";
//			myRB.deleteFromRB(value);
//			std::cout<<"\n";
//			myRB.displayRB();
//			break;
//
//		case '3': //tutaj dodawanie elementu do RB
//			std::cout << "\nPodaj wartosc:";
//			std::cin >> value;
//			myRB.addNodeToRB(value);
//			std::cout<<"\n";
//			myRB.displayRB();
//			break;
//
//		case '4': //tutaj znajdowanie elementu w RB
//			std::cout << "\nPodaj wartosc:";
//			std::cin >> value;
//			if (myRB.isValueInRB(value))
//				std::cout << "\nPodana wartosc jest w RB.\n";
//			else
//				std::cout << "\nPodanej wartosci NIE ma w RB.\n";
//            std::cout<<"\n";
//			myRB.displayRB();
//			break;
//
//		case '5':  //tutaj generowanie  RB
//			std::cout << "\nPodaj ilosc elementow RB:";
//			std::cin >> value;
//			myRB.generateRB(value);
//			std::cout<<"\n";
//			myRB.displayRB();
//			break;
//
//		case '6':  //tutaj wyœwietlanie RB
//			myRB.displayRB();
//			break;
//
//		case '7': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie bêdzie testowana przez prowadz¹cego
//                    // mo¿na sobie tu dodaæ w³asne case'y
//            break;
//		}
//
//	} while (opt != '0');
//}
