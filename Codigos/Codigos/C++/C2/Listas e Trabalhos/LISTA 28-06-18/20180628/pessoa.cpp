#include "pessoa.h"

pessoa::pessoa(){
    this->nome = "";
    this->nascimento = NULL;
    this->altura = 0;
}

pessoa::pessoa(string nome, data *nascimento, float altura){
    this->nome = nome;
    this->nascimento = nascimento;
    this->altura = altura;
}

string pessoa::getNome(){
    return this->nome;
}

data* pessoa::getNascimento(){
    return this->nascimento;
}

float pessoa::getAltura(){
    return this->altura;
}

void pessoa::setNome(string nome){
    this->nome = nome;
}

void pessoa::setNascimento(data *Data){
    this->nascimento = Data;
}

void pessoa::setAltura(float altura){
    this->altura = altura;
}

void pessoa::idadeCalc(data* nascimento){
    this->idade = (2018 - nascimento->getAno());
}

void pessoa::mostrarPessoa(data* nascimento){
    cout << "Nome: " << this->nome << endl;
    cout << "Data de Nascimento: " << nascimento->getAno() << endl;
    cout << "Altura: " << this->altura << " metros" << endl;
    cout << "Idade: " << this->idade << " anos" << endl;
}

pessoa::~pessoa(){
    cout << "Destruindo o objeto: ..." << endl;
}
