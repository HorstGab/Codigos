#ifndef LAMPADA_H
#define LAMPADA_H

#include <iostream>

using namespace std;

class Lampada{
protected:
    bool lampada;
public:
    Lampada();
    bool Ligar();
    bool Desligar();
    void Mostrar();

    ~Lampada();

};

#endif // LAMPADA_H
