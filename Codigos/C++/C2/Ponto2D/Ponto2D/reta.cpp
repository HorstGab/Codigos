#include "reta.h"

Reta::Reta(double coeficienteLinear, double coeficineteAngular){

    this->coeficienteLinear = coeficienteLinear;
    this->coeficienteAngular = coeficineteAngular;
}

Reta::Reta(ponto2d *p1, ponto2d *p2){

    this->coeficienteAngular = (p1->gety() - p2->gety())/(p1->getx() - p2->getx());

    this->coeficienteLinear = p1->gety()- this->coenficienteAngular *p1->getx();

}

bool Reta::pertence(ponto2d *p){
    double c = p->gety() - this->coenficienteAngular *p->getx();

    return c == this->coeficienteLinear;
}

ponto2d* Reta::intercepta(Reta*r){
    ponto2d *p = NULL;

    if(this->coeficienteAngular != r->getCoeficienteAngular()){

        double x = (this->coeficienteLinear - r->getCoeficienteLinear()) /
                (this->)
    }
}

double Reta::getCoenficienteLinear(){
    return this->coeficienteLinear;
}

double Reta::getCoenficienteAngular(){
    return this->coeficienteAngular;
}
