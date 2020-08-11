#ifndef POLIGONO_H
#define POLIGONO_H

#include <iostream>
using namespace std;

class Poligono{
protected:
    float area;
public:
    Poligono();
    virtual void Area() = 0;
    virtual float getArea() = 0;
};

#endif // POLIGONO_H

