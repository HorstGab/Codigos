#include "exercicio.h"

struct no{
    int info;
    struct no* prox;
};

typedef struct fila{
    struct no* inicio;
    struct no* fim;
}Fila;

Fila* criar_fila(){
    Fila* f = (Fila*)malloc(sizeof(Fila));
    if(f != NULL){
        f->fim = NULL;
        f->inicio = NULL;
    }
    return f;
}

void enqueue(Fila *f, int info){
    struct no* novo = (struct no*)malloc(sizeof(struct no));
    novo->prox = NULL;
    novo->info = info;
    if(f->inicio == NULL){
        f->inicio = novo;
        f->fim = novo;
    }else{
        f->fim->prox = novo;
        f->fim = novo;
    }
}

int dequeue(Fila *f){
    struct no* ptr;
    int aux;
    if(f->inicio == NULL) return 0;
    if(f->inicio == f->fim) f->fim = NULL;

    aux = f->inicio->info;
    ptr = f->inicio->prox;
    free(f->inicio);
    f->inicio = ptr;

    return aux;
}

void imprime(Fila *f){
    struct no* aux = f->inicio;
    while(aux != NULL){
        printf("-> %d", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}
