#ifndef ARVORE23
#define ARVORE23

#include <stdio.h>
#include <stdlib.h>

struct no23{
    int chave_esq;
    int chave_dir;
    struct no23* esq;
    struct no23* meio;
    struct no23* dir;
    int n;
};

typedef struct no23* arvore23;

arvore23 busca (arvore23 r, int chave);

int vazia(arvore23 r);

arvore23 inserir (arvore23 r, int chave);

arvore23 inserir_aux (arvore23 r, int chave, int *chave_promovida);

arvore23 split (arvore23 p, int chave, arvore23 subarvore, int *chave_promovida);

void adicionaChave (arvore23 r, int chave, arvore23 p);

int eh_folha(arvore23 r);

arvore23 criaNo23 (int chave_esq, int chave_dir, arvore23 esq, arvore23  meio, arvore23 dir, int n);

int minimo (arvore23 r);

int maximo (arvore23 r);

int conta_nos(arvore23 r);

void in_ordem(arvore23 r);

void mostraArvore(arvore23 a);

#endif // ARVORE23

