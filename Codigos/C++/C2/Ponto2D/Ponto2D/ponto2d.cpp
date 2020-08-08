#include "ponto2d.h"

#include "math.h"
#include "iostream"

using namespace std;


ponto2d::ponto2d(){
    this -> x = 0;
    this -> y = 0;
}

ponto2d::ponto2d (double x, double y){
    this -> x = x;
    this ->y = y;
}

ponto2d::ponto2d (ponto2d *p){
    this -> x = p->getx();
    this -> y = p->gety();
}

double ponto2d::getx(){
    return this -> x;
}
double ponto2d::gety(){
    return this -> y;
}

void ponto2d::setx(double x){
    this -> x = x;
}

void ponto2d::sety(double y){
    this -> y = y;
}

void ponto2d::move(){
    this -> x = 0;
    this -> y = 0;
}

void ponto2d::move(double x, double y){
    this -> x = x;
    this -> y = y;
}

void ponto2d::move(ponto2d *p){
    this -> x = p->getx();
    this -> y = p->gety();
}

bool ponto2d::equals(ponto2d *p){
    return (this -> x == p->getx()) && (this -> y == p->gety());
}

double ponto2d::distance(ponto2d *p){
    return sqrt(pow(p->getx()-this->x,2)+ pow(p->gety()- this->y, 2));
}

ponto2d * ponto2d::clone(){
    return new ponto2d(this);
}

ponto2d::~ponto2d(){
    cout << "Destruindo o objeto Ponto2D" << endl;
}
