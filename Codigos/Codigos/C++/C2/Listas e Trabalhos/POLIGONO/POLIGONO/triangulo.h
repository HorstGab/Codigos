#ifndef TRIANGULO_H
#define TRIANGULO_H
#include "poligono.h"

class Triangulo : public Poligono{
private:
    float altura;
    float base;
public:
    Triangulo(float altura, float base);

    void Area();
    float getArea();
    ~Triangulo();
};

#endif // TRIANGULO_H
