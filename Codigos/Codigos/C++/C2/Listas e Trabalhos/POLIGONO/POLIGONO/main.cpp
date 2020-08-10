#include "poligono.h"
#include "circulo.h"
#include "retangulo.h"
#include "triangulo.h"
#include "poligonocomplexo.h"
#include <iostream>
using namespace std;

int main(){

    PoligonoComplexo* p = new PoligonoComplexo();
    Triangulo* t = new Triangulo(5.0, 2.5);
    Retangulo* r = new Retangulo(3.1, 3.1);
    Circulo* c = new Circulo(15);

    p->add_vector(t);
    p->add_vector(r);
    p->add_vector(c);

    t->Area();
    cout << "Triangulo: " << t->getArea() << "cm^2" << endl;

    r->Area();
    cout << "Retangulo: " << r->getArea() << "cm^2" << endl;

    c->Area();
    cout << "Circulo: " << c->getArea() << "cm^2" << endl;

    p->Area();
    cout << "Area Total: " << p->getArea() << "cm^2" << endl;

    cout << endl;
    return 0;
}

