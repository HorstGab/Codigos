#ifndef AVL_H
#define AVL_H

#include <iostream>

using namespace std;

#include <stdio.h>
#include <stdlib.h>

class AVL{
private:
    int n;
    AVL *esq;
    AVL *dir;

    AVL (int n);
public:
    AVL();
    static void insere(AVL **r, int n);
    void mostrar();
    ~AVL();

};

#endif // AVL_H
