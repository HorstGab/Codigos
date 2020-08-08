#include "divisao.h"

#include "erro.h"

#include <iostream>
using namespace std;

Divisao::Divisao() : Base() {

}

void Divisao::imprimeNome() {
    cout << " /";
}

double Divisao::processa() {
    double divisor = this->dir->processa();
    if (divisor!=0)
        return this->esq->processa()/divisor;
    else
        throw DivisaoPorZero();
    return 0;
}
