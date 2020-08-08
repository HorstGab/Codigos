#include "main.h"

/**
 * @brief main
 * @param nenhum
 * @return 0 caso ocorreu sucesso
 * @pre condicao nenhuma
 * @pos condicao nenhuma
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
    system("cls");
    while(1){
        fflush(stdin);
        mostrar_mesa(mesa);
        imput_comandos(mesa);
    }
    return 0;
}

//printa o estado da mesa atual
/**
 * @brief mostrar_mesa
 * @param mesa
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
void mostrar_mesa(Mesa* mesa){
    int i, andares;
    No *pilha_aux[8] = {NULL};
    No *pilha_reversa[8] = {NULL};

    printf("\n P - Paus; C - Copas; E - Espadas; O - Ouro \n\n");
    mostrar_marcas();
    mostrar_celulas(mesa);
    mostrar_fundacao(mesa);


    //printa as referencias das colunas
    for(i = 0; i < 8; i++){
        printf(" %c \t", 'A' + i);
    }
    printf("\n");

    //inverte as pilhas
    inverte_pilha(mesa->pilhas, pilha_reversa, &andares);

    for(i = 0; i < 8; i++){
        //atribui a um auxiliar
        pilha_aux[i] = pilha_reversa[i];
    }

    //printa as pilhas
    while(andares--){
        for(i = 0; i < 8; i++){
            //enquanto for diferente de NULL
            if(pilha_aux[i]){
                //printa a carta
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
        //libera as pilhas
        free(pilha_aux[i]);
        free(pilha_reversa[i]);
    }
    printf("\n ");
}

//printa a carta
/**
 * @brief mostrar_carta
 * @param carta
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
void mostrar_carta(Carta* carta){
    char valor, naipe;

    //atribui o naipe e o valor
    naipe = carta->naipe;
    valor = carta->valor;
    //printa a carta
    printf("%c,%c\t", getNaipe(naipe), getValor(valor));
}

//printa as celulas
/**
 * @brief mostrar_celulas
 * @param mesa
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
void mostrar_celulas(Mesa* mesa){
    int i;

    for(i = 0; i < 4; i++){
        //se a celula da posicao nao for nula
        if(mesa->celulas[i]){
            //printa a carta
            mostrar_carta(mesa->celulas[i]);
        }else{
            printf(" x \t");
        }
    }
    printf("\t ");
}

//printa as fundacoes
/**
 * @brief mostrar_fundacao
 * @param mesa
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
void mostrar_fundacao(Mesa* mesa){
    int i;

    for(i = 0; i < 4; i++){
        //se o topo da fundacao n for nulo
        if(mesa->fundacoes[i]->inicio){
            //printa a carta
            mostrar_carta(mesa->fundacoes[i]->inicio->carta);
        }else{
            printf(" x \t");
        }
    }
    printf("\n\n");
}

//printa as referencias
/**
 * @brief mostrar_marcas
 * @param nenhum
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao nenhum
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

