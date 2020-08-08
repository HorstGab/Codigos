#ifndef LISTA
#define LISTA

#include <iostream>

using namespace std;


class Lista{
protected:
    int info;
    Lista *prox;

public:
    Lista(); //construtor
    Lista(int info);

    Lista **getProxptr();
    Lista *getProx();
    int getInfo();
    void *setProx(Lista* li);

    static Lista *insere_Fim(Lista *&H, int info);
    static void imprime(Lista* li);

    ~Lista(); //destrutor

};
#endif // LISTA

