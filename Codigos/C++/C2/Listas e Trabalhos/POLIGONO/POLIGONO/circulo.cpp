#include "circulo.h"
#include "math.h"

Circulo::Circulo(float raio){
    this->raio = raio;
    this->area = 0;
}

void Circulo::Area(){
    this->area = (PI*(pow(this->raio,2)));
}

float Circulo::getArea(){
    return this->area;
}

Circulo::~Circulo(){}
