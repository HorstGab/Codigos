#include "data.h"

data::data(){
    this->dia = 0;
    this->mes = 0;
    this->ano = 0;
}

data::data(int dia, int mes, int ano){
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
}

int data::getDia(){
    return this->dia;
}

int data::getMes(){
    return this->mes;
}

int data::getAno(){
    return this->ano;
}

void data::setDia(int dia){
    this->dia = dia;
}

void data::setMes(int mes){
    this->mes = mes;
}

void data::setAno(int ano){
    this->ano = ano;
}

void data::diferenca(data *Data){
        cout << "Dias: " << abs(this->dia - Data->dia) << endl;
        cout << "Mes: " << abs(this->mes - Data->mes) << endl;
        cout << "Ano: " << abs(this->ano - Data->ano) << endl;
}

bool data::bissexto(data *Data){
    return (Data->ano % 4 == 0) && ((Data->ano % 100 != 0) || (Data->ano % 400 == 0));
}

data::~data(){
    cout << "Destruindo o objeto ..." << endl;
}
