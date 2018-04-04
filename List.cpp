#include "List.h"
#include <iostream>
#include <fstream>
#include <random>

Elements::Elements() : Value(0), Next(nullptr), Prev(nullptr) {;} //konstruktor / lista inicjalizacyjna

List::List() : Head (nullptr), Tail(nullptr), cnt(0) {;} //konstruktor / lista inicjalizacyjna

void List::addValueToList(int index, int value) //najpierw przechodze po liscie w wybrane miejsce, dopiero pozniej dodaje tam wartosc.
{

    if (!Head) //jezeli nie ma head
	{
		Head = new Elements;
		Head->Value = value;
		Tail = Head;
		++cnt;
	}
	else if (index == 0) //jezeli dodaje na poczatek
	{
		Elements *Temp = Head;
		Temp->Prev = new Elements;
		Temp=Temp->Prev;
		Temp->Value = value;
		Temp->Next = Head;
		Head = Temp;
		++cnt;
	}
	else if (index == cnt) //jezeli dodaje na koniec
	{
		Elements *Temp = Tail;
		Temp->Next = new Elements;
		Temp = Temp->Next;
		Temp->Prev = Tail;
		Temp->Value = value;
		Tail = Temp;
		++cnt;
	}
	else if (index < cnt) //jezeli gdzies w srodek
	{
        Elements *Temp = Head;
		if(index<=(cnt/2))
            for (int i = 0; i < (index - 1); ++i)
                Temp = Temp->Next;
        else
        {
            Temp = Tail;
            for (int i = 0; i < (cnt-index); ++i)
                Temp = Temp->Prev;
        }
        Elements *NextTemp = Temp->Next;
		Temp->Next = new Elements;
		Temp->Next->Prev = Temp;
		Temp->Next->Value = value;
		Temp->Next->Next = NextTemp;
		NextTemp->Prev=Temp->Next;
		++cnt;
	}
    else
        std::cout<<"Nieprawidlowy index.";
}

int List::returnValue(int index)
{
        Elements *Temp = Head;
		if(index<=(cnt/2))
            for (int i = 0; i < index; ++i)
                Temp = Temp->Next;
        else
        {
            Temp = Tail;
            for (int i = 0; i < (cnt-index)-1; ++i)
                Temp = Temp->Prev;
        }
    return Temp->Value;
}

void List::deleteFromList(int value, bool test)
{
    Elements * Temp=Head;
    while(Temp)
    {
        if(Temp->Value==value)//jezeli znalazles
             break;//zwroc wskaznik
        if(Temp->Next)
            Temp = Temp->Next;//przesuwaj sie po liscie
        else
            return;
    }
    //adres zwrocony przez funkcje isValueInList - jezeli zwroci nullptr,
    //Elementsu nie ma w liscie, czyli if(0),
    //w przeciwnym przypadku if wykona sie, i usunie Elements
    if(Temp)
    {
        if(Head==Tail)//jezeli jest tylko jeden element
        {
            delete Head;
            Head=nullptr;
            Tail=nullptr;
        }
        else if(Temp==Tail)
        {
            Temp->Prev->Next=Temp->Next;
            Tail=Temp->Prev;
            delete Temp;
        }

        else if(Temp==Head)
        {
            Head=Head->Next;
            Head->Prev=nullptr;
            delete Temp;
        }
        else
        {
            Temp->Prev->Next=Temp->Next;
            Temp->Next->Prev=Temp->Prev;
            delete Temp;
        }
        --cnt;
    }
    else if (!test)
        std::cout<<"\nPodanej wartosci nie ma w liscie!!\n";
}

void List::loadFromFileToList(std::string FileName)
{
    std::fstream plik;
    plik.open(FileName,std::ios::in);
    if(plik.good())
    {
        clearList(); //wyczysc liste
        for(int i=0, a ; plik>>a ; ++i)
            addValueToList(i,a); //dodawaj do listy, w tym przypadku akurat na koniec listy.
        plik.close();
    }
    else
        std::cout<<"Cos poszlo nie tak...\n";
}

void List::clearList()
{
    if(!Head) //jezeli lista pusta
        return;
    Elements *Temp = Head;
    while(Temp->Next)
    {
        Temp=Temp->Next;//idz do nastepnego
        delete Temp->Prev; //zwolnij pamiec poprzedniego
    }
    delete Temp; //zwolnij pamiec na ostatnim elemencie
    Head=nullptr; //wyzeruj tail, head oraz cnt
    Tail=nullptr;
    cnt=0;
}

void List::generateList(int size)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 1000000);
    clearList(); //wyczysc liste
    for (int i=0;i<size;++i)
        addValueToList(i,dist(gen)); //dodaj wartosci losowe
}

void List::displayList()
{
    Elements *Temp = Head;
    int i=0;
    std::cout<<"Ilosc Elementow: "<<cnt<<".\n\n";
    while(Temp)
    {
        std::cout<<i<<". "<<Temp->Value<<"\n";
        Temp=Temp->Next;
        ++i;
    }
    if(Head)
        std::cout<<"\nHead:"<<Head->Value<<"\nTail:"<<Tail->Value<<"\n"; //dodatkowo wyswietl wartosci head i tail
}


bool List::isValueInList(int value)
{
    Elements *Temp = Head;
    while(Temp)
    {
        if(Temp->Value==value)
            return true;
        if(Temp->Next)
            Temp=Temp->Next;
        else
            return false;
    }
}
