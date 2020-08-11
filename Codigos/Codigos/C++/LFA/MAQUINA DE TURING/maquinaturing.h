#ifndef MAQUINATURING_H
#define MAQUINATURING_H

#include<iostream>
#include<string>
#include<vector>

#include "estado.h"

using namespace std;

class maquinaTuring
{
private:
    vector<Estado*> *estados;
    vector<char> *alfabeto;
    Estado *estadoInicial;

public:

    maquinaTuring();

    /**
     * @brief adicionarEstado, adiciona o estado a maquinoa
     * @param nome, nome do Estado
     * @return estado adicionarEstado()
     * Pre-condicao: nenhuma
     * Pos-condicao: Estado e adicionado a lista da maquina
     */
    Estado *adicionarEstado(string *nome);

    /**
     * @brief encontrarEstado
     * @param nome
     * @return
     * Pre-condicao:
     * Pos-condicao:
     */
    Estado *encontrarEstado(string *nome);

    /**
     * @brief setEstadoInicial, inicializa a maquina
     */
    void setEstadoInicial();

    void adicionarSimbolo(char simbolo);

    bool contemSimbolo(char simbolo);

    bool movimentoValido(int direcao);

    void testaSequencia(string *sequencia);

    bool testeSequenciaDoEstado(string *sequencia,int posicao, Estado *estadoAtual);

    void criarTransicao(string *nomeOrigem, char simboloLido, string *nomeDestino, char simboloEscrito, int direcao);

    void novoSimbolo(char simbolo);
};

#endif // MAQUINATURING_H
