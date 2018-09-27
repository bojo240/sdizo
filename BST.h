#pragma once
#include <string>
#include <random>

struct Node
{
    int Value; //klucz
    Node *Left;//wskaznik na lewe dziecko
    Node *Right;//wskaznik na prawe dziecko
    Node *Parent;//wskaznik na rodzica
    Node(); //konstruktor/lista inicjalizacyjna
};

class BST
{
    std::string cr,cl,cp;
    void printBST(std::string, std::string, Node*);
    bool isLeaf(Node*);
	void deleteWholeBST(Node*);
    Node* successor(Node* Temp);
    void rotateRight(Node*);
    void rotateLeft(Node*);
    Node *Root; //wskaznik na korzen drzewa
public:
    BST ();//konstruktor/lista inicjalizacyjna
	void addValue(int value, bool dsw=true);
	void remove(int value, bool test = false, bool dsw = true);
    Node* isValue(int value);// funkcja zwracajaca wskaznik na szukany wezel.
	void generate(int size, int* tab=nullptr, int randmax = 1000);
    void loadFromFile(std::string FileName);
	void display();
	void clear();
	int returnValueOfRoot();
    void menuRotateLeft(int value);
    void menuRotateRight(int value);
    void DSW();
};
