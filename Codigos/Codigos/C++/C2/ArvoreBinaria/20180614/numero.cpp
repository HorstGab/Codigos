#include "numero.h"

#include <stdlib.h>
#include <stdio.h>

#include <iostream>
using namespace std;

Numero::Numero( char *valor ) : Base() {
    this->valor = atof(valor);
}

void Numero::imprimeNome() {
    cout << " " << this->valor;
}

void Numero::infix () {
    imprimeNome();
}

double Numero::processa() {
   return this->valor;
}
