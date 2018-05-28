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
    pomiary();

//	char option;
//	do{
//		std::cout << "\n==== MENU GLOWNE ===\n";
//		std::cout << "1. Tablica\n";
//		std::cout << "2. Lista\n";
//		std::cout << "3. Kopiec\n";
//		std::cout << "4. Drzewo BST\n";
//		std::cout << "0. Wyjscie\n";
//		std::cout << "\nPodaj opcje:";
//		option = getche();
//		std::cout << "\n";
//
//		switch (option){
//		case '1':
//			menu_table();
//			break;
//
//		case '2':
//			menu_list();
//			break;
//
//		case '3':
//			menu_heap();
//			break;
//        case '4':
//            menu_BST();
//            break;
//        break;
//		}
//
//	} while (option != '0');


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
                std::cout << "\nPodaj wartosc elementu do obrocenia:";
                std::cin >> value;
                myBST.menuRotateLeft(value);
                std::cout<<"\n";
                myBST.displayBST();
                break;
            case '8':
                std::cout << "\nPodaj wartosc elementu do obrocenia:";
                std::cin >> value;
                myBST.menuRotateRight(value);
                std::cout<<"\n";
                myBST.displayBST();
                break;
            case '9':
                myBST.DSW();
                std::cout<<"\n";
                myBST.displayBST();
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
////    pomiar.removesmallfromtablebegin();
////    pomiar.removeaveragefromtablebegin();
////    pomiar.removelargefromtablebegin();
////    pomiar.removesmallfromtablerandom();
////    pomiar.removeaveragefromtablerandom();
////    pomiar.removelargefromtablerandom();
//    pomiar.removesmallfromtableend();
//    pomiar.removeaveragefromtableend();
//    pomiar.removelargefromtableend();
////    pomiar.removesmallfromlistbegin();
////    pomiar.removeaveragefromlistbegin();
////    pomiar.removelargefromlistbegin();
////    pomiar.removesmallfromlistrandom();
////    pomiar.removeaveragefromlistrandom();
////    pomiar.removelargefromlistrandom();
//    pomiar.removesmallfromlistend();
//    pomiar.removeaveragefromlistend();
//    pomiar.removelargefromlistend();
////    pomiar.removesmallfromheap();
////    pomiar.removeaveragefromheap();
////    pomiar.removelargefromheap();
////    pomiar.removesmallfromBST();
////    pomiar.removeaveragefromBST();
////    pomiar.removelargefromBST();
////    pomiar.removesmallfromBST_DSW();
////    pomiar.removeaveragefromBST_DSW();
////    pomiar.removelargefromBST_DSW();
    pomiar.findsmallintable();
    pomiar.findavarageintable();
    pomiar.findlargeintable();
    pomiar.findsmallinlist();
    pomiar.findavarageinlist();
    pomiar.findlargeinlist();
    pomiar.findsmallinheap();
    pomiar.findavarageinheap();
    pomiar.findlargeinheap();
    pomiar.findsmallinBST();
    pomiar.findavarageinBST();
    pomiar.findlargeinBST();
}
