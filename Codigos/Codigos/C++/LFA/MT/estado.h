#ifndef ESTADO_H
#define ESTADO_H

#include<iostream>
#include<vector>

#include"transicao.h"
using namespace std;

class Transicao;

class Estado
{
public:
    string *nome;
    vector<Transicao*> *transicao;
    bool final;

    /**
     * @brief Estado::Estado, inicializa o estado
     * @param nome, nome do estado
     * Pre-condicao: nenhuma
     * Pos-condicao: estado inicializado
     */
    Estado(string *nome);

    /**
     * @brief Estado::getNome
     * @return nome do estsado
     * Pre-condicao: nenhuma
     * Pos-condicaoo: nenhuma
     */
    string *getNome();

    /**
     * @brief adicionarTransicao, adiciona transicao
     * @param simboloL, simbolo lido
     * @param simboloE, simbolo escrito
     * @param estado, estado de chegada
     * @param direcao, direcao movimento
     * Pre-condicao: nenhuma
     * Pos-condicao: nenhuma
     */
    void adicionarTransicao(char simboloL, char simboloE, Estado *estado, int direcao);

    /**
     * @brief getTransicao
     * @param simbolo, simbolo de leitura
     * @return transicao
     * Pre-condicao: nenhuma
     * Pos-condicao: nenhuma
     */
    Transicao *getTransicao(char simbolo);

    ~Estado();

};

#endif // ESTADO_H
