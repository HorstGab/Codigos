#include "poligonocomplexo.h"

PoligonoComplexo::PoligonoComplexo(){
    this->poligono = new vector<Poligono*>;
    this->area = 0;
}

void PoligonoComplexo::Area(){

    for(int i = 0; i < (int)this->poligono->size(); ++i){
        this->area = this->poligono->at(i)->getArea();
    }
}

float PoligonoComplexo::getArea(){
    return this->area;
}

void PoligonoComplexo::add_vector(Poligono *poligono){
    this->poligono->push_back(poligono);
}

PoligonoComplexo::~PoligonoComplexo(){}
