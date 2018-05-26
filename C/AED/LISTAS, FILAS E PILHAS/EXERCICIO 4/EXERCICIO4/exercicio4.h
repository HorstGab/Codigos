#ifndef EXERCICIO4_H
#define EXERCICIO4
#include <stdio.h>
#include<stdlib.h>

//estrutura para a lista duplamente encadeada
typedef struct no Lista;

//cria uma lista
//entrada: nenhuma
//retorn: ponteiro nulo
//pre-condicao: nenhuma
//pos-condicao: lista e criada
Lista* cria_lista();

// Testa se uma lista e vazia
// Entrada: lista
// Retorno: 1 se a lista e vazia ou 0 caso contrario
// Pre-condic~ao: nenhuma
// Pos-condic~ao: nenhuma
int vazia(Lista * li);

// Insere um elemento na lista
// Entrada: lista e elemento a ser inserido
// Retorno: lista alterada
// Pre-condic~ao: nenhuma
// Pos-condic~ao: elemento e inserido na lista
Lista* insere(Lista* li, int info);

// Remove um elemento da lista
// Entrada: lista e elemento a ser removido
// Retorno: lista alterada
// Pre-condic~ao: nenhuma
// Pos-condic~ao: elemento e removido da lista
Lista* remover(Lista* li, int info);

// Imprime os elementos da lista
// Entrada: lista
// Retorno: nenhum
// Pre-condic~ao: nenhuma
// Pos-condic~ao: os elementos s~ao impressos no console
void imprime(Lista* li);

// Inverte uma lista
// Entrada: lista
// Retorno: lista invertida
// Pre-condic~ao: nenhuma
// Pos-condic~ao: lista original n~ao e modificada
Lista* inverte(Lista* li);

// Concatena duas listas
// Entrada: listas a serem concatenadas
// Retorno: lista resultante da concatenac~ao
// Pre-condic~ao: nenhuma
// Pos-condic~ao: listas originais n~ao s~ao modificadas
Lista* concatena(Lista* l1, Lista* l2);

#endif // EXERCICIO4_H

