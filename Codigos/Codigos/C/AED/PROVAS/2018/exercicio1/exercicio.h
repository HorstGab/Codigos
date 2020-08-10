#ifndef EXERCICIO_H
#define EXERCICIO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct no Lista;

Lista* cria_lista();
Lista* insere(Lista* li, int info);
int conta_ocorrencias(Lista* l, int x);
Lista* remover_enesimo(Lista* l, int n);
void imprime(Lista* li);



#endif // EXERCICIO_H

