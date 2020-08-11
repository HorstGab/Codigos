#include "multiplicacao.h"

#include <iostream>
using namespace std;

Multiplicacao::Multiplicacao() : Base() {

}

void Multiplicacao::imprimeNome() {
    cout << " *";
}

double Multiplicacao::processa() {
    return this->esq->processa()*
            this->dir->processa();
}
