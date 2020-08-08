#include "exercicio4.h"


typedef struct no { //estrutura para lista duplamente encadeada
    int info;
    Lista * ant; // ponteiro para o elemento anterior
    Lista * prox; // ponteiro para proximo elemento
} Lista;

Lista* cria_lista(){
    return NULL;
}

int vazia(Lista *li){
    return (li == NULL);
}

Lista* insere(Lista *li, int info){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = info;
    if(vazia(li)){
        li = novo;
        novo->ant = NULL;
        novo->prox = NULL;
    }else{
        novo->prox = li;
        li->ant = novo;
        novo->ant = NULL;
    }
    return li;
}

Lista* remover(Lista *li, int info){
    Lista* ptr = NULL;
    if(!li) return NULL;

    if(li->prox == info){
        ptr = li->prox;
        free(li);
        return ptr;
    }
    if(li->prox && li->prox->info == info){
        ptr = li->prox->prox;
        free(li->prox);
        li->prox = ptr;
    }else
        li->prox = remover(li->prox, info);
}

void imprime(Lista *li){
    if(!vazia(li)){
        Lista* ptr  = li;
        while(ptr != NULL){
            printf("-> %d", ptr->info);
            ptr = ptr->prox;
        }
    }
}
