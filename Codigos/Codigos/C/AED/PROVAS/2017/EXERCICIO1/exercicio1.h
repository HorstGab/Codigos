#ifndef EXERCICIO1_H
#define EXERCICIO1_H
#include <stdio.h>
#include <stdlib.h>

//estrutura de nó para a lista
typedef struct no Lista;

//cria lista
Lista* cria_lista();

//testa se a lista é vazia
//entrada: lista
//retorno: 1 se a lista é vazia e 0 caso contrario
//pre-condicao: nenhuma
//pos-condicao: nenhuma
int vazia(Lista* l);

//insere
Lista* insere(Lista* l, int info);

//cria uma lista com os numeros impares da lista informada
//entrada: lista
//retorno: lista de numeros impares
//pre-condicao: nenhuma
//pos-condicao: retorna uma nova lista com os numeros impares mantendo
//              a lista orignal
Lista* impares(Lista* l);

//remove os elementos que estejam em um intervalo dado
//entrada: lista e intervalo fechado [a,b]
//retorno: lista
//pre-condicao: a <= b
//pos-condicão: lista modifiada sem numeros no intervalo fechado [a,b]
Lista* remove_intervalo(Lista* l, int a, int b);

//retorna o valor maximo presente na lista
//entrada: lista
//retorno: valor maximo presente na lista ou -1 caso seja vazia
//pre-condicao: nenhuma
//pos-condicao:nenhuma
int maximo(Lista* l);

//imprime
void imprime(Lista* l);

#endif // EXERCICIO1_H

