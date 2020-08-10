#ifndef EXERC1_REC
#define EXERC1_REC
#include <stdio.h>
#include <stdlib.h>

// estrutura de no para lista encadeada
typedef struct no Lista;

//cria uma nova lista
//Entrada: nenhuma
//Retorno: Nova Lista
//Pre-condicao:Nenhuma
//Pos-condicão:Lista criada
Lista* criarLista();

// Testa se uma lista eh vazia
// Entrada: lista
// Retorno: 1 se a lista eh vazia ou 0 caso contrario
// Pre-condicao: nenhuma
// Pos-condicao: nenhuma
int vazia(Lista * l);


// Insere um elemento na lista
// Entrada: lista e elemento a ser inserido
// Retorno: lista alterada
// Pre-condicao: nenhuma
// Pos-condicao: elemento eh inserido na lista
Lista* insere(Lista* li, int info);



// Remove um elemento da lista
// Entrada: lista e elemento a ser removido
// Retorno: lista alterada
// Pre-condicao: nenhuma
// Pos-condicao: elemento eh removido da lista
Lista* remover(Lista* l, int info);


// Imprime os elementos da lista
// Entrada: lista
// Retorno: nenhum
// Pre-condicao: nenhuma
// Pos-condicao: os elementos sao impressos no console
void imprime(Lista* li);


// Inverte uma lista
// Entrada: lista
// Retorno: lista invertida
// Pre-condic~ao: nenhuma
// Pos-condic~ao: lista original n~ao e modificada
//Lista* inverte(Lista* l);


// Concatena duas listas
// Entrada: listas a serem concatenadas
// Retorno: lista resultante da concatenac~ao
// Pre-condic~ao: nenhuma
// Pos-condic~ao: listas originais n~ao s~ao modificadas
//Lista* concatena(Lista* l1, Lista* l2);


// Intercala duas listas
// Entrada: listas a serem intercaladas
// Retorno: lista resultante da intercalac~ao
// Pre-condic~ao: nenhuma
// Pos-condic~ao: listas originais permanecem inalteradas
//Lista* merge(Lista* l1, Lista* l2);

#endif // EXERC1_REC

