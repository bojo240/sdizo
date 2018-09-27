#include "BST.h"
#include <iostream>
#include <fstream>
#include <random>

Node::Node() :  Value(0), Left(nullptr), Right(nullptr), Parent(nullptr) {;}
//konstruktor / lista inicjalizacyjna

BST::BST() : cr("  "), cl("  "), cp ("  "), Root (nullptr)//konstruktor / lista inicjalizacyjna
{
    cr[0] = 218; cr[1] = 196;
    cl[0] = 192; cl[1] = 196;
    cp[0] = 179;
}

static std::random_device rd;
static std::mt19937 gen(rd());
static std::uniform_int_distribution<> dist(1, 1000000);

int BST::returnValueOfRoot() {return Root->Value;}

void BST::addValueint value, bool dsw)
{
    if (!Root)
    {
        Root=new Node; //zaalokuj pamiec
        Root->Value=value; //przypisz wartosc, reszta skladowych wezla = nullptr
    }
    else
    {
        Node *Temp; // zmienna do przesuwania sie po drzewie
        Temp=Root;// przypisz na korzen
        while(1) // petla nieskonczona
        {
            if(value>Temp->Value)//jezeli wartosc nowego wezla jest wieksza od klucza obecnie rozpatrywanego wezla
            {
                if(Temp->Right)//jezeli mozesz
                    Temp=Temp->Right;//idz w prawo
                else//jezeli nie
                {
                    Temp->Right=new Node;//stworz nowy Node na prawo od obecnie rozpatrywanego wezla
                    Temp->Right->Parent=Temp;// i przypisz mu odpowiednie adresy/wartosci
                    Temp->Right->Value=value;
                    break;//wyjdz z funkcji
                }
            }
            else //jezeli wartosc jest mniejsza od klucza obecnie rozpatrywanego wezla
            {
                if(Temp->Left)//analogicznie, ale w lewo.
                    Temp=Temp->Left;
                else
                {
                    Temp->Left=new Node;
                    Temp->Left->Parent=Temp;
                    Temp->Left->Value=value;
                    break;
                }
            }
        }
        if(dsw)
            DSW();
        return;
    }
}

void BST::remove(int value, bool test, bool dsw)
{
    Node *Temp=isValueIn(value);//tworze zmienna i przypisuje jej adres szukanego Node

    if(!Temp)//jezeli wartosci nie ma w drzewie
    {
        if(!test)//jezeli to nie jest test, wyswietl komunikat
            std::cout<<"\nPodanej wartosci nie ma w drzewie!!\n";
    }
    else if(isLeaf(Temp))//jezeli usuwany element to lisc
    {
        if(Temp->Parent)
        {
            if(Temp->Parent->Left==Temp)//jezeli usuwany element to lewe dziecko swojego rodzica
                Temp->Parent->Left=nullptr;//wyczysc wskazniki
            else//analogicznie, jezeli usuwany element to prawe dziecko swojego rodzica
                Temp->Parent->Right=nullptr;
        }
        else
            Root=nullptr;
        delete Temp;//zwolnij pamiec
    }

    else if(Temp->Right&&!(Temp->Left))
    //jezeli jego prawe dziecko to lisc, zamien ich klucze miejscami
    {
        Temp->Value=Temp->Right->Value;
        delete Temp->Right;//zwolnij pamiec
        Temp->Right=nullptr;//wyczysc wskazniki
    }
    else if(Temp->Left&&!(Temp->Right)) //analogicznie jezeli lewe dziecko to lisc
    {
        Temp->Value=Temp->Left->Value;
        delete Temp->Left;
        Temp->Left=nullptr;
    }
    else
    {
        Node* Suc = successor(Temp); // znajdz nastepnika
        int temporary=Temp->Value; // zapamietaj obecnego node'a
        Temp->Value=Suc->Value; // zamien klucze
        Suc->Value=temporary;
        if(isLeaf(Suc))//jezeli usuwany element to lisc
        {
            if(Suc->Parent->Left==Suc)//jezeli usuwany element to lewe dziecko swojego rodzica
                Suc->Parent->Left=nullptr;//wyczysc wskazniki
            else//analogicznie, jezeli usuwany element to prawe dziecko swojego rodzica
                Suc->Parent->Right=nullptr;
            delete Suc;//zwolnij pamiec
        }
        else if(isLeaf(Suc->Right))//jezeli jego prawe dziecko to lisc, zamien ich klucze miejscami
        {
            Suc->Value=Suc->Right->Value;
            delete Suc->Right;//zwolnij pamiec
            Suc->Right=nullptr;//wyczysc wskazniki
        }
        else// prawe dziecko to nie liść
        {
            if(Suc->Parent->Left==Suc)// jezeli nastepnik to lewe dziecko swojego rodzica
                Suc->Parent->Left=Suc->Right; // to lewym dzieckiem jego rodzica jest prawe dziecko nastepnika
            else
                Suc->Parent->Right=Suc->Right; // analogicznie, prawym dzieckiego rodzica nastepnika staje sie prawe dziecko nastepnika
            Suc->Right->Parent=Suc->Parent; // zmiana rodzica dziecka
            delete Suc;
        }
    }
    if(dsw)
        DSW();
    return;
}

Node* BST::successor(Node* Temp)
{
    if(Temp->Right)//jezeli mozesz pojsc w prawo, to idz.
    {
        Temp=Temp->Right;
        while(Temp->Left)// idz maksymalnie w lew
            Temp=Temp->Left;
        return Temp; //zwroc wskaznik
    }
    else  //jezeli jestes prawym dzieckiem swojego syna
    {
        while(Temp->Parent&&Temp->Parent->Right==Temp)
            Temp=Temp->Parent; //idz w gore dopoki jestes prawym dzieckiem.

        if (Temp==Root) // jezeli obecnie jesteś na korzeniu - nie ma nastepnika
            return nullptr;
        else                // w tym momencie jestes lewym dzieckiem
            Temp=Temp->Parent; // idz w gore
        Temp=Temp->Right; // idz w prawo
        while (Temp->Left) //dopoki mozesz
            Temp=Temp->Left; //idz w lewo
        return Temp; //zwroc wskaznik
    }
}

Node* BST::isValue(int value)
{
    Node *Temp;//wskaznik do przesuwania sie po drzewie
    Temp=Root;//przypisz mu korzen
    while(1) // w zaleznosci od klucza, idz w prawo badz lewo
    {
        if (Temp->Value==value)//jezeli znalazles
            return Temp;//wyjdz, zwracajac adres szukanego Nodeu
        else if (Temp->Value<value&&Temp->Right)//jezeli mozesz idz w prawo
            Temp=Temp->Right;
        else if (Temp->Value>value&&Temp->Left)//jezeli moesz idz w lewo
            Temp=Temp->Left;
        else //jezeli ten wezel nie jest szukanym, nie mozesz pojsc ani w prawo ani w lewo,
            return nullptr;
    }
}

bool BST::isLeaf(Node* Temp)
{
    if(!(Temp->Left)&&!(Temp->Right)) // jezeli nie ma prawego ani lewego dziecka
        return true;
    return false;
}

void BST::loadFromFile(std::string FileName)
{
    std::fstream plik;
    plik.open(FileName,std::ios::in);
    if(plik.good())
    {
        clearBST(); //wyczysc drzewo
        for(int i=0, a ; plik>>a ; ++i)
            addNodeToBST(a); //dodawaj do drzewa
        plik.close();
    }
    else
        std::cout<<"Cos poszlo nie tak...\n";
}

void BST::generate(int size, int* tab, int randmax)
{
    clear(); //wyczysc drzewo
    if(tab)
        for(int i=0;i<size;++i)
            addValue(tab[i], false);
    else
        for (int i=0;i<size;++i)
            addValue(dist(gen)%(2*randmax)-randmax, false); //dodaj wartosci losowe
    DSW();
}

void BST::printBST(std::string sp, std::string sn, Node *v) //funkcja wyswietlajaca z serwisu eduinf.waw.pl/inf
{
    std::string s;
    if(v)
    {
        s=sp;
        if(sn == cr) s[s.length() - 2] = ' ';
        printBST(s + cp, cr, v->Right);

        s = s.substr(0,sp.length()-2);
        std::cout << s << sn << v->Value << "\n";

        s = sp;
        if(sn == cl) s[s.length() - 2] = ' ';
        printBST(s + cp, cl, v->Left);
    }
}

void BST::display()//metoda wywolujaca rekurencyjna metode;
{
    Node *asd=Root;
    printBST("","",asd);
}

void BST::clear()
{
    if(!Root)//jezeli drzewo jest puste
        return;
    deleteWholeBST(Root);//przekaz do funkcji rekurencyjnej korzen drzewa
}

void BST::deleteWholeBST(Node* Temp)
{
    if((Temp->Left)&&!(isLeaf(Temp->Left))) // Jeżeli istnieje lewe poddrzewo i nie jest lisciem
        deleteWholeBST(Temp->Left); //wejdz w nie ta funkcja
    if((Temp->Right)&&!(isLeaf(Temp->Right))) // Jezeli istnieje prawe poddrzewo i nie jest liscie
        deleteWholeBST(Temp->Right);//wejdz w nie ta funkcja
    if(!isLeaf(Temp)) // jezeli w tym punkcie funkcji nie jesteś liściem (masz prawego i/lub lewego syna-liscia)
    {//to usun swoje dzieci, a funkcja niech wroci do rodzica
        if(Temp->Right)//jezeli masz prawe dziecko, usun je
        {
            delete Temp->Right;
            Temp->Right=nullptr;
        }

        if(Temp->Left)//jezeli masz lewe dziecko, usun je
        {
            delete Temp->Left;
            Temp->Left=nullptr;
        }

        if(Temp!=Root)//jezeli nie jestes korzeniem, wroc do swojego rodzica
            return;

        Root=nullptr;//a skoro jestes, usun sie
        delete Temp;
    }
}

void BST::DSW()
{
    Node *Temp=Root;//ustawiam temp na korzen
    int n=0;//ilosc wezlow
    while(Temp) // tworzenie struktury listy -- wszystkie elementy są prawymi dziecmi swoich rodzicow
    {
        if(Temp->Left)//jezeli mozesz
        {
            rotateRight(Temp);//wykonaj rotacje w prawo
            Temp=Temp->Parent;
        }
        else
        {
            ++n;
            Temp=Temp->Right;//a jezeli nie mozesz, zwieksz licznik i przejdz do kolejnego wezla
        }
    }
    int m=n+1-pow(2,static_cast<int>(log2(n+1)));//wymagana ilosc obrotow
    Temp=Root;
    for (int i=0;i<m;i++)//petla wykonuje odpowiednia ilosc obrotow
    {
        rotateLeft(Temp);
        Temp=Temp->Parent->Right;
    }
    n-=m;//pomniejszam n o wykonana liczbe obrotow
    while (n>1)
    {
        n/=2;//dzielac int na 2 zaokragla sie w dol; tym samym jestem w stanie przejsc przez wszystkie poziomy
        Temp=Root;
        for(int i=0;i<n;i++)
        {
            rotateLeft(Temp);
            Temp=Temp->Parent->Right;
        }
    }
}

void BST::rotateRight(Node* A)
{
    Node* B=A->Left; //zapisuje sobie adres lewego dziecka A
    A->Left=B->Right; //zamieniam odpowiednie pola
    if(B->Right)
        B->Right->Parent=A;
    B->Parent=A->Parent;
    B->Right=A;
    A->Parent=B;
    if(B->Parent) // jezeli nie jestes korzeniem
    {
        if(B->Parent->Left==A)
            B->Parent->Left=B;
        else
            B->Parent->Right=B;
    }
    else
        Root=B;
}

void BST::rotateLeft(Node *A) // analogicznie
{
    Node* B=A->Right;
    A->Right=B->Left;
    if(B->Left)
        B->Left->Parent=A;
    B->Parent=A->Parent;
    B->Left=A;
    A->Parent=B;
    if(B->Parent)
    {
        if(B->Parent->Left==A)
            B->Parent->Left=B;
        else
            B->Parent->Right=B;
    }
    else
        Root=B;
}

void BST::menuRotateRight(int value) // funkcja publiczna do wyswietlenia w menu programu
{
    Node* A=isValueInBST(value);
    if(A&&A->Left)
    {
        Node* B=A->Left;
        A->Left=B->Right;
        if(B->Right)
            B->Right->Parent=A;
        B->Parent=A->Parent;
        B->Right=A;
        A->Parent=B;
        if(B->Parent)
        {
            if(B->Parent->Left==A)
                B->Parent->Left=B;
            else
                B->Parent->Right=B;
        }
        else
            Root=B;
    }
    else
        std::cout<<"\nNie ma takiego elementu.\n";
}

void BST::menuRotateLeft(int value)// funkcja publiczna do wyswietlenia w menu programu
{
    Node* A=isValueInBST(value);
    if(A&&A->Right)
    {
        Node* B=A->Right;
        A->Right=B->Left;
        if(B->Left)
            B->Left->Parent=A;
        B->Parent=A->Parent;
        B->Left=A;
        A->Parent=B;
        if(B->Parent)
        {
            if(B->Parent->Left==A)
                B->Parent->Left=B;
            else
                B->Parent->Right=B;
        }
        else
            Root=B;
    }
    else
        std::cout<<"\nNie ma takiego elementu.\n";
}
