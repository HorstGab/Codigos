#include "estado.h"

Estado::Estado(string *nome)
{
    this->transicao = new vector<Transicao*>();
    this->nome = nome;
    this->final = false;
}

string *Estado::getNome()
{
    return nome;
}

void Estado::adicionarTransicao(char simboloL, char simboloE, Estado *estado, int direcao)
{
    this->transicao->push_back(new Transicao(simboloL,simboloE, estado, direcao));
}

Transicao *Estado::getTransicao(char simbolo)
{
    int tam = this->transicao->size();
    int i;

    // loop para percorrer a lista de transicoes
    for(i = 0; i < tam; i++){
        if(this->transicao->at(i)->simboloLido == simbolo){
            return this->transicao->at(i);
        }
    }
    return NULL;
}
