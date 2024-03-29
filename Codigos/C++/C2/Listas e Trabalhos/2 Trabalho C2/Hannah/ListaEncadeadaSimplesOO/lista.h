#ifndef LISTA
#define LISTA

#include <iostream>

using namespace std;

/*!
    \file lista.h
    \class Lista
    \author Hannah C. Mariani
*/


class Lista{
protected:
    ///
    int info;
    Lista *prox;

public:

    ///Construtor
    Lista();
    Lista(int info);

    ///
    Lista **getProxptr();

    ///
    Lista *getProx();

    ///
    int getInfo();

    ///
    void *setProx(Lista* li);

    ///Verifica se a Lista está vazia
    bool isEmpty() const;


    ///Insere no Final da Lista
    static Lista *InsereFim(Lista *&H, int info);


    ///
    static void Show(Lista* li);

    ///Destrutor
    ~Lista();

};
#endif // LISTA
