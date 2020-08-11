#ifndef MOVIMENTACAO_H
#define MOVIMENTACAO_H

#include <iostream>
using namespace std;

enum tipo_transacao {debito,credito};

class movimentacao{
private:
    string descricao;
    double valor;
    tipo_transacao tt;
    movimentacao* prox;
public:

    movimentacao(string descricao, double valor, tipo_transacao tt);
    string getTipo() const;
    static void adiciona(movimentacao **h, string descricao, double valor, tipo_transacao tipo);
    void listar();

    ~movimentacao();
};

#endif // MOVIMENTACAO_H
