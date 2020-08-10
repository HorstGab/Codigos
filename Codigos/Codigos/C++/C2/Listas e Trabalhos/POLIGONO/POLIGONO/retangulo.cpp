#include "retangulo.h"

Retangulo::Retangulo(float altura, float largura){
    this->altura = altura;
    this->largura = largura;
    this->area = 0;
}

void Retangulo::Area(){
    this->area = this->altura * this->largura;
}

float Retangulo::getArea(){
    return this->area;
}

Retangulo::~Retangulo(){}
