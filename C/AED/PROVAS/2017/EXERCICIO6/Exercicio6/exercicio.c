#include "exercicio.h"

typedef struct no{
    int info;
    Lista* ant;
    Lista* prox;
}Lista;

Lista* criar_lista(){
    return NULL;
}

int vazia(Lista *l){
    return (l == NULL);
}

Lista* insere(Lista *l, int info){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = info;

    if(vazia(l)){
        novo->prox = novo->ant;
        novo->ant = novo->prox;
        return novo;
    }else{
        novo->prox = l;
        l->ant->prox = novo;
        novo->ant = l->ant;
        l->ant = novo;
        return l;
    }
}

/*Lista* retirar(Lista *l, int info){

}*/

void imprime(Lista *l){
    Lista* ptr = l;

    if(!l) printf("vazia\n");

    while(ptr != l->ant){
        printf("-> %d", ptr->info);
        ptr = ptr->prox;
    }
    printf("\n");
}
