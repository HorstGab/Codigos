#include "pessoa.h"

#include <string.h>
#include <stdlib.h>

ostream &operator<<(ostream &output, Pessoa &p) {
    output << "Pessoa: " << p.idpessoa << " "
           << p.nome;
    return output;
}

ostream &operator<<(ostream &output, Pessoa *p) {
    output << "Pessoa: " << p->idpessoa << " "
           << p->nome;
    return output;
}

Pessoa::Pessoa(int idpessoa, char nome[] ) {
    this->idpessoa = idpessoa;
    strcpy_s ( this->nome, 100, nome );
}

Pessoa::Pessoa(const Pessoa&p) {
    this->idpessoa = p.idpessoa;
    strcpy_s ( this->nome, 100, p.nome );
}

char *Pessoa::getNome() {
    return this->nome;
}

int  Pessoa::getIdPessoa() {
    return this->idpessoa;
}

bool Pessoa::operator>(Pessoa &p) {
    return (strcmp(this->nome,p.nome)>0);
    //return this->idpessoa>p.idpessoa;
}

bool Pessoa::operator>(Pessoa *p) {
    return (strcmp(this->nome,p->nome)>0);
    //return this->idpessoa>p.idpessoa;
}

Pessoa::~Pessoa() {
}

