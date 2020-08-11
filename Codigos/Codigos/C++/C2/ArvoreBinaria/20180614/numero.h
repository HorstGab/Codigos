#ifndef NUMERO_H
#define NUMERO_H

#include "base.h"

class Numero : public Base {
private:
public:
    Numero( char *valor );
    void imprimeNome();
    void infix ();
    double processa();
};

#endif // NUMERO_H
