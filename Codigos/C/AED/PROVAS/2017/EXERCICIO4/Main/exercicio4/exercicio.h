#ifndef EXERCICIO_H
#define EXERCICIO_H
#include <stdio.h>
#include <stdlib.h>

//estrutura de nó
struct no;

typedef struct fila Fila;

Fila* criar_fila();

//insere um elemento na fila
//entrada: fila e elemento
//retorno: nenhum;
//pre-condicao: ponteiro nao nulo para estrutura Fila
//pos-condicao: elemento e inserido na fila
void enqueue (Fila* f, int info);

//retira um elemento da fila
//entrada: fila
//retorno: elemento retirado
//pre-condicão: ponteiro nao nulo para estrutura Fila
//pos-condicao: um elemento eh retirado da fila
int dequeue (Fila* f);

void imprime(Fila* f);

#endif // EXERCICIO_H

