#include "soma.h"

#include <iostream>
using namespace std;

Soma::Soma() : Base() {
}

void Soma::imprimeNome() {
    cout << " +";
}

double Soma::processa() {
    if (this->esq)
        return this->esq->processa()+
                this->dir->processa();
    else
        return this->dir->processa();
}
