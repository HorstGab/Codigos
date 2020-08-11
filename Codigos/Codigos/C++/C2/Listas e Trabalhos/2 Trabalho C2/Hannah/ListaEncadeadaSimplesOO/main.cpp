#include "lista.h"

/*!
    \file main.cpp
    \author Hannah C. Mariani
*/


int main(){

    Lista *li = NULL;

    ///
    cout << "CRIANDO LISTA ..." << endl;

    Lista::InsereFim(li,1);
    Lista::InsereFim(li,2);
    Lista::InsereFim(li,3);
    Lista::InsereFim(li,4);
    Lista::InsereFim(li,5);

    Lista::Show(li);

    cout << endl;
    li->~Lista();
    cout << "Destruindo Lista" << endl;

    ///
    cout << "CRIANDO FILA ..." << endl;

    ///
    cout << "Destruindo Fila" << endl;

   ///
    cout << "CRIANDO PILHA ..." << endl;

    ///
    cout << "Destruindo Pilha" << endl;
    return 0;
}
