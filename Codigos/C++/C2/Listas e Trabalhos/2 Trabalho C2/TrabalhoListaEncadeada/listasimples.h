#ifndef LISTASIMPLES_H
#define LISTASIMPLES_H

#include <iostream>

using namespace std;

#include <stdio.h>
#include <stdlib.h>

class No{
protected:
    int info;
    No* prox;
public:
    No();
    No(int info);

    bool vazia(No *&no) const;

    static No* inserir_inicio(No *&l, int info);
    static No* inserir_final(No *&l, int info);

    static void remove_inicio(No *&l);
    static No *remove_final(No *&l);

    static void num_elem(No* li);
    static void imprime(No* li);
    static No *return_no(No *li, int pos);

    No **getProxptr();
    No *getProx();
    void setProx(No* li);
    int getInfo();


    ~No();
};

#endif // LISTASIMPLES_H
