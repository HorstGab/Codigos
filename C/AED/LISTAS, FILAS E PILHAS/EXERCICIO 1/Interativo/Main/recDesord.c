#include "exercicio1.h"

typedef struct no{
    int info;
    Lista* prox;
}Lista;

Lista* criarLista(){
    return NULL;
}

int vazia(Lista* li){
    if(li->prox){
        vazia(li);
        return 1;
    }else
        return 0;
}
