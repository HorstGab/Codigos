#ifndef CIRCULO_H
#define CIRCULO_H
#define PI 3.1415
#include "poligono.h"

class Circulo : public Poligono{
private:
    float raio;
public:
    Circulo(float raio);

    void Area();
    float getArea();
    ~Circulo();
};

#endif // CIRCULO_H
