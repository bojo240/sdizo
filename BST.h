#pragma once
#include <string>
struct Node
{
    int Value; //klucz
    Node *Right;//wskaznik na prawe dziecko
    Node *Left;//wskaznik na lewe dziecko
    Node *Parent;//wskaznik na rodzica
    Node(); //konstruktor/lista inicjalizacyjna
};

class BST
{
    Node *Root; //wskaznik na korzen drzewa
    std::string cr,cl,cp;
    void printBST(std::string, std::string, Node*);
    bool isLeaf(Node*);
    void rotateRight(Node*);
    void rotateLeft(Node*);
	void deleteWholeBST(Node*);
    void DSW();
public:
    BST ();//konstruktor/lista inicjalizacyjna
	void addNodeToBST(int value);
	void deleteFromBST(int value, bool test = false);
    void loadFromFileToBST(std::string FileName);
	void generateBST(int size);
	void displayBST();
	Node* isValueInBST(int value);// funkcja zwracajaca wskaznik na szukany wezel.
	void clearBST();
	int returnValueOfRoot();
};
