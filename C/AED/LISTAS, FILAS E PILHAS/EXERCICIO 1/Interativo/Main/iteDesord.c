
#include "exercicio1.h"

//estrutura da lista dinamica
typedef struct no {
    int info;
    struct no *prox;
}Lista;


Lista* criarLista(){
    return NULL;
}

int vazia(Lista * li){

    if(li->prox == NULL){
        return 1;
    }else{
        return 0;
    }
}


Lista* insere(Lista* li, int info){
    Lista* novo = (Lista*) malloc(sizeof(Lista));

        novo->info = info;
        novo->prox = li;

    return novo;

}

Lista* remover(Lista* l, int info){
    Lista* ant = l; //elemento anterior
    Lista* p = l; //encontrar o elemento a ser retirado

    if(!vazia(l)){
        while(p != NULL && p->info != info){//n entendi a condicão de parada
            ant = p;
            p = p->prox;
       }
       if(p != NULL){ // elemento encontrado
           if(p == l){
               l = l->prox;
           }else //remocao do meio
               ant->prox = p->prox;
           free(p);
           }else
           printf("ELEMENTO NAO ENCONTRADO\n");
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

Lista* inverte(Lista* l){
    Lista* aux = NULL;

    while(l!= NULL){
        aux = insere(aux, l->info);
        l = l->prox;
    }
    return aux;
}

Lista* merge(Lista* l1, Lista* l2){
}

int conta_ocorrencias(Lista* l, int x){
    int ocorrencia = 0;
    if(l != NULL){
        if(l->info == x){
            ocorrencia++;
        }
        ocorrencia = conta_ocorrencias(l->prox, x);
    }
    return ocorrencia;
}

