#ifndef CARTAS_H
#define CARTAS_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "start.h"
#include "comandos.h"
#include "pilhas.h"

#define MAX 100

//estrutura para a carta
typedef struct _carta{
    int naipe;
    int valor;
}Carta;

typedef struct _no{
    Carta* carta;
    struct no* prox;
}No;

typedef struct _pilha{
    int tamanho;
    No* inicio;
    No* fim;
}Pilha;

//estrutura para a mesa
typedef struct _mesa{
    int celula_livre;
    int qnt_pilha_livre;
    Pilha* fundacoes[4];//vetor de pilhas homecell
    Carta* celulas[4];//vetor de cartas freecell
    Pilha* pilhas[8];//vetor de pilhas tableau
}Mesa;


#endif // CARTAS_H

