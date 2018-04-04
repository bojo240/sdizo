#include "BST.h"
#include <iostream>
#include <fstream>
#include <random>

//std::string cr,cl,cp;//zmienne string wykorzystywane do metody wyswietlania drzewa

Node::Node() :  Value(0), Left(nullptr), Right(nullptr), Parent(nullptr) {;}
//konstruktor / lista inicjalizacyjna

BST::BST() : cr("  "), cl("  "), cp ("  "), Root (nullptr)//konstruktor / lista inicjalizacyjna
{
    cr[0] = 218; cr[1] = 196;
    cl[0] = 192; cl[1] = 196;
    cp[0] = 179;
}


int BST::returnValueOfRoot() {return Root->Value;}

void BST::addNodeToBST(int value)
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
        DSW();
    }
}

void BST::deleteFromBST(int value, bool test)
{
    Node *Temp=isValueInBST(value);//tworze zmienna i przypisuje jej adres szukanego Node
    //displayBST();
    if(!Temp)//jezeli wartosci nie ma w drzewie
    {
        std::cout<<"1\n";
        if(!test)//jezeli to nie jest test, wyswietl komunikat
            std::cout<<"\nPodanej wartosci nie ma w drzewie!!\n";
        return;//wyjdz
    }
    std::cout<<returnValueOfRoot()<<'\n';
    if(isLeaf(Temp))//jezeli to lisc
    {
            std::cout<<"2\n";
        if(Temp->Parent->Left==Temp)//jezeli usuwany element to lewe dziecko swojego rodzica
            Temp->Parent->Left=nullptr;//wyczysc wskazniki
        else//analogicznie, jezeli usuwany element to prawe dziecko swojego rodzica
            Temp->Parent->Right=nullptr;
        delete Temp;//zwolnij pamiec
        return;
    }

    if(isLeaf(Temp->Right))
    //jezeli jego prawe dziecko to lisc, zamien ich klucze miejscami
    {
        std::cout<<"3\n";
        Temp->Value=Temp->Right->Value;
        delete Temp->Right;//zwolnij pamiec
        Temp->Right=nullptr;//wyczysc wskazniki
        return;
    }
    //albo wezel ma tylko lewe poddrzewo, albo szukamy nastepnika w prawym poddrzewie.
    //na pewno element to usunięcia nie jest liściem, ani jego lewe/prawe poddrzewo nie sa liscmi.

    if(Temp->Right)//jezeli możesz, idz w prawo
    {
        if(!(Temp->Right->Left))//jezeli nie mozesz isc w lewo
        {//ojcu przypisuje prawe dziecko
            std::cout<<"4\n";
            displayBST();
            Temp->Right->Parent=Temp->Parent;
            //std::cout<<"gdzie\n";
            if(Temp->Parent)//-----------------------------------   NIE MA TEMP->PARENT, bo w sumie usuwam roota..
            {
                if(Temp->Parent->Right&&Temp->Parent->Right==Temp)
                {
                    Temp->Parent->Right=Temp->Right;
                    std::cout<<"ty\n";
                }
                else if(Temp->Parent->Left)
                {
                    Temp->Parent->Left=Temp->Right;
                    std::cout<<"sie\n";
                }
            }
            std::cout<<"szmato\n";

            //jeżeli mam lewe poddrzewo, przypisuje je swojemu prawemu dziecku.
            if(Temp->Left)//jezeli mam lewe poddrzewo, przypisuje je do swojego prawego dziecka
            {
                std::cout<<"kurwa\n";
                Temp->Left=Temp->Right->Left;
                Temp->Right->Left=Temp->Left;
            }
            std::cout<<"pierdolisz\n";
            delete Temp;//zwolnij pamiec
            std::cout<<"pipo.";
            return;//wyjdz
        }
        else//jezeli moge w prawo, a nastepnie w lewo
        {
            std::cout<<"5\n";
            Node* Tempp=Temp; //zapisuje adres elementu do usuniecia
            Temp=Temp->Right;//ide w prawo
            while(Temp->Left)//ide na maksa w lewo
                Temp=Temp->Left;
            Tempp->Value=Temp->Value;//zamieniam wartosci


            if(Temp->Right)//jezeli ma prawe dziecko
            {
                Temp->Right->Parent=Temp->Parent; //jego ojcu przypisz prawe dziecko, a prawemu dziecku przypisz swojego ojca.
                if(Temp->Parent->Right==Temp)
                    Temp->Parent->Right=Temp->Right;
                else
                    Temp->Parent->Left=Temp->Right;
            }
            else//jezeli jest lisciem
            {
                Temp->Parent->Left=nullptr;
                delete Temp;
            }
        }
    }
    else
    {
        std::cout<<"6\n";
        Temp->Left->Parent=Temp->Parent;
        if(Temp->Parent->Right==Temp)
            Temp->Parent->Right=Temp->Left;
        else
            Temp->Parent->Left=Temp->Left;
    }
    std::cout<<"usuniete\n";
}

Node* BST::successor(Node* Temp)
{
    if(Temp->Right)//jezeli mozesz pojsc w prawo, to idz.
    {
        Temp=Temp->Right;
        while(Temp->Left)
            Temp=Temp->Left;
        return Temp;
    }
    else if(Temp->Parent)//jezeli jestes lewym synem swojego ojca
    {
        if(Temp->Parent->Left==Temp)
        return Temp->Parent;
    }


}

Node* BST::isValueInBST(int value)
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
    if((!Temp->Left)&&!(Temp->Right))
        return true;
    return false;
}

void BST::loadFromFileToBST(std::string FileName)
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

void BST::generateBST(int size)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 1000000);
    clearBST(); //wyczysc drzewo
    for (int i=0;i<size;++i)
        addNodeToBST(dist(gen)%1000); //dodaj wartosci losowe
}

void BST::printBST(std::string sp, std::string sn, Node *v)
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

void BST::displayBST()//metoda wywolujaca rekurencyjna metode;
{
    Node *asd=Root;
    printBST("","",asd);
}

void BST::clearBST()
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

void BST::rotateRight(Node* Temp)
{
    Node* FLC=Temp->Left;
    Node* FP=Temp->Parent;
    if(FLC)
    {
        Temp->Left=FLC->Right;
        if(Temp->Left)
            Temp->Left->Parent=Temp;
        FLC->Right=Temp;
        FLC->Parent=FP;
        Temp->Parent=FLC;
        if(FP)
        {
            if(FP->Left==Temp)
                FP->Left=FLC;
            else
                FP->Right=FLC;
        }
        else Root=FLC;
    }
}

void BST::rotateLeft(Node *Temp)
{
    Node *FRC=Temp->Right;
    Node *FP=Temp->Parent;
    if(FRC)
    {
        Temp->Right=FRC->Left;
        if(Temp->Right)
            Temp->Left->Parent=Temp;
        FRC->Left=Temp;
        FRC->Parent=FP;
        Temp->Parent=FRC;
        if(FP)
        {
            if(FP->Right==Temp)
                FP->Right=FRC;
            else
                FP->Left=FRC;
        }
        else Root = FRC;
        }
}

void BST::DSW()
{
    Node *Temp=Root;//ustawiam temp na korzen
    int n=0;//ilosc wezlow
    while(Temp)
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
