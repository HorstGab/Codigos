#include "elevador.h"

Elevador::Elevador(int capacidade, int andarTotal){

    this->capacidade = capacidade;
    this->andarTotal = andarTotal;
    this->andarAtual = 0;
    this->numPessoas = 0;
}

void Elevador::entraPessoa(){

    if(this->numPessoas < this->capacidade){
        this->numPessoas ++;
    }else{
        cout << "ELEVADOR LOTADO" << endl;
    }
}

void Elevador::saiPessoa(){

    if(this->numPessoas != 0){
        this->numPessoas --;
    }else{
        cout << "ELEVADOR VAZIO" << endl;
    }
}

void Elevador::subir(){

    if(this->andarAtual < this->andarTotal){
        this->andarAtual++;
    }else{
        cout << "ULTIMO ANDAR" << endl;
    }
}

void Elevador::descer(){

    if(this->andarAtual != 0){
        this->andarAtual --;
    }else{
        cout << "TERREO" << endl;
    }
}

int Elevador::getAndarAtual(){
    return this->andarAtual;
}

int Elevador::getAndarTotal(){
    return this->andarTotal;
}

int Elevador::getCapacidade(){
    return this->capacidade;
}

int Elevador::getNumPessoa(){
    return this->numPessoas;
}

void Elevador::mostrarAndar(){

    cout << "Andar Atual: " <<  this->andarAtual << endl;
}

void Elevador::mostrarNumPessoa(){

    cout << "Quantidade de pessoas no elevador: " << this->numPessoas << endl;
}

Elevador::~Elevador(){
    cout << "DESTRUINDO CLASSE ELEVADOR" << endl;
}
