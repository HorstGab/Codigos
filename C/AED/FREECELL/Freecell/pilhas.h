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
    Pilha* fundacoes[4];//vetor de pilhas homecell
    Carta* celulas[4];//vetor de cartas freecell
    Pilha* pilhas[8];//vetor de pilhas tableau
} Mesa;


//cria uma pilha vazia
Pilha* criar_pilha();

//insere as cartas na mesa
Pilha* insere_carta(Pilha* pilha, Carta* carta);

// cria um novo no
No* criar_no(Carta* carta);

//remove um elemento da pilha
No *pop(Pilha *pilha);

void inverte_pilha(Pilha* pilha[], No* pilha_reversa[], int *andares);

No* inverte_lista(No* no);

No* insere_no_cauda(No* lista, Carta* carta);


#endif // PILHAS_H

