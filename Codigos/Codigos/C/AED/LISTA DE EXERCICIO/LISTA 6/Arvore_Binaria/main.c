#include "arvore_binaria.h"
#define MAX 5
int isAVl(arvore* r);

int main(void){

    arvore* r = NULL;
    int vet[MAX] = {38,31, 41, 12, 19};
    int tam = MAX;

    r = insere(r, vet, tam);

    in_ordem(r);
    printf("-----------------\n");
    pre_ordem(r);
    printf("-----------------\n");
    pos_ordem(r);

    printf("-----------------\n");
    printf("Altura: %d\n", altura(r));

    printf("-----------------\n");
    printf("Soma: %d\n", soma(r));

    if(isAVl(r)){
        printf("Eh AVL\n");
    }

    return 0;
}

int isAVl(arvore* r){
    if(!vazia(r)){
        int FB = altura(r->esquerda)- altura(r->direita);
        if(FB < -1 || FB > 1){
            printf("Nao eh AVL\n");
            return 0;
        }else{
            isAVl(r->esquerda);
            isAVl(r->direita);
        }
    }
    return 1;
}

