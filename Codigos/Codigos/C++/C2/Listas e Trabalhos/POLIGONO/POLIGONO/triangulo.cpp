#include "triangulo.h"

Triangulo::Triangulo(float altura, float base){
    this->altura = altura;
    this->base = base;
    this->area = 0;
}

void Triangulo::Area(){
    this->area = ((this->altura * this->base)/2);
}

float Triangulo::getArea(){
    return this->area;
}

Triangulo::~Triangulo(){}

