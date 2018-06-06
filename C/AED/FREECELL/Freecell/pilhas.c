#include "pilhas.h"

/**
 * @brief criar_pilha
 * @return
 */
Pilha* criar_pilha(){
    Pilha* nova_pilha = (Pilha*)malloc(sizeof(Pilha));
    nova_pilha->tamanho = 0;
    nova_pilha->inicio = NULL;
    nova_pilha->fim = NULL;

    return nova_pilha;
}

/**
 * @brief insere_carta
 * @param pilha
 * @param carta
 * @return
 */
Pilha* insere_carta(Pilha* pilha, Carta* carta){
    No* aux = NULL;

    if(!carta) return pilha;
    if(!pilha){
        Pilha* nova_pilha = criar_pilha();
        nova_pilha->tamanho++;
        nova_pilha->inicio = criar_no(carta);
        nova_pilha->fim = nova_pilha->inicio;
        return nova_pilha;
    }

    aux = pilha->inicio;
    pilha->inicio = criar_no(carta);
    pilha->inicio->prox = aux;
    pilha->tamanho++;

    return pilha;
}

/**
 * @brief criar_no
 * @param carta
 * @return
 */
No* criar_no(Carta *carta){
    No* novo_no = (No*)malloc(sizeof(No));

    novo_no->carta = carta;
    novo_no->prox = NULL;

    return novo_no;
}

/**
 * @brief pop
 * @param pilha
 * @return
 */
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

/**
 * @brief inverte_pilha
 * @param pilha
 * @param pilha_reversa
 * @param andares
 */
void inverte_pilha(Pilha* pilha[], No* pilha_reversa[], int *andares){
    int i;

    for(i = *andares = 0; i < 8; i++){
        if(pilha[i]){
            if(pilha[i]->tamanho > *andares){
                *andares = pilha[i]->tamanho;
            }
            pilha_reversa[i] = inverte_lista(pilha[i]->inicio);
        }
    }
}

/**
 * @brief inverte_lista
 * @param no
 * @return
 */
No* inverte_lista(No* no){
    if(!no)return NULL;

    return insere_no_cauda(inverte_lista(no->prox), no->carta);
}

/**
 * @brief insere_no_cauda
 * @param lista
 * @param carta
 * @return
 */
No* insere_no_cauda(No* lista, Carta* carta){
    if(!lista) return criar_no(carta);
    lista->prox = insere_no_cauda(lista->prox, carta);

    return lista;
}

