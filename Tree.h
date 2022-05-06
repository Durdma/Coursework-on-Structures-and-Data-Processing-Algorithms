#pragma once
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;



//  —“–” “”–¿ ¬À¿ƒ≈À‹÷¿ —»Ã  ¿–“€ ’–¿ÕﬂŸ≈√Œ—ﬂ ¬ ƒ≈–≈¬≈
struct clientTree {
    string pasport;
    string placeAndDate;
    string FIO;
    int birthyear;
    string address;

    clientTree(string pasport = "", string placeAndDate = "", string FIO = "", int birthyear = 0, string address = "") {
        this->pasport = pasport;
        this->placeAndDate = placeAndDate;
        this->FIO = FIO;
        this->birthyear = birthyear;
        this->address = address;
    }
};



//  —“–” “”–¿ ”«À¿ ƒ≈–≈¬¿
struct node {
    clientTree key;
    int height;
    node* left;
    node* right;
    
    node(clientTree k) { 
        key = k; 
        left = right = NULL;
        height = 1; 
    }
};




class Tree {
public:

    int height(node* p);
    int bfactor(node* p);
    void fixHeight(node* p);

    node* root = NULL;


    node* rotateRight(node* p);
    node* rotateLeft(node* p);
    node* balance(node* p);
    
    void addKlitnt(clientTree k);
    void deleteKlient(string pasport);


    node* insert(node* p, clientTree k);
    node* findMin(node* p);
    
    node* removeMin(node* p);
    node* remove(node* p, string k);
    void removeAll();

    void findCustomer(node* p, string a);
    
    bool checkPasport(string a, node* p);

    void showKlient();
    void minShow(node* p);

    void findKlientOnString(node* p, string str, bool& chek);
    bool findString(string s, string c);
};

