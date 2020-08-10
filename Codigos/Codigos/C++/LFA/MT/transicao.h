#ifndef TRANSICAO_H
#define TRANSICAO_H

#include <vector>

#include "estado.h"

class Estado;

class Transicao
{
public:
    char simboloLido;
    char simboloEsc;
    int direcao;
    Estado *estado;
    /**
     * @brief Transicao, inicializa os campos
     * @param simboloL, simbolo lido
     * @param simboloE, simbolo escrito
     * @param estado, estado de chegada
     * @param direcao, direcao do movimento
     */
    Transicao(char simboloL, char simboloE, Estado *estado, int direcao );
};

#endif // TRANSICAO_H
