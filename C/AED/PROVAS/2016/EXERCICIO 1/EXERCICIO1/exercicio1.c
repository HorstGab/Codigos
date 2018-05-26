#include "exercicio1.h"

struct no{
    int info;
    struct no* prox;
};
struct no* cria_lista(){
    return NULL;
}

int vazia(struct no *l){
    return (l == NULL);
}

struct no* insere(struct no* li, int info){
    struct no* novo = (struct no*) malloc(sizeof(struct no));

        novo->info = info;
        novo->prox = li;

    return novo;

}

struct no* inserir_apos(struct no *l, int info_ref, int info){
    struct no* ptr = l;
    int aux = NULL;
    if(!vazia(l)){
        while(ptr != NULL || ptr->info == info_ref){
            struct no* novo = (struct no*) malloc(sizeof(struct no));
            novo->prox = ptr->prox;
            ptr->prox = novo;
            novo->info = info;
            printf("inseriu apos \n");
            aux = 1;
            ptr = ptr->prox;
            return l;
            }
        if(aux == NULL){
            struct no* novo = (struct no*) malloc(sizeof(struct no));
            ptr->prox = novo;
            novo->info = info;
            novo->prox = NULL;
            printf("inseriu no fim \n");
            return l;
        }
    }
    return l;
}

void imprime(struct no* l){
    struct no* ptr = l;
    while(ptr != NULL){
        printf("-> %d", ptr->info);
        ptr = ptr->prox;
    }
    printf("\n");
}
