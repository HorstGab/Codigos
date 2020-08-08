#include "arvore_binaria.h"

int vazia(arvore* r){
    return (r == NULL);
}

arvore* insere(arvore* r, int vet[], int tam){
    int i;

    for(i = 0; i < tam; i++){
       r = insere_Arvore_Binaria(r, vet[i]);
    }
    return r;
}

arvore* insere_Arvore_Binaria(arvore *r, int x){

    if(vazia(r)){
        r = (arvore*)malloc(sizeof(arvore));
        r->direita = NULL;
        r->esquerda = NULL;
        r->info = x;
    }else{
        if(x < r->info){
            r->esquerda = insere_Arvore_Binaria(r->esquerda, x);
        }else{
            r->direita = insere_Arvore_Binaria(r->direita, x);
        }
    }
    return r;
}

arvore* remove_Arvore_Binaria(arvore *r, int x){
    if(vazia(r)) return NULL;

    if(x < r->info) r->esquerda = remove_Arvore_Binaria(r->esquerda, x);//se eh menos

    if(x > r ->info) r->direita = remove_Arvore_Binaria(r->direita, x);//se eh amior

    if(x == r->info){//se for igual

        if(r->direita == NULL && r->esquerda == NULL){ //eh folha
            free(r);
            r = NULL;
        }else{

            if(r->esquerda == NULL){//so tem filho a direita
                r->info = minimo(r->direita);
                r->direita = remove_Arvore_Binaria(r->direita, r->info);

            }else{//so tem filho a esquerda
                r->info = maximo(r->esquerda);
                r->esquerda = remove_Arvore_Binaria(r->esquerda, r->info);
            }
        }
    }
    return r;
}

int minimo(arvore *r){
    if(vazia(r)){
        return -1;
    }else{
        if(vazia(r->esquerda)){
            return r->info;
        }else{
            return minimo(r->esquerda);
        }
    }
}

int maximo(arvore *r){
    if(!vazia(r)){
        while(!vazia(r->direita)){
            r = r->direita;
        }
    }
    return r->info;
}

void mostrar_arvore(arvore *r){
    if(!vazia(r)){
        mostrar_arvore(r->esquerda);
        printf("%d\n", r->info);
        mostrar_arvore(r->direita);
    }
    return;
}

void in_ordem(arvore *r){
    if(!vazia(r)){
        in_ordem(r->esquerda);
        printf("%d \n", r->info);
        in_ordem(r->direita);
    }
}

void pre_ordem(arvore* r){
    if(!vazia(r)){
        printf("%d \n", r->info);
        pre_ordem(r->esquerda);
        pre_ordem(r->direita);
    }
}

void pos_ordem(arvore *r){
    if(!vazia(r)){
        pos_ordem(r->esquerda);
        pos_ordem(r->direita);
        printf("%d \n", r->info);
    }
}

int altura(arvore *r){
    if(vazia(r)) return -1;

    int sub_e = altura(r->esquerda);
    int sub_d = altura(r->direita);
    if(sub_e < sub_d){
        return sub_d + 1;
    }else{
        return sub_e + 1;
    }
}

int soma(arvore *r){

    if(!vazia(r)){
        return r->info + soma(r->esquerda) + soma(r->direita);
    }else{
        return 0;
    }
}
