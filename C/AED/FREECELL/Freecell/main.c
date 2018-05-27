#include "main.h"

int main(void){

    return 0;
}

void mostrar_mesa(Mesa* mesa){
    int i, andares;
    No *pilha_aux[8] = {NULL};
    No *pilha_reversa[8] = {NULL};

    system("CLS");

    mostrar_marcas();
    mostrar_celulas(mesa);
    mostrar_fundacao(mesa);

    inverte_pilha(mesa->pilhas, pilha_reversa, &andares);

    for(i = 0; i < 8; i++){
        pilha_aux[i] = pilha_reversa[i];
    }

    while(andares--){
        for(i = 0; i < 8; i++){
            if(pilha_aux[i]){
                mostrar_carta(pilha_aux[i]->carta);
                pilha_aux[i] = pilha_aux[i]->prox;
            }else{
                printf("   ");
            }
        }
        printf("\n ");
    }
    printf("   ");

    for(i = 0; i < 8; i++){
        free(pilha_aux[i]);
        free(pilha_reversa[i]);
        printf(" %c \n", 'A'+ i);
    }
    printf("\n ");
}

void mostrar_carta(Carta* carta){
    char valor, naipe;

    if(carta){
        naipe = carta->naipe;
        valor = carta->valor;

        printf("%c%c,%c%c", (naipe%2) ? '(' : '[', getNaipe(naipe), getValor(valor), (naipe%2) ? '(' : '[');
    }else{
        return;
    }
}

void mostrar_celulas(Mesa* mesa){
     int i;

     frintf("-> ");
     for(i = 0; i < 4; i++){
         mostrar_carta(mesa->celulas[i]);
     }
     printf("\t ");
 }

void mostrar_fundacao(Mesa* mesa){
     int i;

     for(i = 0; i < 4; i++){
         if(mesa->fundacoes[i]){
             mostrar_carta(mesa->fundacoes[i]->inicio->carta);
         }
     }
     printf("\n");
 }

void mostrar_marcas(){
     int i;

     for(i = 0; i < 4; i++){
         printf(" %c ", 'A' + i);
     }

     printf("\t");

     for(i = 0; i < 4; i++){
         printf(" %c ", getNaipe(i));
     }
 }

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

No* inverte_lista(No* no){
    if(!no)return NULL;

    return insere_no_cauda(inverte_lista(no->prox), no->carta);
}

No* insere_no_cauda(No* lista, Carta* carta){
    if(!lista) return criar_no(carta);
    lista->prox = insere_no_cauda(lista->prox, carta);

    return lista;
}
