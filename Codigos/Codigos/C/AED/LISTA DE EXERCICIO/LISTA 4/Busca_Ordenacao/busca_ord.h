#ifndef BUSCA_ORD
#define BUSCA_ORD

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _no{
    int info;
    struct _no* prox;
    struct _no* ant;
}No;

typedef struct lista{
   No* cabeca;
   No* cauda;
}Lista;

int posicao_valor (int vet[], int tam);
void selectionSort (int vet[], int tam, int index);
void swap(int vet[], int min, int index);
void insertionSortList(No* no);
void selectionSortParcial(int vet[], int tam, int k);

#endif // BUSCA_ORD

