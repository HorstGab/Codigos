#ifndef EXERCICIO1_H
#define EXERCICIO1_H
#include <stdio.h>
#include <stdlib.h>

//estrutura do no da lista encadeada
struct no;

// cria lista
struct no* cria_lista();

//testa se uma lista é vazia
//entrada: lista
//retorno: 1 se a lista for vazia e 0 caso contrario
//pre-condicão: nenhuma
//pos-condicão: nenhuma
int vazia(struct no* l);

//insere na lista
struct no* insere(struct no* li, int info);

//insere um elemento apos o elemento indicado, ou no fim da lista
//caso o elemento indicado não esteja na lista
//entrada: lista, elemento de referencia, elemento a ser inserido
//retorno: lista alterada
//pre-condicão: nenhuma
//pos-condicão: elemento inserido na lista
struct no* inserir_apos(struct no* l, int info_ref, int info);

//elimina as repeticoes de uma lista
//entrada: lista
//retorno: lista alterada
//pre-condicão: nenhuma
//pos-condicão: lista sem elementos repetidos
struct no* eliminar_repetidos(struct no* l);

//conta o numero de ocorrencias de um elemento em uma lista
//entrada: lista e elemento procurado
//retorno: numero de ocorrencias do elemento informado
//pre-condicao: nenhuma
//pos-condicao: nenhuma
int contar_ocorrencias (struct no* l, int x);

//criar uma lista contendo os elementos menores que um valor de referencia
//entrada: lista e valor de referencia
//retorno: uma nova lista contendo os elementos menores que o valor de referencia
//pre-condicao: nenhuma
//pos-condicao: nenhuma
struct no* menores(struct no* l, int val_ref);

//imprime lista
void imprime(struct no* l);


#endif // EXERCICIO1_H

