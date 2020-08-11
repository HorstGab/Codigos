#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "maquinaturing.h"
#include <string.h>

#define MAX 256


class Arquivo
{
private:
    FILE *arquivo;
    maquinaTuring *maqT;

public:
    Arquivo(char const *str);

    maquinaTuring *inicializarMaquina();

    void leQuantidadeEstados(FILE *arq);

    void lerEstadosFinais(FILE *arq);

    void lerAlfabeto(FILE *arq);

    void lerTransicao(FILE *arq);
};

#endif // ARQUIVO_H
