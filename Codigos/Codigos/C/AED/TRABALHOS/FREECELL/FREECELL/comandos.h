#ifndef COMANDOS
#define COMANDOS

#define MAXSTR 512

#include <stdio.h>
#include <math.h>
#include <ctype.h>

#include "pilhas.h"
#include "start.h"


#include <conio.h>

//le os comandos
/**
 * @brief imput_comandos
 * @param mesa
 * @return nenhum
 * @pre-condicao nenhuma
 * @pos-condicao nenhuma
 */
void imput_comandos(Mesa* mesa);

//mostra os comandos aceitos
/**
 * @brief comandos_possiveis
 * @param nenhum
 * @return tipo de comando
 * @pre condicao nenhuma
 * @pos condicao nenhuma
 */
int comandos_possiveis();

//le o comando para enviar para as fundacoes
/**
 * @brief cmd_fundacao
 * @param coluna_origem
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao le a referencia da carta
 */
void cmd_fundacao(char *coluna_origem);

//le o comando para enviar carta para as celulas
/**
 * @brief cmd_insere_cel
 * @param coluna_origem
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao le a referencia da carta
 */
void cmd_insere_cel(char* coluna_origem);

//le o comando para retirar carta das celulas
/**
 * @brief cmd_remove_cel
 * @param coluna_origem
 * @param coluna_destino
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao le as referencias da carta
 */
void cmd_remove_cel(char* coluna_origem, char* coluna_destino);

//le o comando para enviar das reservas para as fundações
/**
 * @brief cmd_cel_fund
 * @param coluna_origem
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao le a referencia da carta
 */
void  cmd_cel_fund(char* coluna_origem);

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
void cmd_colunas(char* coluna_origem, int* qnt_cartas, char* coluna_destino);

//movimenta a carta para a fundacão
/**
 * @brief insere_fundacoes
 * @param mesa
 * @param coluna_origem
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao carta inserida na fundacao
 */
void insere_fundacoes(Mesa* mesa, char coluna_origem);

//insere cartas nas celulas livres
/**
 * @brief insere_celulas
 * @param mesa
 * @param coluna_origem
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao carta inserida nas celulas de reserva
 */
void insere_celulas(Mesa* mesa, char coluna_origem);

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
void remove_celula(Mesa* mesa, char coluna_origem, char coluna_destino);

//retira a carta das celulas e envia para as fundações
/**
 * @brief cel_fund
 * @param mesa
 * @param coluna_origem
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao carta removida da celula e inserida na fundacao
 */
void cel_fund(Mesa* mesa, char coluna_origem);

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
void move_coluna(Mesa* mesa, char coluna_origem, int qnt_cartas, char coluna_destino);

//valida se uma coluna de cartas está de acordo para a movimentaçáo
/**
 * @brief validacao_coluna
 * @param no
 * @param qnt_cartas
 * @return no se a pilha de carta for valida e null caso contrario
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
No *validacao_coluna(No* no, int qnt_cartas);

//retorna o naipe
/**
 * @brief getNaipe
 * @param str
 * @return valor do naipe da posicao do vetor global
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
char getNaipe(unsigned char str);

//retorna o valor da carta
/**
 * @brief getValor
 * @param str
 * @return valor do valor da posicao do vetor global
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
char getValor(unsigned char str);

/////////////////////////////////
//salva o jogo
/**
 * @brief salvar
 * @param mesa
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
void salvar(Mesa* mesa);

//carrega um jogo ja salvo
/**
 * @brief salvar
 * @param mesa
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao nenhum
 */

void carregar(Mesa* mesa);

//salva as colunas, fundacoes e celulas no arquivo
/**
 * @brief salvar_jogo
 * @param mesa
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
void salvar_jogo(Mesa* mesa);

//salva a fundacao no arquivo
/**
 * @brief save_fundacao
 * @param mesa
 * @param f
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
void save_fundacao(Mesa* mesa, FILE* f);

//salva as cartas no arquivo
/**
 * @brief save_carta
 * @param f
 * @param carta
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao salva carta no arquivo
 */
void save_carta(FILE *f, Carta *carta);

//salva as celula no arquivo
/**
 * @brief save_celula
 * @param mesa
 * @param f
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
void save_celula(Mesa* mesa, FILE* f);

//salva as colunas no arquivo
/**
 * @brief save_coluna
 * @param mesa
 * @param f
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
void save_coluna(Mesa* mesa, FILE* f);

//salva as pilhas no arquivo
/**
 * @brief save_pilha
 * @param no
 * @param f
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
void save_pilha(No* no, FILE* f);

//carrega um jogo do arquivo
/**
 * @brief carregar_jogo
 * @param mesa
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
void carregar_jogo(Mesa* mesa);

//carrega as cartas do arquivo
/**
 * @brief load_carta
 * @param buffer
 * @param f
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao le uma carta do arquivo
 */
void load_carta(Carta *buffer, FILE* f);

//carrega as celulas do arquivo
/**
 * @brief load_celula
 * @param mesa
 * @param f
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
void load_celula(Mesa* mesa, FILE* f);

//carrega as fundacoes do arquivo
/**
 * @brief load_fundacao
 * @param mesa
 * @param f
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
void load_fundacao(Mesa* mesa, FILE* f);

//carrega as colunas do arquivo
/**
 * @brief load_coluna
 * @param mesa
 * @param f
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
void load_coluna(Mesa* mesa, FILE* f);

//carrega as pilhas do arquivo
/**
 * @brief load_pilha
 * @param pilha
 * @param f
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
void load_pilha(Pilha* pilha, FILE* f);

//sai do jogo
/**
 * @brief sair
 * @param nenhum
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao saiu do jogo
 */
void sair();

#endif // COMANDOS

