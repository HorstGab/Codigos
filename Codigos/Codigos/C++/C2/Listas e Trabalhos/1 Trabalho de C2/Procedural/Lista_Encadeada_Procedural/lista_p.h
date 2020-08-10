#ifndef LISTA_P
#define LISTA_P

#include <iostream>
#include "stdlib.h"

using namespace std;

    typedef struct no Lista;

    Lista* lista();
    int vazia(Lista * li);

    Lista* insere_Final(Lista* li, int info);

    void imprime(Lista* li);
    void freeLista(Lista* li);

#endif // LISTA_P

