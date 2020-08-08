#ifndef PILHAS_H
#define PILHAS_H

#include <stdio.h>
#include <stdlib.h>

//estrutura da carta
typedef struct _carta{
    int naipe;
    int valor;
} Carta;

//estrutura do no
typedef struct _no{
    Carta* carta;
    struct _no* prox;
} No;

//estrutura da pilha
typedef struct _pilha{
    int tamanho;
    No* inicio;
    No* fim;
} Pilha;

//estrutura da mesa
typedef struct _mesa{
    int celula_livre;
    int qnt_pilha_livre;
    Pilha* fundacoes[4];//vetor de pilhas
    Carta* celulas[4];//vetor de cartas
    Pilha* pilhas[8];//vetor de pilhas
} Mesa;


//cria uma pilha vazia
/**
 * @brief criar_pilha
 * @param nenhuma
 * @return nova pilha
 * @pre-condicao nenhuma
 * @pos-condicao pilha criada
 */
Pilha* criar_pilha();

//insere as cartas na mesa
/**
 * @brief insere_carta
 * @param pilha
 * @param carta a ser inserida na pilha
 * @return pilha ou uma nova pilha se a anterior nao existir
 * @pre-condicao nenhuma
 * @pos-condicao carta inserida na pilha
 */
Pilha* insere_carta(Pilha* pilha, Carta* carta);

// cria um novo no
/**
 * @brief criar_no
 * @param carta
 * @return novo no
 * @pre-condicao nenhuma
 * @pos-condicao cria um novo no da carta
 */
No* criar_no(Carta* carta);

//remove um elemento da pilha
/**
 * @brief pop
 * @param pilha
 * @return retorna o topo da pilha
 * @pre-condicao nenhuma
 * @pos-condicao o topo eh removida da pilha
 */
No *pop(Pilha *pilha);

//inverte as pilha
/**
 * @brief inverte_pilha
 * @param pilha
 * @param pilha_reversa
 * @param andares
 * @return nenhum
 * @pre-condicao nenhuma
 * @pos-condicao a pilha eh invertida
 */
void inverte_pilha(Pilha* pilha[], No* pilha_reversa[], int *andares);

//inverte uma pilha
/**
 * @brief inverte_lista
 * @param no
 * @return cabeça de uma cópia da lista invertida
 * @pre-condicao nenhuma
 * @pos-condicao nenhuma
 */
No* inverte_lista(No* no);

//insere um no na cauda
/**
 * @brief insere_no_cauda
 * @param lista
 * @param carta
 * @return lista alterada
 * @pre-condicao nenhuma
 * @pos-condicao no inserido na cauda
 */
No* insere_no_cauda(No* lista, Carta* carta);

#endif // PILHAS_H

