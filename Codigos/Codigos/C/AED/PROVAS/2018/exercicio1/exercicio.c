#include "exercicio.h"

typedef struct no{
    int info;
    Lista* prox;
}Lista;


Lista* cria_lista(){
    return NULL;
}

Lista* insere(Lista* li, int info){
    Lista* novo = (Lista*) malloc(sizeof(Lista));

        novo->info = info;
        novo->prox = li;

    return novo;

}

int conta_ocorrencias(Lista* l, int x){
    if(l != NULL){
        if(l->info == x){
            return 1 + conta_ocorrencias(l->prox, x);
        }else{
            return conta_ocorrencias(l->prox, x);
        }
    }
}

Lista* remover_enesimo (Lista* l, int n){
    Lista* aux = NULL;
    //se n eh diferente de zero
    if(--n){
        //se n eh 1 remove o proximo
        if(n == 1){
            aux = l->prox;
            l->prox = l->prox->prox;
            free(aux);
        //senão vai para o proximo
        }else{
            remover_enesimo(l->prox, n);
        }
    //senão remove a cabeca
    }else{
        aux = l->prox;
        free(l);
        return aux;
    }
    return l;
}

void imprime(Lista* li){
    printf("-> ");

    while(li != NULL){
        printf (" %d-> ", li->info);
        li = li->prox;
    }

    printf("\n");
}
