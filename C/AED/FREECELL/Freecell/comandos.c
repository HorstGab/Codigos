#include "comandos.h"

char naipe[4] = {'O','E','C','P'};
char valor[13] = {'A','2','3','4','5','6','7','8','9','1','J','Q','K'};


void imput_comandos(Mesa *mesa){
    char cmd[MAXSTR];
    int cmd_tipo;
    char coluna_origem = 0, coluna_destino = 0;
    int qnt_cartas = 0;

    cmd_tipo = comandos_possiveis();

    if(cmd_tipo)printf("ok\n");

    switch(cmd_tipo){
    case 1:
        cmd_fundacao(&coluna_origem);
        printf("Coluna de origem: %c\n", coluna_origem);
        insere_fundacoes(mesa, coluna_origem);
        printf("\n\n --------//-------------------//-----------------\n\n");
    break;
    case 2:
        cmd_insere_cel(&coluna_origem);
        printf("Coluna de origem: %c \n", coluna_origem);
        insere_celulas(mesa, coluna_origem);
        printf("\n\n --------//-------------------//-----------------\n\n");
    break;
    case 3:
        cmd_remove_cel(&coluna_origem, &coluna_destino);
        printf("Celula de origem: %c \n", coluna_origem);
        printf("Coluna de destino: %c \n", coluna_destino);
        remove_celula(mesa, coluna_origem, coluna_destino);
    break;
    case 4:
        cmd_colunas(cmd, &coluna_origem, &qnt_cartas, &coluna_destino);
        move_coluna(mesa, coluna_origem, qnt_cartas, coluna_destino);
        break;
   // case 5:
        /*ler_cmd5();
        salvar_jogo();*/
        //break;
   // case 6:
        /*ler_cmd6();
        carregar_jogo();*/
        break;
   // case 7:
     //   sair();
        //break;
    default:
        printf("comando invalido\n");
    break;
    }
    getchar();
}

int comandos_possiveis(){
    int cmd_tipo;

    printf("comandos possiveis: \n");
    printf("1: MOVER PARA AS FUNDACOES \n");
    printf("2. MOVER PARA O CAMPO VAZIO \n");
    printf("3. RETIRAR DO CAMPO VAZIO \n");
    printf("4. MOVER PARA OUTRA COLUNA \n");
    printf("5. SALVAR JOGO \n");
    printf("6. CARREGAR JOGO \n");
    printf("7. SAIR \n");

    printf("escolha a operacao: ");
    scanf("%d", &cmd_tipo);
    fflush(stdin);

    return cmd_tipo;
}

void cmd_fundacao(char *coluna_origem){
    printf("Escolha a coluna: ");
    scanf("%c", coluna_origem);
    *coluna_origem = toupper(*coluna_origem);
}

void cmd_insere_cel(char* coluna_origem){
    printf("Escolha a coluna a ser enviada para o campo de reserva: ");
    scanf("%c", coluna_origem);
    *coluna_origem = toupper(*coluna_origem);
}

void cmd_remove_cel(char* coluna_origem, char* coluna_destino){
    printf("Escolha a celula a retirar a carta: ");
    scanf("%c", coluna_origem);
    *coluna_origem = toupper(*coluna_origem);
    getchar();

    printf("Escolha a coluna a inserir a carta: ");
    scanf("%c", coluna_destino);
    *coluna_destino = toupper(*coluna_destino);
}

void cmd_colunas(char cmd[],char* coluna_origem, int* qnt_cartas, char* coluna_destino){
    int i = 0, j = 0;
    sscanf(cmd, "%c%n", coluna_origem, &i);
    sscanf(cmd+i, "%d%n", qnt_cartas, &j);
    sscanf(cmd+i+j, ">%c", coluna_destino);
}

void insere_fundacoes(Mesa *mesa, char coluna_origem){
    Carta* carta = NULL;
    No* no = NULL;
    int indice_coluna = coluna_origem - 'A';

    if(coluna_origem >= 'A' && coluna_origem <= 'H'){
        if(mesa->pilhas[indice_coluna]->inicio){
            carta = mesa->pilhas[indice_coluna]->inicio->carta;
            if(mesa->fundacoes[carta->naipe]){
                no = mesa->fundacoes[carta->naipe]->inicio;
            }
            if(!carta->valor || (no && no->carta->valor == carta->valor - 1)){
                no = pop(mesa->pilhas[indice_coluna]);
                mesa->fundacoes[carta->naipe] = insere_carta(mesa->fundacoes[carta->naipe], no->carta);
                mesa->qnt_pilha_livre += (!mesa->pilhas[indice_coluna]->tamanho);
                free(no);
            }else{
                printf("A CARTA [%c,%c] NAO PODE SER FINALIZADA! \n", getNaipe(carta->naipe), getValor(carta->valor));
            }
        }else{
            printf("A COLUNA (%c) NAO POSSUI CARTAS! \n", coluna_origem);
        }
    }else{
        printf("COLUNA INVALIDA! \n");
    }
}

void insere_celulas(Mesa *mesa, char coluna_origem){
    Carta* carta = NULL;
    No* no = NULL;
    int indice_coluna = coluna_origem - 'A';
    int i;

    if(coluna_origem >= 'A' && coluna_origem <= 'H'){
        if(mesa->celula_livre){
            if(mesa->pilhas[indice_coluna]->inicio){
                for(i = 0; i < 4; i++){
                    if(!mesa->celulas[i]){
                        no = pop(mesa->pilhas[indice_coluna]);
                        carta = no->carta;
                        mesa->celulas[i] = carta;

                        mesa->celula_livre--;
                        mesa->qnt_pilha_livre += (!mesa->pilhas[indice_coluna]);
                        free(no);
                        break;
                    }
                }
            }else{
                printf("COLUNA (%c) NAO POSSUI NENHUMA CARTA!\n", coluna_origem);
            }
        }else{
            printf("NAO EXISTE ESPACO LIVRE! \n");
        }
    }else{
        printf("COLUNA INVALIDA! \n");
    }
}

void remove_celula(Mesa *mesa, char coluna_origem, char coluna_destino){
    Carta* carta_o = NULL, *carta_d = NULL;
    No* no = NULL;
    int indice_coluna_o = coluna_origem - 'A';
    int indice_coluna_d = coluna_destino - 'A';

    if(coluna_origem >= 'A' && coluna_origem <= 'D') {
        if(!coluna_destino || (coluna_destino >= 'A' && coluna_destino <= 'H')){
            if(mesa->celulas[indice_coluna_o]){
                carta_o = mesa->celulas[indice_coluna_o];
                no = mesa->pilhas[indice_coluna_d]->inicio;
                carta_d = no->carta;

                if(!no || carta_o->naipe%2 != carta_d->naipe%2){
                    if(!no || carta_o->valor - carta_d->valor == -1){
                        mesa->pilhas[indice_coluna_d] = insere_carta(mesa->pilhas[indice_coluna_d], carta_o);
                        mesa->celulas[indice_coluna_o] = NULL;

                        mesa->celula_livre++;
                        mesa->qnt_pilha_livre -= (!no);
                    }else{
                        printf("CARTA [%c,%c] PRECISA SER UM VALOR MENOR QUE A ANTERIOR! \n", getNaipe(carta_o->naipe), getValor(carta_o->valor));
                    }
                }else{
                    printf("AS CORES PRECISAM SER ALTERNADAS! \n");
                }
            }else{
                printf("A CELULA NAO POSSUI CARTA! \n");
            }
        }else{
            printf("COLUNA INVALIDA! \n");
        }
    }else{
        printf("CELULA INVALIDA! \n");
    }
}

void move_coluna(Mesa* mesa, char coluna_origem, int qnt_cartas, char coluna_destino){
    No *no_o = NULL, *no_d = NULL;
    Carta *carta_o = NULL, *carta_d = NULL;
    Pilha *pilha;
    int indice_coluna_o = coluna_origem - 'A';
    int indice_coluna_d = coluna_destino - 'A';
    int i, aux;


    if(toupper(coluna_origem) >= 'A' && toupper(coluna_origem) <= 'H'){
        if(coluna_destino >= 'A' && coluna_destino <= 'H'){
            printf("Celula de origem: %c \n", coluna_origem);
            printf("quantidade de cartas: %d \n", qnt_cartas);
            printf("Coluna de destino: %c \n", coluna_destino);
        }
    }else{
        return;
    }

    if(mesa->pilhas[indice_coluna_o]->inicio){
        if(qnt_cartas <= (mesa->celula_livre+1) * pow(2, mesa->qnt_pilha_livre)){
            no_o = mesa->pilhas[indice_coluna_o]->inicio;


            if(!qnt_cartas) return;

            for(i = aux = 1; i < qnt_cartas && aux; ++i){
                if(no_o && no_o->prox){
                    if(no_o->carta->naipe%2 == no_o->prox->carta->naipe%2){
                        aux = 1;
                        printf("AS CORES PRECISAM SER ALTERNADAS! \n");
                    }
                    if(no_o->carta->valor - no_o->prox->carta->valor != -1){
                        aux = 1;
                        printf("CARTA [%d, %d] PRECISA SER UM VALOR MENOR QUE A ANTERIOR! \n", carta_o->naipe, carta_o->valor);
                    }
                }else{
                    aux = 1;
                    printf("NAO HA %d CARTA(S) PARA SER MOVIMENTADA\n", qnt_cartas);
                }
                no_o = no_o->prox;
            }

            if(aux){
                carta_o = no_o->carta;
                no_d = mesa->pilhas[indice_coluna_d]->inicio;
                carta_d = mesa->pilhas[indice_coluna_d]->inicio->carta;

                if(!no_d || carta_o->naipe%2 != carta_d->naipe%2){

                    if(!no_d || carta_o->valor - carta_d->valor == -1){
                        pilha = criar_pilha();

                        for(i = 0; i < qnt_cartas; i++){
                            no_d = pop(mesa->pilhas[indice_coluna_o]);
                            pilha = insere_carta(pilha, no_d->carta);
                            free(no_d);
                        }

                        for(i = 0; i < qnt_cartas; i++){
                            no_d = pop(pilha);
                            mesa->pilhas[indice_coluna_d] = insere_carta(mesa->pilhas[indice_coluna_d], no_d->carta);
                            free(no_d);
                        }

                        free(pilha);
                    }else{
                        printf("CARTA [%d, %d] PRECISA SER UM VALOR MENOR QUE A ANTERIOR! \n", carta_o->naipe, carta_o->valor);
                    }
                }else{
                    printf("AS CORES PRECISAM SER ALTERNADAS! \n");
                }
            }
        }else{
            printf("PODE-SE MOVER %d CARTAS\n", mesa->celula_livre + mesa->qnt_pilha_livre +1);
        }
    }else{
        printf("COLUNA (%c) NAO POSSUI NENHUMA CARTA!\n", coluna_origem);
    }
}

char getNaipe(unsigned char str){
    return naipe[str];
}

char getValor(unsigned char str){
    return valor[str];
}
