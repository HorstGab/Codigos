#include "lampada.h"

Lampada::Lampada(){
    this->lampada = NULL;
}

bool Lampada::Ligar(){
    return this->lampada = 1;
}

bool Lampada::Desligar(){
    return this->lampada = 0;
}

void Lampada::Mostrar(){

    if(this->lampada == 1){
        cout << "Ligada" << endl;
    }else{
        cout << "Desligada" << endl;
    }
}

Lampada::~Lampada(){
    cout << "destruindo lampada" << endl;
}
