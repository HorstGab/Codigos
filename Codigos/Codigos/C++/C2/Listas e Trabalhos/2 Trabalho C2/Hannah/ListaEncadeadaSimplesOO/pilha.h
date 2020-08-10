#ifndef PILHA_H
#define PILHA_H

#include "lista.h"

/*!
    \file pilha.h
    \class Pilha
    \author Hannah C. Mariani
*/

class Pilha : public Lista
{
public:
    Pilha();
    Pilha(int num);


    /// Pop() -> Remove o último elemento da Pilha
    static Lista *RemoveFim(Pilha *&P, int info);

    ///Pilha Vazia
    void PilhaVazia(Pilha *P);

};

#endif // PILHA_H
