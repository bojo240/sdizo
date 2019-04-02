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
#include "pomiary.h"

//Deklaracje funkcji menu
void menu_table();
void menu_list();
void menu_heap();
void menu_BST();
void pomiary2();

//Tworzenie obiektow
Table myTab;
List myList;
Heap myHeap;
BST myBST;
pomiary pomiar;

int main()
{
    srand(time(NULL));
    pomiary2();
	char option;
	do
    {
		std::cout << "\n==== MENU GLOWNE ===\n";
		std::cout << "1. Tablica\n";
		std::cout << "2. Lista\n";
		std::cout << "3. Kopiec\n";
		//std::cout << "4. Drzewo BST\n";
		std::cout << "0. Wyjscie\n";
		std::cout << "\nPodaj opcje:";
		option = getche();
		std::cout << "\n";
		switch (option)
		{
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
            break;
		}
	} while (option != '0');
	return 0;
}

void menu_table()
{
	char opt;
	std::string fileName;
	int index, value;
	do
    {
        std::cout << "\n--- TABLICA ---\n";
        std::cout << "1. Wczytaj z pliku\n";
        std::cout << "2. Usun po indeksie\n";
        std::cout << "3. Usun po wartosci\n";
        std::cout << "4. Dodaj\n";
        std::cout << "5. Znajdz\n";
        std::cout << "6. Utworz losowo\n";
        std::cout << "0. Powrot do menu\n";
        std::cout << "\nPodaj opcje:";
		opt = getche();
		std::cout << "\n";
		switch (opt)
		{
            case '1':
                std::cout << "\nPodaj nazwe zbioru:";
                std::cin >> fileName;
                myTab.loadFromFile(fileName);
                myTab.display();
                std::cout<<"\n";
                break;
            case '2':
                std::cout << "\nPodaj index:";
                std::cin >> index;
                myTab.removeIndex(index);
                myTab.display();
                break;
            case '3':
                std::cout << "\nPodaj wartosc:";
                std::cin >> value;
                myTab.removeValue(value);
                myTab.display();
                break;
            case '4':
                std::cout << "\nPodaj index:";
                std::cin >> index;
                std::cout << "\nPodaj wartosc:";
                std::cin >> value;
                myTab.addValue(value,index);
                myTab.display();
                break;
            case '5':
                std::cout << "\nPodaj wartosc:";
                std::cin >> value;
                if (myTab.isValue(value))
                    std::cout << "\nPodana wartosc jest w tablicy.\n";
                else
                    std::cout << "\nPodanej wartosci NIE ma w tablicy.\n";
                myTab.display();
                break;
            case '6':
                std::cout << "Podaj ilosc elementow tablicy:";
                std::cin >> value;
                myTab.generate(value);
                myTab.display();
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
        std::cout << "\n--- LISTA ---\n";
        std::cout << "1. Wczytaj z pliku\n";
        std::cout << "2. Usun po indeksie\n";
        std::cout << "3. Usun po wartosci\n";
        std::cout << "4. Dodaj\n";
        std::cout << "5. Znajdz\n";
        std::cout << "6. Utworz losowo\n";
        std::cout << "0. Powrot do menu\n";
        std::cout << "\nPodaj opcje:";
		opt = getche();
		std::cout << "\n";
		switch (opt)
		{
            case '1':
                std::cout << "Podaj nazwe zbioru:";
                std::cin >> fileName;
                myList.loadFromFile(fileName);
                myList.display();
                break;
            case '2':
                std::cout << "\nPodaj indeks: ";
                std::cin >> index;
                std::cout << "\n";
                myList.removeIndex(index);
                myList.display();
                break;
            case '3':
                std::cout << "\nPodaj wartosc: ";
                std::cin >> value;
                std::cout<<"\n";
                myList.removeValue(value);
                myList.display();
                break;
            case '4':
                std::cout << "\nPodaj index:\n";
                std::cin >> index;
                std::cout << "\nPodaj wartosc:";
                std::cin >> value;
                myList.addValue(value,index);
                myList.display();
                break;
            case '5':
                std::cout << "\nPodaj wartosc:";
                std::cin >> value;
                if (myList.isValue(value))
                    std::cout << "\nPodana wartosc jest w liscie.\n";
                else
                    std::cout << "\nPodanej wartosci NIE ma w liscie.\n";
                std::cout<<"\n";
                myList.display();
                break;
            case '6':
                std::cout << "\nPodaj ilosc elementow listy:";
                std::cin >> value;
                myList.generate(value);
                std::cout<<"\n";
                myList.display();
                break;
		}
	} while (opt != '0');
}

void menu_heap()
{
	char opt;
	std::string fileName;
	int value;
	do
    {
        std::cout << "\n--- KOPIEC ---\n";
        std::cout << "1. Wczytaj z pliku\n";
        std::cout << "2. Usun po wartosci\n";
        std::cout << "3. Dodaj\n";
        std::cout << "4. Znajdz\n";
        std::cout << "5. Utworz losowo\n";
        std::cout << "0. Powrot do menu\n";
        std::cout << "\nPodaj opcje:";
		opt = getche();
		std::cout << "\n";
		switch (opt)
		{
            case '1':
                std::cout << "Podaj nazwe zbioru:";
                std::cin >> fileName;
                myHeap.loadFromFile(fileName);
                myHeap.display();
                break;
            case '2':
                std::cout << "\nPodaj wartosc:";
                std::cin >> value;
                std::cout<<"\n";
                myHeap.removeValue(value);
                myHeap.display();
                break;
            case '3':
                std::cout << "\nPodaj wartosc:";
                std::cin >> value;
                myHeap.addValue(value);
                std::cout<<"\n";
                myHeap.display();
                break;
            case '4':
                std::cout << "\nPodaj wartosc:";
                std::cin >> value;
                if (myHeap.isValue(value))
                    std::cout << "\nPodana wartosc jest w kopcu.\n";
                else
                    std::cout << "\nPodanej wartosci NIE ma w kopcu.\n";
                std::cout<<"\n";
                myHeap.display();
                break;
            case '5':
                std::cout << "\nPodaj ilosc elementow kopca:";
                std::cin >> value;
                myHeap.generate(value);
                std::cout<<"\n";
                myHeap.display();
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
        std::cout << "\n--- DRZEWO PRZESZUKIWAN BINARNYCH ---\n";
        std::cout << "1. Wczytaj z pliku\n";
        std::cout << "2. Usun\n";
        std::cout << "3. Dodaj\n";
        std::cout << "4. Znajdz\n";
        std::cout << "5. Utworz losowo\n";
        std::cout << "6. Obrot w lewo\n";
    	std::cout << "7. Obrot w prawo\n";
    	std::cout << "8. DSW\n";
        std::cout << "0. Powrot do menu\n";
        std::cout << "\nPodaj opcje:";
		opt = getche();
		std::cout << "\n";
		switch (opt)
		{
            case '1':
                std::cout << "Podaj nazwe zbioru:";
                std::cin >> fileName;
                myBST.loadFromFile(fileName);
                myBST.display();
                break;
            case '2':
                std::cout << "\nPodaj wartosc:";
                std::cin >> value;
                std::cout<<"\n";
                myBST.removeValue(value);
                std::cout<<"\n";
                myBST.display();
                break;
            case '3':
                std::cout << "\nPodaj wartosc:";
                std::cin >> value;
                myBST.addValue(value);
                std::cout<<"\n";
                myBST.display();
                break;
            case '4':
                std::cout << "\nPodaj wartosc:";
                std::cin >> value;
                if (myBST.isValue(value))
                    std::cout << "\nPodana wartosc jest w BST.\n";
                else
                    std::cout << "\nPodanej wartosci NIE ma w BST.\n";
                std::cout<<"\n";
                myBST.display();
                break;
            case '5':
                std::cout << "\nPodaj ilosc elementow BST:";
                std::cin >> value;
                myBST.generate(value);
                std::cout<<"\n";
                myBST.display();
                break;
            case '6':
                std::cout << "\nPodaj wartosc elementu do obrocenia:";
                std::cin >> value;
                myBST.rotateLeft(nullptr, value);
                std::cout<<"\n";
                myBST.display();
                break;
            case '7':
                std::cout << "\nPodaj wartosc elementu do obrocenia:";
                std::cin >> value;
                myBST.rotateRight(nullptr, value);
                std::cout<<"\n";
                myBST.display();
                break;
            case '8':
                myBST.DSW();
                std::cout<<"\n";
                myBST.display();
                break;
		}
	} while (opt != '0');
}

void pomiary2()
{
//    pomiar.add(myTab, 10000, 0, 50000, "tableaddsmalltobegin.txt");
//    pomiar.add(myTab, 10000, 1, 50000, "tableaddsmalltorandom.txt");
//    pomiar.add(myTab, 10000, 2, 50000, "tableaddsmalltoend.txt");
//    pomiar.add(myTab, 1000000, 1, 50000, "tableaddlargetorandom.txt");
//    pomiar.add(myTab, 1000000, 0, 50000, "tableaddlargetobegin.txt");
//    pomiar.add(myTab, 1000000, 2, 50000, "tableaddlargetoend.txt");
//    pomiar.add(myList, 10000, 0, 20000, "listaddsmalltobegin.txt");
//    pomiar.add(myList, 10000, 1, 20000, "listaddsmalltorandom.txt");
//    pomiar.add(myList, 10000, 2, 20000, "tlistaddsmalltoend.txt");
//    pomiar.add(myList, 1000000, 0, 20000, "listaddlargetobegin.txt");
//    pomiar.add(myList, 1000000, 1, 20000, "listaddlargetorandom.txt");
//    pomiar.add(myList, 1000000, 2, 20000, "listaddlargetoend.txt");
//    pomiar.add(myHeap, 10000, 0, 2000, "heapaddsmall.txt");
//    pomiar.add(myHeap, 1000000, 0, 200, "heapaddlarge.txt");
}
