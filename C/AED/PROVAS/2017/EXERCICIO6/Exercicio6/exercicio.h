#ifndef EXERCICIO_H
#define EXERCICIO_H
#include <stdio.h>
#include <stdlib.h>

//estrutura do nó duplamente encadeado circular
typedef struct no Lista;

//criar lista
Lista* criar_lista ();

//testa se a lista é vazia
//entrada: ponteiro para a estrutura
//retorno: 1 se alista é vazia ou 0 caso contrário
//pré-condicão: lista
//pós-condicão: nenhuma
int vazia (Lista* l);

//insere o elemento na cabeca da lista
//entrada: lista
//retorno: lista alterada
//pré-condicão: nenhuma
//pós-condicão: elemento é inserido na cabeca da lista;
Lista* insere (Lista* l, int info);

//remove elemento da lista
//entada: lista
//retorno: lista alterada
//pré-condicão: nenhuma
//pos-condicão: elemento é removido da lista
Lista* retirar(Lista* l, int info);

//imprime lista
void imprime(Lista* l);

#endif // EXERCICIO_H

