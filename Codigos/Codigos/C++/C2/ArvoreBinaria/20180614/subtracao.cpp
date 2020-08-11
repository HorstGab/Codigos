#include "subtracao.h"

#include <iostream>
using namespace std;

Subtracao::Subtracao() : Base() {
}

void Subtracao::imprimeNome() {
    cout << " -";
}

double Subtracao::processa() {
    if (this->esq)
        return this->esq->processa()-
                this->dir->processa();
    else
        return -this->dir->processa();
}
