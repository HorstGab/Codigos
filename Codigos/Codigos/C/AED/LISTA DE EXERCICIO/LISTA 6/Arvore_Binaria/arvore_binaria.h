#ifndef ARVORE_BINARIA
#define ARVORE_BINARIA

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    struct no* esquerda;
    struct no* direita;
}arvore;

//testa se uma arvore é vazia
int vazia(arvore* r);

//passa cada elemento do vetor para ser inserido na arvore
arvore* insere(arvore* r, int vet[], int tam);

//insere um elemento na arvore
arvore* insere_Arvore_Binaria(arvore* r, int x);

//remove um elemento da arvore
arvore* remove_Arvore_Binaria(arvore* r, int x);

int minimo(arvore* r);

int maximo(arvore* r);

//mostra na tela a arvore
void mostrar_arvore(arvore* r);

void in_ordem(arvore* r);

void pre_ordem(arvore* r);

void pos_ordem(arvore* r);

int altura(arvore* r);

int soma(arvore* r);

#endif // ARVORE_BINARIA

