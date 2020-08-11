#ifndef POLIGONOCOMPLEXO_H
#define POLIGONOCOMPLEXO_H
#include "poligono.h"
#include <vector>

class PoligonoComplexo : public Poligono{
private:
    vector<Poligono*> *poligono;
public:
    PoligonoComplexo();

    void Area();
    float getArea();
    void add_vector(Poligono* poligono);
    ~PoligonoComplexo();
};

#endif // POLIGONOCOMPLEXO_H
