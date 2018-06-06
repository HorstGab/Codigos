#include "main.h"

/**
 * @brief main
 * @return
 */
int main(void){
    Mesa* mesa = Criar_Mesa();
    int aux;

    printf("Carregar jogo salvo? \n");
    printf("1. Sim\t 2.Cancelar\n");
    scanf("%d", &aux);
    if(aux == 1){
        carregar_jogo(mesa);
    }else{
        iniciar_jogo(mesa);
    }
    while(1){
        fflush(stdin);
        mostrar_mesa(mesa);
        imput_comandos(mesa);
    }
    return 0;
}

/**
 * @brief mostrar_mesa
 * @param mesa
 */
void mostrar_mesa(Mesa* mesa){
    int i, andares;
    No *pilha_aux[8] = {NULL};
    No *pilha_reversa[8] = {NULL};

    printf("\n P - Paus; C - Copas; E - Espadas; O - Ouro \n\n");
    mostrar_marcas();
    mostrar_celulas(mesa);
    mostrar_fundacao(mesa);


    for(i = 0; i < 8; i++){
        printf(" %c \t", 'A' + i);
    }
    printf("\n");

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
                printf("\t");
            }
        }
        printf("\n");
    }
    printf("\t");

    for(i = 0; i < 8; i++){
        free(pilha_aux[i]);
        free(pilha_reversa[i]);
    }
    printf("\n ");
}

/**
 * @brief mostrar_carta
 * @param carta
 */
void mostrar_carta(Carta* carta){
    char valor, naipe;

    naipe = carta->naipe;
    valor = carta->valor;
    printf("%c,%c\t", getNaipe(naipe), getValor(valor));
}

/**
 * @brief mostrar_celulas
 * @param mesa
 */
void mostrar_celulas(Mesa* mesa){
    int i;

    for(i = 0; i < 4; i++){
        if(mesa->celulas[i]){
            mostrar_carta(mesa->celulas[i]);
        }else{
            printf(" x \t");
        }
    }
    printf("\t ");
}

/**
 * @brief mostrar_fundacao
 * @param mesa
 */
void mostrar_fundacao(Mesa* mesa){
    int i;

    for(i = 0; i < 4; i++){
        if(mesa->fundacoes[i]->inicio){
            mostrar_carta(mesa->fundacoes[i]->inicio->carta);
        }else{
            printf(" x \t");
        }
    }
    printf("\n\n");
}

/**
 * @brief mostrar_marcas
 */
void mostrar_marcas(){
    int i;

    for(i = 0; i < 4; i++){
        printf(" %c \t", 'A' + i);
    }

    printf("\t");

    for(i = 0; i < 4; i++){
       printf(" %c \t", getNaipe(i));
    }
    printf("\n");
}

