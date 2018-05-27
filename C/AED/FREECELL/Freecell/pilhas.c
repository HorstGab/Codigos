#include "pilhas.h"

Pilha* criar_pilha(){
    Pilha* nova_pilha = (Pilha*)malloc(sizeof(Pilha));
    nova_pilha->tamanho = 0;
    nova_pilha->inicio = NULL;
    nova_pilha->fim = NULL;

    return nova_pilha;
}

Pilha* insere_carta(Pilha* pilha, Carta* carta){
    No* aux = NULL;

    if(!carta) return pilha;
    if(!pilha){
        Pilha* nova_pilha = criar_pilha();
        nova_pilha->tamanho++;
        nova_pilha->inicio = criar_no(carta);
        nova_pilha->fim = nova_pilha->inicio;
    }
    aux = pilha->inicio;
    pilha->inicio = criar_no(carta);
    pilha->inicio->prox = aux;
    pilha->tamanho++;

    return pilha;
}

No* criar_no(Carta *carta){
    No* novo_no = (No*)malloc(sizeof(No));

    novo_no->carta = carta;
    novo_no->prox = NULL;

    return novo_no;
}

No* pop(Pilha *pilha){
    No* aux;

    if(pilha || pilha->inicio){
        aux = pilha->inicio;
        if(pilha->inicio == pilha->fim){
            pilha->inicio = NULL;
            pilha->fim = NULL;
        }else{
            pilha->inicio = pilha->inicio->prox;
        }
        pilha->tamanho--;
        aux->prox = NULL;
    }
    return aux;
}
