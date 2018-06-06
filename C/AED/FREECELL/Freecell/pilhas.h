#ifndef PILHAS_H
#define PILHAS_H

#include <stdio.h>
#include <stdlib.h>

//estrutura para a carta

typedef struct _carta{
    int naipe;
    int valor;
} Carta;

typedef struct _no{
    Carta* carta;
    struct _no* prox;
} No;

typedef struct _pilha{
    int tamanho;
    No* inicio;
    No* fim;
} Pilha;

//estrutura para a mesa
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
 * @return
 */
Pilha* criar_pilha();

//insere as cartas na mesa
/**
 * @brief insere_carta
 * @param pilha
 * @param carta
 * @return
 */
Pilha* insere_carta(Pilha* pilha, Carta* carta);

// cria um novo no
/**
 * @brief criar_no
 * @param carta
 * @return
 */
No* criar_no(Carta* carta);

//remove um elemento da pilha
/**
 * @brief pop
 * @param pilha
 * @return
 */
No *pop(Pilha *pilha);

/**
 * @brief inverte_pilha
 * @param pilha
 * @param pilha_reversa
 * @param andares
 */
void inverte_pilha(Pilha* pilha[], No* pilha_reversa[], int *andares);

/**
 * @brief inverte_lista
 * @param no
 * @return
 */
No* inverte_lista(No* no);

/**
 * @brief insere_no_cauda
 * @param lista
 * @param carta
 * @return
 */
No* insere_no_cauda(No* lista, Carta* carta);


#endif // PILHAS_H

