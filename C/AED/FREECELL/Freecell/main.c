#include "main.h"

int main(void){

    return 0;
}


Pilha* criar_pilha(){
    Pilha* nova_pilha = (Pilha*)malloc(sizeof(Pilha));
    nova_pilha->tamanho = 0;
    nova_pilha->inicio = NULL;
    nova_pilha->fim = NULL;

    return nova_pilha;
}

No* criar_no(Carta *carta){
    No* novo_no = (No*)malloc(sizeof(No));

    novo_no->carta = carta;
    novo_no->prox = NULL;

    return novo_no;
}

Mesa* Criar_Mesa(){
    Mesa* nova_mesa = (Mesa*)malloc(sizeof(Mesa));
    int i;

    nova_mesa->celula_livre = 4;
    nova_mesa->qnt_pilha_livre = 8;

    for(i = 0; i < 4; i++){
        nova_mesa->pilhas[i] = criar_pilha();
        nova_mesa->pilhas[i+4] = criar_pilha();
        nova_mesa->fundacoes[i] = criar_pilha();
        nova_mesa->celulas[i] = NULL;
    }
    return nova_mesa;
}

void iniciar_jogo(){
    Carta* cartas[52];

    Criar_Baralho(cartas);
    Embaralhar(cartas);
   // insere_mesa(cartas);
}

void Criar_Baralho(Carta* cartas[]){
    int naipe, valor;

    for(naipe = 0; naipe < 3; naipe++){
        for(valor = 0; valor < 12; valor++){
            cartas[naipe*13 + valor] = Criar_Carta(naipe, valor);
        }
    }
}

Carta* Criar_Carta(int naipe, int valor){
    Carta* nova_carta = (Carta*)malloc(sizeof(Carta));

    nova_carta->naipe = naipe;
    nova_carta->valor = valor;

    return nova_carta;
}

void Embaralhar(Carta* cartas[]){
    Carta* aux = NULL;
    int i, ind;

    for(i = 0; i < 52; i++){
        ind = rand() % 52;
        aux = cartas[i];
        cartas[i] = cartas[ind];
        cartas[ind] = aux;
    }
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

//comandos

void imput_cmd(Mesa *mesa){
    char cmd[MAX], cmd_tipo;
    char coluna_origem = 0, coluna_destino = 0;
    int qnt_cartas = 0;

    comandos_possiveis(cmd_tipo);

    switch(cmd_tipo){
    case 1:
        cmd_fundacao(cmd, &coluna_origem);
        insere_fundacoes(mesa, coluna_origem);
        break;
    case 2:
        cmd_insere_cel(cmd, &coluna_origem, &coluna_destino);
        insere_celulas(mesa, coluna_origem, coluna_destino);
        break;
    case 3:
        cmd_remove_cel(cmd, &coluna_origem, &coluna_destino);
        remove_celula(mesa, coluna_origem, coluna_destino);
        break;
    case 4:
        cmd_colunas(cmd, &coluna_origem, &qnt_cartas, &coluna_destino);
        move_coluna(mesa, coluna_origem, qnt_cartas, coluna_destino);
        break;
    case 5:
        /*ler_cmd5();
        salvar_jogo();*/
        break;
    case 6:
        /*ler_cmd6();
        carregar_jogo();*/
        break;
    case 7:
        sair();
    }
    getchar();
}

int comandos_possiveis(char cmd_tipo){

    printf("escolha a carta: ");

    printf("comandos possiveis: \n");
    printf("1: MOVER PARA AS FUNDACOES \n");
    printf("2. MOVER PARA O CAMPO VAZIO \n");
    printf("3. RETIRAR DO CAMPO VAZIO \n");
    printf("4. MOVER PARA OUTRA COLUNA \n");
    printf("5. SALVAR JOGO \n");
    printf("6. CARREGAR JOGO \n");
    printf("7. SAIR \n");

    scanf("%d", &cmd_tipo);

    return cmd_tipo;
}

void cmd_fundacao(char cmd[], char* coluna_origem){
    sscanf(cmd, "*%c", coluna_origem);
    *coluna_origem = toupper(*coluna_origem);
}

void insere_fundacoes(Mesa *mesa, char *coluna_origem){
    Carta* carta = NULL;
    No* no = NULL;
    int indice_coluna = coluna_origem - 'A';

    if(!(toupper(coluna_origem) >= 'A' && toupper(coluna_origem) <= 'H')) return;

    printf("Coluna de origem: %c\n", colula_origem);

    if(indice_coluna >= 0 && indice_coluna < 8){

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
                printf("A CARTA [%d, %d] NAO PODE SER FINALIZADA! \n", getNaipe(carta->naipe), getValor(carta->valor));
            }
        }else{
            printf("A COLUNA (%d) NAO POSSUI CARTAS \n", coluna_origem);
        }
    }
}

void cmd_insere_cel(char cmd[], char* coluna_origem, char* coluna_destino){
    sscanf(cmd, "^%c >%c", coluna_origem);
    *coluna_origem = toupper(*coluna_origem);
    *coluna_destino = toupper(*coluna_destino);
}

void insere_celulas(Mesa *mesa, char *coluna_origem, char *coluna_destino){
    Carta* carta = NULL;
    No* no = NULL;
    int indice_coluna_o = coluna_origem - 'A';
    int indice_coluna_d = coluna_destino - 'A';

    if(toupper(coluna_origem) >= 'A' && toupper(coluna_origem) <= 'H'){
        if(!coluna_destino || (coluna_destino >= 'A' && coluna_destino <= 'D')){
                printf("Coluna de origem: %c \n", coluna_origem);
                printf("Celula de destino: %c \n", coluna_destino);
        }

    }else{
            return;
    }

    if(mesa->celula_livre > 0){
        if(mesa->pilhas[indice_coluna_o]->inicio){
            if(indice_coluna_d < 0 || indice_coluna_d >= 4){
                for(indice_coluna_d = 0; indice_coluna_d < 4 && mesa->celulas[indice_coluna_d]; indice_coluna_d ++);
            }
            if(!(mesa->celulas[indice_coluna_d])){
                no = pop(mesa->pilhas[indice_coluna_o]);
                carta = no->carta;
                mesa->celulas[indice_coluna_d] = carta;

                mesa->celula_livre--;
                mesa->qnt_pilha_livre += (!mesa->pilhas[indice_coluna_o]);
                free(no);
            }else{
                printf("JA EXISTE CARTA NESSE PONTO!\n");
            }
        }else{
            printf("COLUNA (%d) NAO POSSUI NENHUMA CARTA!\n");
        }
    }else{
        printf("NAO EXISTE ESPACO LIVRE! \n");
    }
}

void cmd_remove_cel(char cmd[], char* coluna_origem, char* coluna_destino){
    sscanf(cmd, "v%c >%c", coluna_origem);
    *coluna_origem = toupper(*coluna_origem);
    *coluna_destino = toupper(*coluna_destino);
}

void remove_celula(Mesa *mesa, char *coluna_origem, char *coluna_destino){
    Carta* carta_o = NULL, *carta_d = NULL;
    No* no = NULL;
    int indice_coluna_o = coluna_origem - 'A';
    int indice_coluna_d = coluna_destino - 'A';

    if(toupper(coluna_origem) >= 'A' && toupper(coluna_origem) <= 'H') {
        if(!colTo || (colTo >= 'A' && colTo <= 'D')){
            printf("Celula de origem: %c \n", coluna_origem);
            printf("Coluna de destino: %c \n", coluna_destino);
        }
    }else{
        return;
    }

    if(mesa->celulas[indice_coluna_o]){
        carta_o = mesa->celulas[indice_coluna_o];
        no = mesa->pilhas[indice_coluna_d]->inicio;
        carta_d = no->carta;

        if(!node || carta_o->naipe%2 != carta_d->naipe%2){
            if(!node || carta_o->valor - carta_d->valor == -1){
                mesa->pilhas[indice_coluna_d] = insere_carta(mesa->pilhas[indice_coluna_d], carta_o);
                mesa->celulas[indice_coluna_o] = NULL;

                mesa->celula_livre++;
                mesa->celulas -= (!no);
            }else{
                printf("MOVIMENTO INVALIDO!\n");
                printf("CARTA [%d, %d] PRECISA SER UM VALOR MENOR QUE A ANTERIOR! \n", getNaipe(carta_o->naipe), getValor(carta_o->valor))
            }
        }else{
            printf("MOVIMENTO INVALIDO!\n");
            printf("AS CORES PRECISAM SER ALTERNADAS! \n");
        }
    }else{
        printf("MOVIMENTO INVALIDO!\n");
        printf("A CELULA NAO POSSUI CARTA! \n");
    }
}

void cmd_colunas(char cmd[],char* coluna_origem, int* qnt_cartas, char* coluna_destino){
    int i = 0, j = 0;
    sscanf(cmd, "%c%n", coluna_origem, &i);
    sscanf(cmd+i, "%d%n", qnt_cartas, &j);
    sscanf(cmd+i+j, ">%c", coluna_destino);
}

void move_coluna(Mesa* mesa, char* coluna_origem, int qnt_cartas, char* coluna_destino){
    no *no_o = NULL;
    int indice_coluna_o = coluna_origem - 'A';
    int indice_coluna_d = coluna_destino - 'A';
    int i, aux;

    if(mesa->pilhas[indice_coluna_o]->inicio){
        if(qnt_cartas <= (mesa->celulas+1) * pow(2, mesa->qnt_pilha_livre)){
            no_o = mesa->pilhas[indice_coluna_o]->inicio;

            if(!qnt_cartas) return;

            for( i = aux = 1; i < qnt_cartas && aux; ++i){
                if(no_o && no_o->prox){
                    if(no_o->carta->naipe%2 == no_o->prox->carta->naipe%2){
                        aux = 1;
                        printf("AS CORES PRECISAM SER ALTERNADAS! \n");
                    }
                    if(no_o->carta->valor - no_o->prox->carta->valor != -1){
                        aux = 1;
                        printf("CARTA [%d, %d] PRECISA SER UM VALOR MENOR QUE A ANTERIOR! \n", getNaipe(carta_o->naipe), getValor(carta_o->valor));
                    }
                }else{
                    aux = 1;
                    printf("NAO HA %d CARTA(S) PARA SER MOVIMENTADA\n", qnt_cartas);
                }
                no_o = no_o->prox;
            }
        }
    }
}
