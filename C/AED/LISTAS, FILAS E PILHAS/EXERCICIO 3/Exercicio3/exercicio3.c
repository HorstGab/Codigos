#include "exercicio3.h"


typedef struct no {
    int info;
    struct no * prox;
}no;

typedef struct Lista{
     no* cabeca;
     no* cauda;
} Lista;
Lista* criar_lista(){
   Lista* li = (Lista*) malloc(sizeof(Lista));
   if(li){
       li->cabeca = NULL;
       li->cauda = NULL;
   }
   return li;
}

int vazia(Lista* li){
    return (li->cabeca == NULL);
}

Lista* insere_cabeca(Lista* li, int info){
    no* novo = (no*)malloc(sizeof(no));
    if(vazia(li)){
        li->cabeca = novo;
        novo->info = info;
        novo->prox = NULL;
        li->cauda = novo;
    }else
        novo->prox = li->cabeca;
        novo->info = info;
        li->cabeca = novo;

    return li;
}

Lista* insere_cauda(Lista *li, int info){
    if(vazia(li)){
        return insere_cabeca(li, info);
    }else{
        no* novo = (no*) malloc(sizeof(no));
        li->cauda->prox = novo;
        li->cauda = novo;
        novo->prox = NULL;
        novo->info = info;
        return li;
    }
}

Lista* remover(Lista *li, int info){
    no* ptr = li->cabeca;
    no* prevPtr = NULL;
    if(vazia(li)){
        return NULL;
    }else{
        while(ptr != NULL){
            if(ptr->info == info){
                if(ptr == li->cabeca){
                    li->cabeca = ptr->prox;
                    free(ptr);
                    ptr = li->cabeca;
                }else
                    if(ptr == li->cauda){
                        prevPtr->prox = NULL;
                        li->cauda = prevPtr;
                        free(ptr);
                        ptr = NULL;
                    }else{
                        prevPtr->prox = ptr->prox;
                        free(ptr);
                        ptr = prevPtr->prox;
                    }
            }else{
                prevPtr = ptr;
                ptr = ptr->prox;
            }
        }
    }
    return li;
}

void imprime(Lista *li){
    no* ptr = li->cabeca;
    while(ptr != NULL){
        printf("-> %d", ptr->info);
        ptr = ptr->prox;
    }
    printf("\n");
}
