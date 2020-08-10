#include "transicao.h"

Transicao::Transicao(char simboloL, char simboloE, Estado *estado, int direcao )
{
    this->simboloLido = simboloL;
    this->simboloEsc = simboloE;
    this->estado = estado;
    this->direcao = direcao;
}

