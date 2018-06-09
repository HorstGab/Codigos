#ifndef COMANDOS
#define COMANDOS

#define MAXSTR 512

#include <stdio.h>
#include <math.h>
#include <ctype.h>

#include "pilhas.h"
#include "start.h"


#include <conio.h>

//mostra os comandos aceitos
/**
 * @brief comandos_possiveis
 * @return
 */
int comandos_possiveis();

//le os comandos
/**
 * @brief imput_comandos
 * @param mesa
 */
void imput_comandos(Mesa* mesa);

//le o comando para enviar para as fundacoes
/**
 * @brief cmd_fundacao
 * @param coluna_origem
 */
void cmd_fundacao(char *coluna_origem);

//le o comando para enviar carta para as celulas
/**
 * @brief cmd_insere_cel
 * @param coluna_origem
 */
void cmd_insere_cel(char* coluna_origem);

//le o comando para retirar carta das celulas
/**
 * @brief cmd_remove_cel
 * @param coluna_origem
 * @param coluna_destino
 */
void cmd_remove_cel(char* coluna_origem, char* coluna_destino);

//le o comando para enviar das reservas para as fundações
/**
 * @brief cmd_cel_fund
 * @param coluna_origem
 */
void  cmd_cel_fund(char* coluna_origem);

//le o comando que muda uma ou mais carta de uma coluna para outra
/**
 * @brief cmd_colunas
 * @param coluna_origem
 * @param qnt_cartas
 * @param coluna_destino
 */
void cmd_colunas(char* coluna_origem, int* qnt_cartas, char* coluna_destino);

//movimenta a carta para a fundacão
/**
 * @brief insere_fundacoes
 * @param mesa
 * @param coluna_origem
 */
void insere_fundacoes(Mesa* mesa, char coluna_origem);

//insere cartas nas celulas livres
/**
 * @brief insere_celulas
 * @param mesa
 * @param coluna_origem
 */
void insere_celulas(Mesa* mesa, char coluna_origem);

//retira cartas das celulas
/**
 * @brief remove_celula
 * @param mesa
 * @param coluna_origem
 * @param coluna_destino
 */
void remove_celula(Mesa* mesa, char coluna_origem, char coluna_destino);

//retira a carta das celulas e envia para as fundações
/**
 * @brief cel_fund
 * @param mesa
 * @param coluna_origem
 */
void cel_fund(Mesa* mesa, char coluna_origem);

//move uma ou mais cartas de uma coluna para outra
/**
 * @brief move_coluna
 * @param mesa
 * @param coluna_origem
 * @param qnt_cartas
 * @param coluna_destino
 */
void move_coluna(Mesa* mesa, char coluna_origem, int qnt_cartas, char coluna_destino);

//valida se uma coluna de cartas está de acordo para a movimentaçáo
/**
 * @brief validacao_coluna
 * @param no
 * @param qnt_cartas
 * @return
 */
No *validacao_coluna(No* no, int qnt_cartas);

//encerrar o jogo
/**
 * @brief sair
 */
void sair();

//retorna o naipe
/**
 * @brief getNaipe
 * @param str
 * @return
 */
char getNaipe(unsigned char str);

//retorna o valor da carta
/**
 * @brief getValor
 * @param str
 * @return
 */
char getValor(unsigned char str);

/////////////////////////////////
//salva o jogo
/**
 * @brief salvar
 * @param mesa
 */
void salvar(Mesa* mesa);

//carrega um jogo ja salvo
/**
 * @brief carregar
 * @param mesa
 */
void carregar(Mesa* mesa);

/**
 * @brief salvar_jogo
 * @param mesa
 */
void salvar_jogo(Mesa* mesa);

/**
 * @brief save_fundacao
 * @param mesa
 * @param f
 */
void save_fundacao(Mesa* mesa, FILE* f);

/**
 * @brief save_celula
 * @param mesa
 * @param f
 */
void save_celula(Mesa* mesa, FILE* f);

/**
 * @brief save_coluna
 * @param mesa
 * @param f
 */
void save_coluna(Mesa* mesa, FILE* f);

/**
 * @brief save_pilha
 * @param no
 * @param f
 */
void save_pilha(No* no, FILE* f);

/**
 * @brief carregar_jogo
 * @param mesa
 */
void carregar_jogo(Mesa* mesa);

/**
 * @brief load_celula
 * @param mesa
 * @param f
 */
void load_celula(Mesa* mesa, FILE* f);

/**
 * @brief load_fundacao
 * @param mesa
 * @param f
 */
void load_fundacao(Mesa* mesa, FILE* f);

/**
 * @brief load_coluna
 * @param mesa
 * @param f
 */
void load_coluna(Mesa* mesa, FILE* f);

/**
 * @brief load_pilha
 * @param pilha
 * @param f
 */
void load_pilha(Pilha* pilha, FILE* f);

/**
 * @brief save_carta
 * @param f
 * @param carta
 */
void save_carta(FILE *f, Carta *carta);

/**
 * @brief load_carta
 * @param buffer
 * @param f
 */
void load_carta(Carta *buffer, FILE* f);

/**
 * @brief sair
 */
void sair();

#endif // COMANDOS

