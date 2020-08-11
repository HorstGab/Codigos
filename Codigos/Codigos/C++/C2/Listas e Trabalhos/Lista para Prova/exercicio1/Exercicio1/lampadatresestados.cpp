#include "lampadatresestados.h"

LampadaTresEstados::LampadaTresEstados(){
    this->lampadaTresEstados = (LampadaTresEstados*)malloc(sizeof(LampadaTresEstados));
}

char *LampadaTresEstados::Ligar(int ref){

    if(ref == 100){
        this->lampadaTresEstados = "Ligada";
    }if(ref == 0){
        this->lampadaTresEstados = "Desligada";
    }else{
        this->lampadaTresEstados = "Meia Fase";
    }
}

LampadaTresEstados::~LampadaTresEstados(){
    cout << "Destruindo objeto" << endl;
}
