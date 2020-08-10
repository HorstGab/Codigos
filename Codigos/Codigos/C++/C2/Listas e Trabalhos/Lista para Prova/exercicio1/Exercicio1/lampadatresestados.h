#ifndef LAMPADATRESESTADOS_H
#define LAMPADATRESESTADOS_H

#include <iostream>
#include <stdlib.h>

using namespace std;

class LampadaTresEstados : Lampada
{
protected:
    char* lampadaTresEstados;
public:
    LampadaTresEstados();
    char* Ligar(int ref);

    ~LampadaTresEstados();
};

#endif // LAMPADATRESESTADOS_H
