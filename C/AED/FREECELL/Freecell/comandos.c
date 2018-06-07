#include "comandos.h"

char naipe[4] = {'O','E','C','P'};
char valor[13] = {'A','2','3','4','5','6','7','8','9','1','J','Q','K'};

/**
 * @brief imput_comandos
 * @param mesa
 */
void imput_comandos(Mesa *mesa){
    int cmd_tipo;
    char coluna_origem = 0, coluna_destino = 0;
    int qnt_cartas = 0;

    cmd_tipo = comandos_possiveis();
    //para cada caso le um comando e o executa
    switch(cmd_tipo){
    case 1:
        //enviar para as fundacoes
        cmd_fundacao(&coluna_origem);
        system("cls");
        insere_fundacoes(mesa, coluna_origem);
        break;
    case 2:
        //inserir nas celulas
        cmd_insere_cel(&coluna_origem);
        system("cls");
        insere_celulas(mesa, coluna_origem);
        break;
    case 3:
        //remover das celulas e inserir nas colunas
        cmd_remove_cel(&coluna_origem, &coluna_destino);
        system("cls");
        remove_celula(mesa, coluna_origem, coluna_destino);
        break;
    case 4:
        //remover das celulas e inserir nas fundacoes
        cmd_cel_fund(&coluna_origem);
        system("cls");
        cel_fund(mesa, coluna_origem);
        break;
    case 5:
        //mover de uma coluna para outra
        cmd_colunas(&coluna_origem, &qnt_cartas, &coluna_destino);
        system("cls");
        move_coluna(mesa, coluna_origem, qnt_cartas, coluna_destino);
        break;
    case 6:
        //salva o jogo em um arquivo binario
        system("cls");
        salvar(mesa);
        break;
    case 7:
        //carrega um jogo salvo
        system("cls");
        carregar(mesa);
        break;
    case 8:
        sair();
        break;
    default:
        printf("Comando invalido!\n");
        break;
    }
    getchar();
}

/**
 * @brief comandos_possiveis
 * @return
 */
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

/**
 * @brief cmd_fundacao
 * @param coluna_origem
 */
void cmd_fundacao(char *coluna_origem){
    printf("Escolha a coluna: ");
    //le o char que representa a coluna
    scanf("%c", coluna_origem);
    //transforma em maiuscula
    *coluna_origem = toupper(*coluna_origem);
}

/**
 * @brief cmd_insere_cel
 * @param coluna_origem
 */
void cmd_insere_cel(char* coluna_origem){
    printf("Escolha a coluna a ser enviada para o campo de reserva: ");
    //le o char que representa a coluna
    scanf("%c", coluna_origem);
    //transforma em maiuscula
    *coluna_origem = toupper(*coluna_origem);
}

/**
 * @brief cmd_remove_cel
 * @param coluna_origem
 * @param coluna_destino
 */
void cmd_remove_cel(char* coluna_origem, char* coluna_destino){
    printf("Escolha a celula a retirar a carta: ");
    //le o char que representa a celula
    scanf("%c", coluna_origem);
    //transforma em maiuscula
    *coluna_origem = toupper(*coluna_origem);
    getchar();

    printf("Escolha a coluna a inserir a carta: ");
    //le o char que representa a coluna
    scanf("%c", coluna_destino);
    //transforma em maiuscula
    *coluna_destino = toupper(*coluna_destino);
}

/**
 * @brief cmd_cel_fund
 * @param coluna_origem
 */
void cmd_cel_fund(char *coluna_origem){
    printf("Escolha a celula a retirar a carta: ");
    //le o char que representa a celula
    scanf("%c",coluna_origem);
    //transforma em maiuscula
    *coluna_origem = toupper(*coluna_origem);
}

/**
 * @brief cmd_colunas
 * @param coluna_origem
 * @param qnt_cartas
 * @param coluna_destino
 */
void cmd_colunas(char* coluna_origem, int* qnt_cartas, char* coluna_destino){
    printf("Escolha a coluna inicial: ");
    //le o char que representa a coluna de inicio
    scanf("%c", coluna_origem);
    //transforma em maiuscula
    *coluna_origem = toupper(*coluna_origem);
    getchar();
    printf("Escolha a coluna de destino: ");
    //le o char que representa a coluna de destino
    scanf("%c", coluna_destino);
    //transforma em maiuscula
    *coluna_destino = toupper(*coluna_destino);
    getchar();
    printf("Escolha a quantidade de cartas: ");
    //le a quantidade de cartas a ser movida
    scanf("%d", qnt_cartas);
}

/**
 * @brief insere_fundacoes
 * @param mesa
 * @param coluna_origem
 */
void insere_fundacoes(Mesa *mesa, char coluna_origem){
    Carta* carta = NULL;
    No* no = NULL;
    int indice_coluna = coluna_origem - 'A';

    //confere se a coluna está entre as colunas existentes
    if(coluna_origem >= 'A' && coluna_origem <= 'H'){
        //confere se existe topo
        if(mesa->pilhas[indice_coluna]->inicio){
            //carta recebe a carta do topo da pilha
            carta = mesa->pilhas[indice_coluna]->inicio->carta;
            //confere se existe a pilha do respectivo naipe na fundacao
            if(mesa->fundacoes[carta->naipe]){
                //no recebe o topo da pilha do respectivo naipe na fundacao
                no = mesa->fundacoes[carta->naipe]->inicio;
            }
            //condere se é um as ou o no existe e se os valores das cartas e uma unidade menor que a outra
            if(!carta->valor || (no && (no->carta->valor+1) == carta->valor)){
                //no recebe o topo da pilha de cartas
                no = pop(mesa->pilhas[indice_coluna]);
                //fundacao recebe a carta retirada da pilha
                mesa->fundacoes[carta->naipe] = insere_carta(mesa->fundacoes[carta->naipe], no->carta);
                //atualiza o numero de pilhas vazias se foi esvaziada
                mesa->qnt_pilha_livre += (!mesa->pilhas[indice_coluna]->tamanho);
                //libera o no
                free(no);
            }else{
                printf("A CARTA NAO PODE SER FINALIZADA! \n");
            }
        }else{
            printf("A COLUNA (%c) NAO POSSUI CARTAS! \n", coluna_origem);
        }
    }else{
        printf("COLUNA INVALIDA! \n");
    }
}

/**
 * @brief insere_celulas
 * @param mesa
 * @param coluna_origem
 */
void insere_celulas(Mesa *mesa, char coluna_origem){
    Carta* carta = NULL;
    No* no = NULL;
    int indice_coluna = coluna_origem - 'A';
    int i;

    //confere se a coluna esta entre as colunas validas
    if(coluna_origem >= 'A' && coluna_origem <= 'H'){
        //confere se possui celulas livres
        if(mesa->celula_livre){
            //confere se existe carta no topo da pilha de cartas
            if(mesa->pilhas[indice_coluna]->inicio){
                for(i = 0; i < 4; i++){
                    //se a celula nao possuir celula
                    if(!mesa->celulas[i]){
                        //no recebe o topo da pilha de cartas
                        no = pop(mesa->pilhas[indice_coluna]);
                        //carta recebe a carta do topo da pilha
                        carta = no->carta;
                        //a celula recebe a carta
                        mesa->celulas[i] = carta;

                        //a quantidade de celula livre eh decrementada
                        mesa->celula_livre--;
                        //atualiza o numero de pilhas livres se foi esvaziada
                        mesa->qnt_pilha_livre += (!mesa->pilhas[indice_coluna]);
                        //libera no
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

/**
 * @brief remove_celula
 * @param mesa
 * @param coluna_origem
 * @param coluna_destino
 */
void remove_celula(Mesa *mesa, char coluna_origem, char coluna_destino){
    Carta* carta_o = NULL, *carta_d = NULL;
    No* no = NULL;
    int indice_coluna_o = coluna_origem - 'A';
    int indice_coluna_d = coluna_destino - 'A';


    //confere se a celula esta entre as colunas validas
    if(coluna_origem >= 'A' && coluna_origem <= 'D') {
        //confere se a coluna é valida e se esta entre as colunas validas
        if(!coluna_destino || (coluna_destino >= 'A' && coluna_destino <= 'H')){
            //confere se existe carta para retirar da celula
            if(mesa->celulas[indice_coluna_o]){
                //carta recebe a carta da celula
                carta_o = mesa->celulas[indice_coluna_o];
                //no recebe o topo da pilha
                no = mesa->pilhas[indice_coluna_d]->inicio;
                //carta de destino recebe a carta do topo da pilha
                carta_d = no->carta;

                //se a pilha eh vazia ou se os naipes sao diferentes
                if(!no || carta_o->naipe%2 != carta_d->naipe%2){
                    //se a pilha eh vazia ou se os valores das cartas e uma unidade menor q a outra
                    if(!no || (carta_o->valor+1) == carta_d->valor){
                        //pilha recebe a carta da celula
                        mesa->pilhas[indice_coluna_d] = insere_carta(mesa->pilhas[indice_coluna_d], carta_o);
                        //celula é zerada
                        mesa->celulas[indice_coluna_o] = NULL;

                        //quantidade de celulas livres eh incrementada
                        mesa->celula_livre++;
                        //diminui a quantidade de pilhas vazias se o no n for vazia
                        mesa->qnt_pilha_livre -= (!no);
                    }else{
                        printf("CARTA PRECISA SER UM VALOR MENOR QUE A ANTERIOR! \n");
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

/**
 * @brief cel_fund
 * @param mesa
 * @param coluna_origem
 */
void cel_fund(Mesa *mesa, char coluna_origem){
    Carta* carta = NULL;
    No* no = NULL;
    int indice_coluna = coluna_origem - 'A';

    //confere se a celula esta entre as colunas validas
    if(coluna_origem >= 'A' && coluna_origem <= 'D'){
        //confere se a celula possui carta
        if(mesa->celulas[indice_coluna]){
            //carta recebe a carta da celula
            carta = mesa->celulas[indice_coluna];
            //confere se a pilha do vetor de fundacoes possui carta
            if(mesa->fundacoes[carta->naipe]){
                //no recebe o no do topo da fundacao
                no = mesa->fundacoes[carta->naipe]->inicio;
                //se a pilha eh vazia ou se os valores das cartas e uma unidade menor que a outra
                if(!carta->valor || (no && (no->carta->valor+1) == carta->valor)){
                    //a fundacão recebe a carta da celula
                    mesa->fundacoes[carta->naipe] = insere_carta(mesa->fundacoes[carta->naipe],carta);
                    //a celula é anulada
                    mesa->celulas[indice_coluna] = NULL;
                    //a quantidade de celulas livres é incrementada
                    mesa->celula_livre++;
                }else{
                    printf("A CARTA NAO PODE SER FINALIZADA! \n");
                }
            }
        }else{
            printf("NAO POSSUI CARTA NA CELULA DE RESERVA! \n");
        }
    }else{
        printf("CELULA INVALIDA! \n");
    }
}

/**
 * @brief move_coluna
 * @param mesa
 * @param coluna_origem
 * @param qnt_cartas
 * @param coluna_destino
 */
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

                    if(!qnt_cartas){
                        return;
                    }
                    if(qnt_cartas > 1){
//                        aux = validacao_coluna(no_o, qnt_cartas);
                        for(i = 0; !no_o && i < qnt_cartas; no_o = no_o->prox)
                            ;
                        printf("ok\n");
                    }


                    if(aux){
                        carta_o = no_o->carta;
                        no_d = mesa->pilhas[indice_coluna_d]->inicio;
                        carta_d = mesa->pilhas[indice_coluna_d]->inicio->carta;

                        if(!no_d || carta_o->naipe%2 != carta_d->naipe%2){

                            if(!no_d || (carta_o->valor+1) == carta_d->valor){
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

/**
 * @brief validacao_coluna
 * @param no
 * @param qnt_cartas
 * @return
 */
int validacao_coluna (No* no, int qnt_cartas){
    int i;

    for(i = 1; i < qnt_cartas; i++){
        if(no && no->prox){
            if(no->carta->naipe%2 != no->prox->carta->naipe%2){
                if((no->carta->valor+1) == no->prox->carta->valor){
                    return 1;
                    printf("ok\n");
                }else{
                    printf("As cartas nao possuem ordem valida! \n");
                    return 0;
                }
            }else{
                printf("As cores das cartas precisam ser alternados! \n");
                return 0;
            }
        }else{
            printf("Quantidade de cartas inexistente! \n");
            return 0;
        }
        no = no->prox;
    }
    return 0;
}

/**
 * @brief salvar
 * @param mesa
 */
void salvar(Mesa* mesa){
    int x;

    printf("Salvar jogo? \n");
    printf("1. SIM \t2.CANCELAR\n");

    scanf("%d", &x);
    if(x == 1){
        salvar_jogo(mesa);
        printf("JOGO SALVO! \n");
    }else{
        if(x == 2){
            return;
        }else{
            salvar(mesa);
        }
    }
}

/**
 * @brief carregar
 * @param mesa
 */
void carregar(Mesa* mesa){
    int x;

    printf("Carregar jogo? \n");
    printf("1. SIM \t2.CANCELAR\n");

    scanf("%d", &x);
    if(x == 1){
        carregar_jogo(mesa);
        printf("JOGO CARREGADO! \n");
    }else{
        if(x == 2){
            return;
        }else{
            carregar(mesa);
        }
    }
}

/**
 * @brief getNaipe
 * @param str
 * @return
 */
char getNaipe(unsigned char str){
    return naipe[str];
}

/**
 * @brief getValor
 * @param str
 * @return
 */
char getValor(unsigned char str){
    return valor[str];
}

//////////////////////////////////////////////

/**
 * @brief salvar_jogo
 * @param mesa
 */
void salvar_jogo(Mesa* mesa){
    FILE* f;
    char nome_arquivo[15];

    printf("Nome do arquivo: ");
    scanf("%s", nome_arquivo);

    if((f = fopen(nome_arquivo, "ab")) == NULL){
        printf("Erro! Arquivo nao pode ser aberto! \n");
    }else{
        save_celula(mesa, f);
        save_fundacao(mesa, f);
        save_coluna(mesa, f);
    }
    fclose(f);
    system("cls");
}

/**
 * @brief save_fundacao
 * @param mesa
 * @param f
 */
void save_fundacao(Mesa* mesa, FILE* f){
    int i;

    for(i = 0; i < 4; i++){
        save_pilha(mesa->fundacoes[i]->inicio, f);
    }
}

/**
 * @brief save_carta
 * @param f
 * @param carta
 */
void save_carta(FILE *f, Carta *carta) {
    Carta cartaNula; cartaNula.naipe = -1; cartaNula.valor = -1;

    if(carta) {
        fwrite(carta, sizeof(Carta), 1, f);
    } else {
        fwrite(&cartaNula, sizeof(Carta), 1, f);
    }

    getch();

}

/**
 * @brief save_celula
 * @param mesa
 * @param f
 */
void save_celula(Mesa* mesa, FILE* f){
    int i;
    Carta* carta = NULL;

    for(i = 0; i < 4; i++){
        carta = mesa->celulas[i];
        save_carta(f, carta);
    }
}

/**
 * @brief save_coluna
 * @param mesa
 * @param f
 */
void save_coluna(Mesa* mesa, FILE* f){
    int i;
    int andares;
    No* pilha_reversa[8] = {NULL};

    inverte_pilha(mesa->pilhas, pilha_reversa, &andares);
    for(i = 0; i < 8; i++){
        save_pilha(pilha_reversa[i], f);
    }
}

/**
 * @brief save_pilha
 * @param no
 * @param f
 */
void save_pilha(No* no, FILE* f){

    while(no != NULL){
        save_carta(f, no->carta);
        no = no->prox;
    }

    save_carta(f, NULL);
}

/**
 * @brief carregar_jogo
 * @param mesa
 */
void carregar_jogo(Mesa* mesa){
    FILE* f;
    char nome_arquivo[15];

    printf("DIGITE O NOME DO JOGO SALVO! \n");
    getchar();
    scanf("%[^\n]%*c", nome_arquivo);

    if((f = fopen(nome_arquivo, "rb+")) == NULL){
        printf("Erro! Arquivo nao pode ser aberto! \n");
    }else{
        load_celula(mesa, f);
        load_fundacao(mesa, f);
        load_coluna(mesa, f);
    }
    fclose(f);
    system("cls");
}

/**
 * @brief load_carta
 * @param buffer
 * @param f
 */
void load_carta(Carta *buffer, FILE* f) {
    fread(buffer, sizeof(Carta), 1, f);
}

/**
 * @brief load_celula
 * @param mesa
 * @param f
 */
void load_celula(Mesa* mesa, FILE* f){
    Carta buffer;
    int i;

    for(i = 0; i < 4; i++){
        load_carta(&buffer, f);
        if(buffer.naipe != -1) {
            mesa->celulas[i] = Criar_Carta(buffer.naipe, buffer.valor);
        }
    }
}

/**
 * @brief load_fundacao
 * @param mesa
 * @param f
 */
void load_fundacao(Mesa* mesa, FILE* f){
    int i;

    for(i = 0; i < 4; i++){
        load_pilha(mesa->fundacoes[i], f);
    }
}

/**
 * @brief load_coluna
 * @param mesa
 * @param f
 */
void load_coluna(Mesa* mesa, FILE* f){
    int i;

    for(i = 0; i < 8; i++){
        load_pilha(mesa->pilhas[i], f);
    }
}

/**
 * @brief load_pilha
 * @param pilha
 * @param f
 */
void load_pilha(Pilha* pilha, FILE* f){
    Carta buffer;

    load_carta(&buffer, f);
    while(!feof(f)){
        if(buffer.naipe == -1) {
            return;
        }
        insere_carta(pilha, Criar_Carta(buffer.naipe, buffer.valor));
        load_carta(&buffer, f);
    }
}
/**
 * @brief sair
 */
void sair(){
    int aux;

    printf("Sair sem salvar? \n");
    printf("1.Sim\t2.Cancelar\n");
    scanf("%d", &aux);

    if(aux) exit(0);
}
