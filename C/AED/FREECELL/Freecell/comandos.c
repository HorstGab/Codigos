#include "comandos.h"

char naipe[4] = {'O','E','C','P'};
char valor[13] = {'A','2','3','4','5','6','7','8','9','1','J','Q','K'};


void imput_comandos(Mesa *mesa){
    int cmd_tipo;
    char coluna_origem = 0, coluna_destino = 0;
    int qnt_cartas = 0;

    cmd_tipo = comandos_possiveis();

    switch(cmd_tipo){
    case 1:
        cmd_fundacao(&coluna_origem);
        system("cls");
        insere_fundacoes(mesa, coluna_origem);
        break;
    case 2:
        cmd_insere_cel(&coluna_origem);
        system("cls");
        insere_celulas(mesa, coluna_origem);
        break;
    case 3:
        cmd_remove_cel(&coluna_origem, &coluna_destino);
        system("cls");
        remove_celula(mesa, coluna_origem, coluna_destino);
        break;
    case 4:

    case 5:
        cmd_colunas(&coluna_origem, &qnt_cartas, &coluna_destino);
        system("cls");
        move_coluna(mesa, coluna_origem, qnt_cartas, coluna_destino);
        break;

        /*ler_cmd5();
        salvar_jogo();*/
        //break;
    case 6:
        /*ler_cmd6();
        carregar_jogo();*/
        break;
    case 7:
        //sair();
        break;
    default:
        printf("Comando invalido!\n");
        break;
    }
    getchar();
}

int comandos_possiveis(){
    int cmd_tipo;

    printf("Comandos possiveis: \n");
    printf("1: COLUNA -> FUNDACOES\n");
    printf("2. COLUNA -> RESERVA\n");
    printf("3. RESERVA -> COLUNA\n");
    printf("4. RESERVA -> FUNDACOES\n");
    printf("5. COLUNA -> COLUNA\n");
    printf("6. SALVAR JOGO\n");
    printf("7. CARREGAR JOGO\n");
    printf("8. SAIR \n");

    printf("Escolha a operacao: ");
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

void cmd_colunas(char* coluna_origem, int* qnt_cartas, char* coluna_destino){
    printf("Escolha a coluna inicial: ");
    scanf("%c", coluna_origem);
    *coluna_origem = toupper(*coluna_origem);
    getchar();
    printf("Escolha a coluna de destino: ");
    scanf("%c", coluna_destino);
    *coluna_destino = toupper(*coluna_destino);
    getchar();
    printf("Escolha a quantidade de cartas: ");
    scanf("%d", qnt_cartas);
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
    int i, aux = 1;


    if(coluna_origem >= 'A' && coluna_origem <= 'H'){
        if(coluna_destino >= 'A' && coluna_destino <= 'H'){
            if(mesa->pilhas[indice_coluna_o]->inicio){
                if(qnt_cartas <= (mesa->celula_livre+1) * pow(2, mesa->qnt_pilha_livre)){
                    no_o = mesa->pilhas[indice_coluna_o]->inicio;

                    if(!qnt_cartas) return;
                    if(qnt_cartas > 2){
                        aux = validacao_coluna(no_o, qnt_cartas);
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
                                printf("CARTA PRECISA SER UM VALOR MENOR QUE A ANTERIOR! \n");
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
    }
}

int validacao_coluna (No* no, int qnt_cartas){
    int i, aux = 0;

    for(i = 0; i < qnt_cartas; i++){
        if(no && no->prox){
            if(no->carta->naipe%2 == no->prox->carta->naipe%2){
                if((no->carta->valor+1) == no->prox->carta->valor){
                    aux = 1;
                }else{
                    printf("As cartas nao possuem ordem valida! \n");
                    return 0;
                }
            }else{
                printf("Os naipes das cartas precisam ser alternados! \n");
                return 0;
            }
        }else{
            printf("Quantidade de cartas inexistente! \n");
            return 0;
        }
        no = no->prox;
    }

    return aux;
}

char getNaipe(unsigned char str){
    return naipe[str];
}

char getValor(unsigned char str){
    return valor[str];
}
