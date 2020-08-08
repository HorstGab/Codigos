#include "lista_p.h"

typedef struct no{
    int info;
    struct no* prox;
}Lista;

Lista* lista(){
    return NULL;
}

int vazia(Lista *li){
    if(li == NULL){
        return 1;
    }else
        return 0;
}

Lista* insere_Final(Lista *li, int info){

    if(vazia(li)){
        Lista* novo = (Lista*) malloc(sizeof(Lista));
        li = novo;
        novo->info = info;
        novo->prox = NULL;
        return li;
    }
    li->prox = insere_Final(li->prox, info);
    return li;
}

void imprime(Lista *li){
    cout << "->";

    while(li != NULL){
        cout << li->info << "->";
        li = li->prox;
    }
    cout << "NULL" << endl;
}

void freeLista(Lista *li){
    cout << "Destruindo Lista ... " << endl;
    Lista* aux;
    while(li != NULL){
        aux = li;
        li = li->prox;
        free(aux);
    }
}
