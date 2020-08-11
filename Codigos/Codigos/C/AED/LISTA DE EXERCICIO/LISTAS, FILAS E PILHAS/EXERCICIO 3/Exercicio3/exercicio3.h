#ifndef EXERCICIO3_H
#define EXERCICIO3
#include <stdio.h>
#include <stdlib.h>

// estrutura de no para lista encadeada
struct no;

// estrutura para lista encadeada com cabeeca e cauda
typedef struct Lista Lista;

//criar uma nova lista
//entrada: nenhum
//retorno: ponteiro nulo;
//pré-condicão: nenhuma
//pos-condicão: nenhuma
Lista* criar_lista();

//testa se a lista é vazia
//Entrada: lista
//retorno: 1 se a lista for vazia e 0 caso contrario
//pré-condicão: nenhuma
//pós-condicão: nenhuma
int vazia(Lista* li);

//inserir um elemento na cabeca da lista
//entrada: lista e um valor a ser inserido
//retorno: lista modificada
//pré-condicão: nenhuma
//pós-condicão: elemento inserido na lista
Lista* insere_cabeca(Lista* li, int info);

//inserir um elemento na cauda da lista
//entrada: lista e valor a ser inserido
//retorno: lista modificada
//pré-condicão: a lista ter uma cabeca não nula
//pós-condicão: elemento inserido na cauda da lista
Lista* insere_cauda(Lista* li, int info);


//remover um dado elemento da lista
//entrada: lista e valor a ser inserido
//retorno: lista modificada
//pré-condicão: lista não vazia
//pós-condicão: elemento é removido da lista
Lista* remover(Lista* li, int info);

// Imprime os elementos da lista
// Entrada: lista
// Retorno: nenhum
// Pre-condicao: nenhuma
// Pos-condicao: os elementos sao impressos no console
void imprime(Lista* li);


#endif // EXERCICIO3_Hra
