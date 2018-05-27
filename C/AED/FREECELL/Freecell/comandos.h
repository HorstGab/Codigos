#ifndef COMANDOS
#define COMANDOS

#define MAXSTR 512

#include <stdio.h>
#include <math.h>
#include <ctype.h>

#include "pilhas.h"

//mostra os comandos aceitos
int comandos_possiveis();

//le os comandos
void imput_comandos(Mesa* mesa);

//le o comando para enviar para as fundacoes
void cmd_fundacao(char cmd[], char* coluna_origem);

//le o comando para enviar carta para as celulas
void cmd_insere_cel(char cmd[], char* coluna_origem, char* coluna_destino);

//le o comando para retirar carta das celulas
void cmd_remove_cel(char cmd[], char* coluna_origem, char* coluna_destino);

//le o comando que muda uma ou mais carta de uma coluna para outra
void cmd_colunas(char cmd[],char* coluna_origem, int* qnt_cartas, char* coluna_destino);

//movimenta a carta para a fundacão
void insere_fundacoes(Mesa* mesa, char coluna_origem);

//insere cartas nas celulas livres
void insere_celulas(Mesa* mesa, char coluna_origem, char coluna_destino);

//retira cartas das celulas
void remove_celula(Mesa* mesa, char coluna_origem, char coluna_destino);

//move uma ou mais cartas de uma coluna para outra
void move_coluna(Mesa* mesa, char coluna_origem, int qnt_cartas, char coluna_destino);

char getNaipe(char str);

#endif // COMANDOS

