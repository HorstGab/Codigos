#include "pessoa.h"
#include <string.h>
#include <stdlib.h>


ostream &operator<< (ostream &output, Pessoa &p){

}

Pessoa::Pessoa(int idpessoa, char *nome){
    this->idpessoa = idpessoa;
    this->nome = (char*)malloc(strlen(nome)+1);
    strcpy(this->nome, nome);
}

char* Pessoa::getnome(){
    return this->nome;
}

int Pessoa::getIdPessoa(){
    return this->idpessoa;
}

bool Pessoa::operator<(Pessoa &p){
    return(strcmp(this->name, p.getnome()) < 0);
}

bool Pessoa::operator>(Pessoa &p){
    return(strcmp(this->name, p.getnome()) > 0);
}

Pessoa::~Pessoa(){
    free(this->nome);
}
