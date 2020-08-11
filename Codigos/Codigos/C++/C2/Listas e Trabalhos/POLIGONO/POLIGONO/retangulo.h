#ifndef RETANGULO_H
#define RETANGULO_H
#include "poligono.h"

class Retangulo : public Poligono{
private:
    float altura;
    float largura;
public:
    Retangulo(float altura, float largura);

    void Area();
    float getArea();
    ~Retangulo();
};

#endif // RETANGULO_H
