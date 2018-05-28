#pragma once
#include <chrono>
#include <random>
class pomiary
{
    Table myTab;
    List myList;
    Heap myHeap;
    BST myBST;
    static const int pktypomiar = 50; //zmienna globalna okreslajaca rozdzielczosc pomiarow
    static const int powtorzenia = 100; //ile razy dokonac testow
    double czas;
    void clearvars();
public:
    //Deklaracje metod testujacych
    void StartCounter();
    double GetCounter();


    void addsmalltotablebegin();
    void addaveragetotablebegin();
    void addlargetotablebegin();

    void addsmalltotablerandom();
    void addaveragetotablerandom();
    void addlargetotablerandom();

    void addsmalltotableend();
    void addaveragetotableend();
    void addlargetotableend();

    void addsmalltolistbegin();
    void addaveragetolistbegin();
    void addlargetolistbegin();

    void addsmalltolistrandom();
    void addaveragetolistrandom();
    void addlargetolistrandom();

    void addsmalltolistend();
    void addaveragetolistend();
    void addlargetolistend();

    void addsmalltoheap();
    void addaveragetoheap();
    void addlargetoheap();

    void addsmalltoBST();
    void addaveragetoBST();
    void addlargetoBST();

    void addsmalltoBST_DSW();
    void addaveragetoBST_DSW();
    void addlargetoBST_DSW();


    void removesmallfromtablebegin();
    void removeaveragefromtablebegin();
    void removelargefromtablebegin();

    void removesmallfromtablerandom();
    void removeaveragefromtablerandom();
    void removelargefromtablerandom();

    void removesmallfromtableend();
    void removeaveragefromtableend();
    void removelargefromtableend();

    void removesmallfromlistbegin();
    void removeaveragefromlistbegin();
    void removelargefromlistbegin();

    void removesmallfromlistrandom();
    void removeaveragefromlistrandom();
    void removelargefromlistrandom();

    void removesmallfromlistend();
    void removeaveragefromlistend();
    void removelargefromlistend();

    void removesmallfromheap();
    void removeaveragefromheap();
    void removelargefromheap();

    void removesmallfromBST();
    void removeaveragefromBST();
    void removelargefromBST();

    void removesmallfromBST_DSW();
    void removeaveragefromBST_DSW();
    void removelargefromBST_DSW();


    void findsmallintable();
    void findavarageintable();
    void findlargeintable();

    void findsmallinlist();
    void findavarageinlist();
    void findlargeinlist();

    void findsmallinheap();
    void findavarageinheap();
    void findlargeinheap();

    void findsmallinBST();
    void findavarageinBST();
    void findlargeinBST();

    int iloscpomiarow;
};
