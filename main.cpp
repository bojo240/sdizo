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
void menu_RB();
void menu_test();
void displayMenu(std::string info);

//Tworzenie obiektowa
Table myTab;
List myList;
Heap myHeap;
BST myBST;
pomiary pomiar;
//Funkcja glowna
void pomiary();

int main()
{
    //pomiary();

	char option;
	do{
		std::cout << "\n==== MENU GLOWNE ===\n";
		std::cout << "1. Tablica\n";
		std::cout << "2. Lista\n";
		std::cout << "3. Kopiec\n";
		std::cout << "4. Drzewo BST\n";
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
			myTab.remove(index);
			myTab.display();
			break;

		case '3':
			std::cout << "\nPodaj index:";
			std::cin >> index;
			std::cout << "\nPodaj wartosc:";
			std::cin >> value;
			myTab.addValue(index,value);
			myTab.display();
			break;

		case '4':
			std::cout << "\nPodaj wartosc:";
			std::cin >> value;
			if (myTab.isValue(value))
				std::cout << "\nPodana wartosc jest w tablicy.\n";
			else
				std::cout << "\nPodanej wartosci NIE ma w tablicy.\n";
            myTab.display();
			break;

		case '5':
			std::cout << "Podaj ilosc elementow tablicy:";
			std::cin >> value;
			myTab.generate(value);
			myTab.display();
			break;

		case '6':
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
		displayMenu("--- LISTA ---");
		opt = getche();
		std::cout << "\n";
		switch (opt){
		case '1':
			std::cout << "Podaj nazwe zbioru:";
			std::cin >> fileName;
			myList.loadFromFile(fileName);
			myList.display();
			break;
		case '2':
			std::cout << "\nPodaj wartosc: ";
			std::cin >> value;
            std::cout<<"\n";
			myList.remove(value);
			myList.display();
			break;
		case '3':
			std::cout << "\nPodaj index:\n";
			std::cin >> index;
			std::cout << "\nPodaj wartosc:";
			std::cin >> value;
			myList.addValue(index,value);
			myList.display();
			break;
		case '4':
			std::cout << "\nPodaj wartosc:";
			std::cin >> value;
			if (myList.isValue(value))
				std::cout << "\nPodana wartosc jest w liscie.\n";
			else
				std::cout << "\nPodanej wartosci NIE ma w liscie.\n";
            std::cout<<"\n";
            myList.display();
			break;
		case '5':
			std::cout << "\nPodaj ilosc elementow listy:";
			std::cin >> value;
			myList.generate(value);
			std::cout<<"\n";
			myList.display();
			break;
		case '6':
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
	do{
		displayMenu("--- KOPIEC ---");
		opt = getche();
		std::cout << "\n";
		switch (opt){
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
			myHeap.remove(value);
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
		case '6':
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
        std::cout << "\n1. Wczytaj z pliku\n";
        std::cout << "2. Usun\n";
        std::cout << "3. Dodaj\n";
        std::cout << "4. Znajdz\n";
        std::cout << "5. Utworz losowo\n";
        std::cout << "6. Wyswietl\n";
        std::cout << "7. Obrot w lewo\n";
    	std::cout << "8. Obrot w prawo\n";
    	std::cout << "9. DSW\n";
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
                myBST.remove(value);
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
                myBST.display();
                break;
            case '7':
                std::cout << "\nPodaj wartosc elementu do obrocenia:";
                std::cin >> value;
                myBST.rotateLeft(nullptr, value);
                std::cout<<"\n";
                myBST.display();
                break;
            case '8':
                std::cout << "\nPodaj wartosc elementu do obrocenia:";
                std::cin >> value;
                myBST.rotateRight(nullptr, value);
                std::cout<<"\n";
                myBST.display();
                break;
            case '9':
                myBST.DSW();
                std::cout<<"\n";
                myBST.display();
                break;
		}
	} while (opt != '0');
}

void pomiary()
{
////    pomiar.addsmalltotablebegin();
////    pomiar.addaveragetotablebegin();
////    pomiar.addlargetotablebegin();
//    pomiar.addsmalltotablerandom();
//    pomiar.addaveragetotablerandom();
//    pomiar.addlargetotablerandom();
////    pomiar.addsmalltotableend();
////    pomiar.addaveragetotableend();
////    pomiar.addlargetotableend();
////    pomiar.addsmalltolistbegin();
////    pomiar.addaveragetolistbegin();
////    pomiar.addlargetolistbegin();
//    pomiar.addsmalltolistrandom();
//    pomiar.addaveragetolistrandom();
//    pomiar.addlargetolistrandom();
////    pomiar.addsmalltolistend();
////    pomiar.addaveragetolistend();
////    pomiar.addlargetolistend();
////    pomiar.addsmalltoheap();
////    pomiar.addaveragetoheap();
////    pomiar.addlargetoheap();
////    pomiar.addsmalltoBST();
////    pomiar.addaveragetoBST();
////    pomiar.addlargetoBST();
//    pomiar.addsmalltoBST_DSW();
//    pomiar.addaveragetoBST_DSW();
//    pomiar.addlargetoBST_DSW();
//    pomiar.removesmallfromtablebegin();
//    pomiar.removeaveragefromtablebegin();
//    pomiar.removelargefromtablebegin();
//    pomiar.removesmallfromtablerandom();
//    pomiar.removeaveragefromtablerandom();
//    pomiar.removelargefromtablerandom();
//    pomiar.removesmallfromtableend();
//    pomiar.removeaveragefromtableend();
//    pomiar.removelargefromtableend();
//    pomiar.removesmallfromlistbegin();
//    pomiar.removeaveragefromlistbegin();
//    pomiar.removelargefromlistbegin();
//    pomiar.removesmallfromlistrandom();
//    pomiar.removeaveragefromlistrandom();
//    pomiar.removelargefromlistrandom();
//    pomiar.removesmallfromlistend();
//    pomiar.removeaveragefromlistend();
//   pomiar.removelargefromlistend();
//    pomiar.removesmallfromheap();
//    pomiar.removeaveragefromheap();
//    pomiar.removelargefromheap();
//    pomiar.removesmallfromBST();
//    pomiar.removeaveragefromBST();
//    pomiar.removelargefromBST();
//    pomiar.removesmallfromBST_DSW();
//    pomiar.removeaveragefromBST_DSW();
//    pomiar.removelargefromBST_DSW();
//    pomiar.findsmallintable();
//    pomiar.findavarageintable();
//    pomiar.findlargeintable();
//    pomiar.findsmallinlist();
//    pomiar.findavarageinlist();
//    pomiar.findlargeinlist();
//    pomiar.findsmallinheap();
//    pomiar.findavarageinheap();
//    pomiar.findlargeinheap();
//    pomiar.findsmallinBST();
//    pomiar.findavarageinBST();
//    pomiar.findlargeinBST();
}
