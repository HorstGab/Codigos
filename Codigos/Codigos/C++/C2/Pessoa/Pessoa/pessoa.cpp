#include "pessoa.h"
#include<iostream>

using namespace std;

Pessoa::Pessoa()
{
    this->nome[0] = '\0'; // qlqr metodo ou qlqr atributo posso usar o 'this' significa a instancia desta classe; endereco do objeto deslocado
    this->endereco[0] = '\0'; // this é interno da classe
}

void Pessoa::setar()
{
    char newLine;
    cout <<"Digite o nome:";
    cin.get(this->nome, 30, '\n');
    cin.get(newLine);
    cout << "Digite o endereco: ";
    cin.get(this->endereco, 40, '\n');
    cin.get(newLine);
}
void Pessoa::mostrar()
{
    cout << "\nNome: " << nome;
    cout << "\nEndereco: " << endereco;
}

Pessoa:: ~Pessoa(void){
    cout <<"\nLiberando a memoria alocada para Pessoa\n";
}
