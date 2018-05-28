#include "List.h"
#include <iostream>
#include <fstream>
#include <random>

Elements::Elements() : Value(0), Next(nullptr), Prev(nullptr) {;} //konstruktor / lista inicjalizacyjna

List::List() : Head (nullptr), Tail(nullptr), cnt(0) {;} //konstruktor / lista inicjalizacyjna

static std::random_device rd;
static std::mt19937 gen(rd());
static std::uniform_int_distribution<> dist(1, 1000000);


void List::addValueToList(int index, int value) //najpierw przechodze po liscie w wybrane miejsce, dopiero pozniej dodaje tam wartosc.
{

    if (!Head) //jezeli nie ma head
	{
		Head = new Elements; // utworz
		Head->Value = value; //przypisz wartosc
		Tail = Head; // nie zapomnij o Tail
		++cnt; // zwieksz licznik
	}
	else if (index == 0) //jezeli dodaje na poczatek
	{
		Elements *Temp = Head; //ustaw wskaznik na head
		Temp->Prev = new Elements; // zadeklaruj pamiec
		Temp=Temp->Prev; // przesun sie na ten element
		Temp->Value = value; // przypisz wartosc
		Temp->Next = Head;// przypisz nexta
		Head = Temp; // ustaw head na ten element
		++cnt; // zwieksz licznik
	}
	else if (index == cnt) //jezeli dodaje na koniec
	{
		Elements *Temp = Tail; // ustaw sie na Tail
		Temp->Next = new Elements; // zadeklaruj pamiec
		Temp = Temp->Next; // przejdz do tego elementu
		Temp->Prev = Tail; // ustaw pola struktury
		Temp->Value = value;
		Tail = Temp;
		++cnt;
	}
	else if (index < cnt) //jezeli gdzies w srodek
	{
        Elements *Temp = Head; //ustaw sie wstepnie na head
		if(index<=(cnt/2)) // jezeli wstawiamy w pierwsza polowe
            for (int i = 0; i < (index - 1); ++i)
                Temp = Temp->Next; //idz do przodu
        else // jezeli w druga polowe
        {
            Temp = Tail; // ustaw sie na ogon
            for (int i = 0; i < (cnt-index); ++i)
                Temp = Temp->Prev; // przesuwaj sie do tylu
        }
        Elements *NextTemp = Temp->Next; // zapisz sobie adres nastepnego elementu
		Temp->Next = new Elements; // zadeklaruj pamiec
		Temp->Next->Prev = Temp; // ustaw pola struktury
		Temp->Next->Value = value;
		Temp->Next->Next = NextTemp;
		NextTemp->Prev=Temp->Next;
		++cnt; // zwieksz licznik
	}
    else
        std::cout<<"Nieprawidlowy index.";
}

void List::deleteFromList(int value, bool test) // usuwanie z listy
{
    Elements * Temp=isValueInList(value);
    //adres zwrocony przez funkcje isValueInList - jezeli zwroci nullptr,
    //Elementsu nie ma w liscie, czyli if(0),
    //w przeciwnym przypadku if wykona sie, i usunie Elements
    if(Temp)
    {
        if(Head==Tail)//jezeli jest tylko jeden element
        {
            delete Head; // wyzeruj head, tail i zwolnij pamiec
            Head=nullptr;
            Tail=nullptr;
        }
        else if(Temp==Tail)//jezeli to Tail
        {

            Tail=Tail->Prev; // zmien odpowiednie pola w strukturze
            Tail->Next=nullptr;
            delete Temp; // zwolnij pamiec
        }

        else if(Temp==Head) // jezeli to Head
        {
            Head=Head->Next; //zmien odpowiednie pola w strukturze
            Head->Prev=nullptr;
            delete Temp; // zwolnij pamiec
        }
        else
        {
            Temp->Prev->Next=Temp->Next;//zmien pola
            Temp->Next->Prev=Temp->Prev;
            delete Temp; // zwolnij pamiec
        }
        --cnt; // zmniejsz licznik
    }
    else if (!test) // jezeli to nie jest test
        std::cout<<"\nPodanej wartosci nie ma w liscie!!\n"; // wyswielt error
}

void List::loadFromFileToList(std::string FileName)
{
    std::fstream plik;
    plik.open(FileName,std::ios::in);
    if(plik.good())
    {
        clearList(); //wyczysc liste
        for(int i=0, a ; plik>>a ; ++i)
            addValueToList(i,a); //dodawaj na koniec listy.
        plik.close();
    }
    else
        std::cout<<"Cos poszlo nie tak...\n";
}

void List::clearList()
{
    if(!Head) //jezeli lista pusta
        return;
    Elements *Temp = Head; // ustaw sie na Head
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

void List::generateList(int size, int* tab, int randmax)
{
    clearList(); //wyczysc liste
    for (int i=0;i<size;++i)
        addValueToList(i, dist(gen)%(2*randmax)-randmax); //dodaj wartosci losowe
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

Elements* List::isValueInList(int value) // funkcja zwraca wskaznik na znaleziony element, jezeli nie znajdzie zwraca nullptr
{
    Elements *Temp = Head;
    while(Temp)
    {
        if(Temp->Value==value)
            return Temp;
        if(Temp->Next)
            Temp=Temp->Next;
        else
            return nullptr;
    }
    return nullptr;
}

int List::returnValue(int index) // funkcja sluzaca glownie do testow, zwraca
{
    Elements *Temp = Head; // ustaw sie na head
    if (index<cnt) // jezeli index ma sensowna wartosc
    {
        if(index<=(cnt/2)) // jezeli indeks to mniej niz polowa ilosci elementow
            for (int i = 0; i < index; ++i)
                Temp = Temp->Next; // idz do przodu
        else // jezeli wiecej niz polowa
        {
            Temp = Tail; // ustaw sie na tail
            for (int i = 0; i < (cnt-index)-1; ++i)
                Temp = Temp->Prev; // idz do tylu
        }
        return Temp->Value; // zwroc ta wartosc
    }
    return Temp->Value;
}
