#include "exerc1_rec.h"

//estrutura da lista dinamica
typedef struct no {
    int info;
    struct no *prox;
}Lista;


Lista* criarLista(){
    return NULL;
}

int vazia(Lista *l){
    return (l == NULL);
}

Lista* insere(Lista *li, int info){
    Lista* novo = NULL;
    Lista* ptr = NULL;
    if(!li || li->info > info){
        novo = (Lista*) malloc(sizeof(Lista));
        novo->info = info;
        novo->prox = li;
        return novo;
    }
    if(!li->prox || li->prox->info > info){
       novo = (Lista*) malloc(sizeof(Lista));
       novo->info = info;
       ptr = li->prox;
       li->prox = novo;
       novo->prox = ptr;
    }else{
       li->prox = insere(li->prox,info);
    }
    return li;
}

Lista* remover(Lista* l, int info){
    Lista* ptr = NULL;

    if(!l) return NULL;

    if(l->prox == info){
        ptr = l->prox;
        free(l);
        return ptr;
    }
    if(l->prox && l->prox->info == info){
        ptr = l->prox->prox;
        free(l->prox);
        l->prox = ptr;
    }else{
        l->prox = remover (l->prox, info);
    }
    return l;
}

void imprime(Lista *li){
    if(li != NULL){
        printf("-> %d", li->info);
        imprime(li->prox);
    }
}
