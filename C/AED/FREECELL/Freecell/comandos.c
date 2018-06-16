#include "comandos.h"

//vetor com os valores e naipes das cartas
char naipe[4] = {'O','E','C','P'};
char valor[13] = {'A','2','3','4','5','6','7','8','9','1','J','Q','K'};

//le os comandos
/**
 * @brief imput_comandos
 * @param mesa
 * @return nenhum
 * @pre-condicao nenhuma
 * @pos-condicao nenhuma
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
        //sai do jogo
        sair();
        break;
    default:
        //caso comando for invalido
        printf("Comando invalido!\n");
        break;
    }
    getchar();
}

//mostra os comandos aceitos
/**
 * @brief comandos_possiveis
 * @param nenhum
 * @return tipo de comando
 * @pre condicao nenhuma
 * @pos condicao nenhuma
 */
int comandos_possiveis(){
    int cmd_tipo;

    //comandos possiveis
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

//le o comando para enviar para as fundacoes
/**
 * @brief cmd_fundacao
 * @param coluna_origem
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao le a referencia da carta
 */
void cmd_fundacao(char *coluna_origem){
    printf("Escolha a coluna: ");
    //le o char que representa a coluna
    scanf("%c", coluna_origem);
    //transforma em maiuscula
    *coluna_origem = toupper(*coluna_origem);
}

//le o comando para enviar carta para as celulas
/**
 * @brief cmd_insere_cel
 * @param coluna_origem
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao le a referencia da carta
 */
void cmd_insere_cel(char* coluna_origem){
    printf("Escolha a coluna a ser enviada para o campo de reserva: ");
    //le o char que representa a coluna
    scanf("%c", coluna_origem);
    //transforma em maiuscula
    *coluna_origem = toupper(*coluna_origem);
}

//le o comando para retirar carta das celulas
/**
 * @brief cmd_remove_cel
 * @param coluna_origem
 * @param coluna_destino
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao le as referencias da carta
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

//le o comando para enviar das reservas para as fundações
/**
 * @brief cmd_cel_fund
 * @param coluna_origem
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao le a referencia da carta
 */
void cmd_cel_fund(char *coluna_origem){
    printf("Escolha a celula a retirar a carta: ");
    //le o char que representa a celula
    scanf("%c",coluna_origem);
    //transforma em maiuscula
    *coluna_origem = toupper(*coluna_origem);
}

//le o comando que muda uma ou mais carta de uma coluna para outra
/**
 * @brief cmd_colunas
 * @param coluna_origem
 * @param qnt_cartas
 * @param coluna_destino
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao le as referencias da carta
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

//movimenta a carta para a fundacão
/**
 * @brief insere_fundacoes
 * @param mesa
 * @param coluna_origem
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao carta inserida na fundacao
 */
void insere_fundacoes(Mesa *mesa, char coluna_origem){
    Carta* carta = NULL;
    No* no = NULL;
    int indice_coluna = coluna_origem - 'A';

    //confere se a coluna está entre as colunas existentes
    if(coluna_origem >= 'A' && coluna_origem <= 'H'){
        //confere se o topo nao eh nulo
        if(mesa->pilhas[indice_coluna]->inicio){
            //carta recebe a carta do topo da pilha
            carta = mesa->pilhas[indice_coluna]->inicio->carta;
            //confere se a pilha do respectivo naipe na fundacao nao eh nula
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

//insere cartas nas celulas livres
/**
 * @brief insere_celulas
 * @param mesa
 * @param coluna_origem
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao carta inserida nas celulas de reserva
 */
void insere_celulas(Mesa *mesa, char coluna_origem){
    Carta* carta = NULL;
    No* no = NULL;
    int indice_coluna = coluna_origem - 'A';
    int i;

    //confere se a coluna esta entre as colunas validas
    if(coluna_origem >= 'A' && coluna_origem <= 'H'){
        //confere se as celulas livres sao diferentes que 0
        if(mesa->celula_livre){
            //confere se a carta no topo da pilha de cartas nao eh nula
            if(mesa->pilhas[indice_coluna]->inicio){
                for(i = 0; i < 4; i++){
                    //se a celula for nula
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

//retira cartas das celulas
/**
 * @brief remove_celula
 * @param mesa
 * @param coluna_origem
 * @param coluna_destino
 * @return nenhum
 * @pre condicao nenhuma
 * @pos condicao carta removida da celula e inserida as colunas
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
            //confere se a carta para retirar da celula nao eh nula
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

//retira a carta das celulas e envia para as fundações
/**
 * @brief cel_fund
 * @param mesa
 * @param coluna_origem
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao carta removida da celula e inserida na fundacao
 */
void cel_fund(Mesa *mesa, char coluna_origem){
    Carta* carta = NULL;
    No* no = NULL;
    int indice_coluna = coluna_origem - 'A';

    //confere se a celula esta entre as colunas validas
    if(coluna_origem >= 'A' && coluna_origem <= 'D'){
        //confere se a celula nao eh nula
        if(mesa->celulas[indice_coluna]){
            //carta recebe a carta da celula
            carta = mesa->celulas[indice_coluna];
            //confere se a pilha do vetor de fundacoes nao eh nula
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

//move uma ou mais cartas de uma coluna para outra
/**
 * @brief move_coluna
 * @param mesa
 * @param coluna_origem
 * @param qnt_cartas
 * @param coluna_destino
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao carta movida de uma coluna para outra
 */
void move_coluna(Mesa* mesa, char coluna_origem, int qnt_cartas, char coluna_destino){
    No *no_o = NULL, *no_d = NULL, *aux = NULL;
    Carta *carta_o = NULL, *carta_d = NULL;
    Pilha *pilha;
    int indice_coluna_o = coluna_origem - 'A';
    int indice_coluna_d = coluna_destino - 'A';
    int i;


    //confere se as colunas estao entre as colunas validas
    if(coluna_origem >= 'A' && coluna_origem <= 'H'){
        if(coluna_destino >= 'A' && coluna_destino <= 'H'){
            //se o topo da pilha nao for nula
            if(mesa->pilhas[indice_coluna_o]->inicio){
                //se a quantidade de cartas for menor que a permitida para movimentacao
                if(qnt_cartas <= (mesa->celula_livre+1) * pow(2, mesa->qnt_pilha_livre)){
                    //no recebe o topo
                    no_o = mesa->pilhas[indice_coluna_o]->inicio;
                    //aux recebe o no
                    aux = no_o;

                    //se as cartas forem diferentes de zero
                    if(!qnt_cartas){
                        return;
                    }
                    //se as cartas forem maiores que 1
                    if(qnt_cartas > 1){
                        aux = validacao_coluna(no_o, qnt_cartas);
                    }

                    //se o aux for diferente de nulo
                    if(aux != NULL){
                        //carta de origem recebe a carta do no auxiliar
                        carta_o = aux->carta;
                        //no de destino recebe o topo da coluna
                        no_d = mesa->pilhas[indice_coluna_d]->inicio;
                        //carta de destino recebe a carta do topo da coluna
                        carta_d = mesa->pilhas[indice_coluna_d]->inicio->carta;

                        //se a pilha for vazia ou os naipes forem diferentes
                        if(no_d == NULL || carta_o->naipe%2 != carta_d->naipe%2){

                            //se a pilha for vazia ou os valores sao uma unidade abaixo que a anterior
                            if(no_d == NULL || (carta_o->valor+1) == carta_d->valor){
                                //cria pilha
                                pilha = criar_pilha();

                                for(i = 0; i < qnt_cartas; i++){
                                    //remove o topo da coluna de origem
                                    no_d = pop(mesa->pilhas[indice_coluna_o]);
                                    //insere numa pilha auxilar
                                    pilha = insere_carta(pilha, no_d->carta);
                                    //liberta o no
                                    free(no_d);
                                }

                                for(i = 0; i < qnt_cartas; i++){
                                    //remove o topo da pilha auxiliar
                                    no_d = pop(pilha);
                                    //a coluna de destino recebe o topo
                                    mesa->pilhas[indice_coluna_d] = insere_carta(mesa->pilhas[indice_coluna_d], no_d->carta);
                                    //libera o no
                                    free(no_d);
                                }

                                //libera a pilha
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

//valida se uma coluna de cartas está de acordo para a movimentaçáo
/**
 * @brief validacao_coluna
 * @param no
 * @param qnt_cartas
 * @return no se a pilha de carta for valida e null caso contrario
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
No* validacao_coluna (No* no, int qnt_cartas){
    int i, vc = 0;

    for(i = 1; i < qnt_cartas; i++){
        //se o no e o proximo nao forem nulos
        if(no && no->prox){
            //se os naipes forem diferentes
            if(no->carta->naipe%2 != no->prox->carta->naipe%2){
                //se os valores da carta forem uma unidade abaixo da anterior
                if((no->carta->valor+1) == no->prox->carta->valor){
                    vc = 1;
                }else{
                    printf("As cartas nao possuem ordem valida! \n");
                }
            }else{
                printf("As cores das cartas precisam ser alternados! \n");
            }
        }else{
            printf("Quantidade de cartas inexistente! \n");
        }
        //no recebe o proximo
        no = no->prox;
    }

    //se for igual a 1
    if(vc == 1){
        //retorna o no
        return no;
    }else{
        return NULL;
    }
}

//salva o jogo
/**
 * @brief salvar
 * @param mesa
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
void salvar(Mesa* mesa){
    int x;

    printf("Salvar jogo? \n");
    printf("1. SIM \t2.CANCELAR\n");

    scanf("%d", &x);
    //testa se o usuario quer salvar o jogo
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

//carrega um jogo ja salvo
/**
 * @brief carregar
 * @param mesa
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
void carregar(Mesa* mesa){
    int x;

    printf("Carregar jogo? \n");
    printf("1. SIM \t2.CANCELAR\n");

    scanf("%d", &x);
    //testa se o usuario quer carregar o jogo
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

//retorna o naipe
/**
 * @brief getNaipe
 * @param str
 * @return valor do naipe da posicao do vetor global
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
char getNaipe(unsigned char str){
    return naipe[str];
}

//retorna o valor da carta
/**
 * @brief getValor
 * @param str
 * @return valor do valor da posicao do vetor global
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
char getValor(unsigned char str){
    return valor[str];
}

//salva as colunas, fundacoes e celulas no arquivo
/**
 * @brief salvar_jogo
 * @param mesa
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
void salvar_jogo(Mesa* mesa){
    FILE* f;
    char nome_arquivo[15];

    printf("Nome do arquivo: ");
    scanf("%s", nome_arquivo);

    //se o arquivo nao abriu
    if((f = fopen(nome_arquivo, "ab")) == NULL){
        printf("Erro! Arquivo nao pode ser aberto! \n");
    }else{
        //senao salve as informacoes
        save_celula(mesa, f);
        save_fundacao(mesa, f);
        save_coluna(mesa, f);
    }
    //fecha o arquivo
    fclose(f);
    system("cls");
}

//salva a fundacao no arquivo
/**
 * @brief save_fundacao
 * @param mesa
 * @param f
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
void save_fundacao(Mesa* mesa, FILE* f){
    int i;

    for(i = 0; i < 4; i++){
        //salva o topo no arquivo
        save_pilha(mesa->fundacoes[i]->inicio, f);
    }
}

//salva as cartas no arquivo
/**
 * @brief save_carta
 * @param f
 * @param carta
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao salva carta no arquivo
 */
void save_carta(FILE *f, Carta *carta) {
    Carta cartaNula; cartaNula.naipe = -1; cartaNula.valor = -1;

    //se a carta nao for nula
    if(carta) {
        //escreva a carta no arquivo
        fwrite(carta, sizeof(Carta), 1, f);
    } else {
        //senao escreva carta nula
        fwrite(&cartaNula, sizeof(Carta), 1, f);
    }
}

//salva as celula no arquivo
/**
 * @brief save_celula
 * @param mesa
 * @param f
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
void save_celula(Mesa* mesa, FILE* f){
    int i;
    Carta* carta = NULL;

    for(i = 0; i < 4; i++){
        //salva a carta das celulas
        carta = mesa->celulas[i];
        save_carta(f, carta);
    }
}

//salva as colunas no arquivo
/**
 * @brief save_coluna
 * @param mesa
 * @param f
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
void save_coluna(Mesa* mesa, FILE* f){
    int i;
    int andares;
    No* pilha_reversa[8] = {NULL};

    //inverte a pilha
    inverte_pilha(mesa->pilhas, pilha_reversa, &andares);
    for(i = 0; i < 8; i++){
        //salva as pilhas em arquivo
        save_pilha(pilha_reversa[i], f);
    }
}

//salva as pilhas no arquivo
/**
 * @brief save_pilha
 * @param no
 * @param f
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
void save_pilha(No* no, FILE* f){

    //enquanto o no nao for nulo
    while(no != NULL){
        //salva as cartas da pilha no arquivo
        save_carta(f, no->carta);
        no = no->prox;
    }

    //salve uma carta nula
    save_carta(f, NULL);
}

//carrega um jogo do arquivo
/**
 * @brief carregar_jogo
 * @param mesa
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
void carregar_jogo(Mesa* mesa){
    FILE* f;
    char nome_arquivo[15];

    printf("DIGITE O NOME DO JOGO SALVO! \n");
    getchar();
    scanf("%[^\n]%*c", nome_arquivo);

    //se o arquivo nao abrir
    if((f = fopen(nome_arquivo, "rb+")) == NULL){
        printf("Erro! Arquivo nao pode ser aberto! \n");
    }else{
        //senao salve as informacoes
        load_celula(mesa, f);
        load_fundacao(mesa, f);
        load_coluna(mesa, f);
    }
    //fecha o arquivo
    fclose(f);
    system("cls");
}

//carrega as cartas do arquivo
/**
 * @brief load_carta
 * @param buffer
 * @param f
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao le uma carta do arquivo
 */
void load_carta(Carta *buffer, FILE* f) {
    //le a carta do arquivo
    fread(buffer, sizeof(Carta), 1, f);
}

//carrega as celulas do arquivo
/**
 * @brief load_celula
 * @param mesa
 * @param f
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
void load_celula(Mesa* mesa, FILE* f){
    Carta buffer;
    int i;

    for(i = 0; i < 4; i++){
        //carrega a carta do arquivo
        load_carta(&buffer, f);
        if(buffer.naipe != -1) {
            //celula recebe a carta
            mesa->celulas[i] = Criar_Carta(buffer.naipe, buffer.valor);
        }
    }
}

//carrega as fundacoes do arquivo
/**
 * @brief load_fundacao
 * @param mesa
 * @param f
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
void load_fundacao(Mesa* mesa, FILE* f){
    int i;

    for(i = 0; i < 4; i++){
        //carrega a pilha do arquivo
        load_pilha(mesa->fundacoes[i], f);
    }
}

//carrega as colunas do arquivo
/**
 * @brief load_coluna
 * @param mesa
 * @param f
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
void load_coluna(Mesa* mesa, FILE* f){
    int i;

    for(i = 0; i < 8; i++){
        //carrega a pilha do arquivo
        load_pilha(mesa->pilhas[i], f);
    }
}

//carrega as pilhas do arquivo
/**
 * @brief load_pilha
 * @param pilha
 * @param f
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
void load_pilha(Pilha* pilha, FILE* f){
    Carta buffer;

    //carrega a carta do arquivo
    load_carta(&buffer, f);
    //enquanto nao for fim de arquivo
    while(!feof(f)){
        if(buffer.naipe == -1) {
            return;
        }
        //insere a carta na pilha
        insere_carta(pilha, Criar_Carta(buffer.naipe, buffer.valor));
        load_carta(&buffer, f);
    }
}

//sai do jogo
/**
 * @brief sair
 * @param nenhum
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao saiu do jogo
 */
void sair(){
    system("cls");
    //sair do jogo
    exit(0);
}
