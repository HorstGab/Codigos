#ifndef ARVOREB
#define ARVOREB

#include <stdio.h>
#include <stdlib.h>

#define ORDEM 5
//estrutura de no para arvore B:
//ha 1 posic~ao a mais de chave e ponteiro de filho para
//facilitar a implementac~ao da operac~ao split
typedef struct no {
    int numChaves;
    int chave[ORDEM];
    struct no* filho[ORDEM+1];
} arvoreB;

arvoreB* insere(arvoreB* r, int info);

void insere_aux(arvoreB* r, int info);

void adicionaDireita(arvoreB* r, int pos, int k, arvoreB* p);

int buscaPos(arvoreB* r, int info, int * pos);

int eh_folha(arvoreB* r);

arvoreB* split(arvoreB* x, int * m);

int vazia(arvoreB* r);

int maximo(arvoreB* r);

int minimo(arvoreB* r);

int contaNosMinChaves(arvoreB* r);
#endif // ARVOREB

