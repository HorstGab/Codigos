#include "movimentacao.h"

movimentacao::movimentacao(string descricao, double valor, tipo_transacao tt){
    this->descricao = descricao;
    this->valor = valor;
    this->tt = tt;
    this->prox = NULL;
}

//fila de movimentacoes
void movimentacao::adiciona(movimentacao **h, string descricao, double valor, tipo_transacao tipo){
    if(*h){
        adiciona(&(*h)->prox, descricao, valor, tipo);
    }else{
        (*h) = new movimentacao(descricao, valor,tipo);
    }
}

string movimentacao::getTipo() const{
    if(this->tt == credito) {
        return "credito";
    }
    return "debito";
}

void movimentacao::listar(){
    movimentacao* aux = this;
    while(aux){
        cout << aux->descricao << endl;
        cout << "Valor: " << aux->valor << endl;
        cout << "Tipo: " << aux->tt << endl;

        aux = aux->prox;
    }
}

movimentacao::~movimentacao(){
    if(prox) delete prox;
}
