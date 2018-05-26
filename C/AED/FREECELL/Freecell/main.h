#ifndef CARTAS_H
#define CARTAS_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

//estrutura para a carta
typedef struct carta{
    int naipe;
    int valor;
}Carta;

typedef struct no{
    Carta* carta;
    struct no* prox;
}No;

typedef struct pilha{
    int tamanho;
    No* inicio;
    No* fim;
}Pilha;

//estrutura para a mesa
typedef struct _mesa{
    int celula_livre;
    int qnt_pilha_livre;
    Pilha* fundacoes[4];//vetor de pilhas homecell
    Carta* celulas[4];//vetor de cartas freecell
    Pilha* pilhas[8];//vetor de pilhas tableau
}Mesa;



//cria uma pilha vazia
Pilha* criar_pilha();

// cria um novo no
No* criar_no(Carta* carta);

//cria a mesa do jogo sem o baralho na mesa, todos os campos vazios
Mesa* Criar_Mesa();

//chama as funcões que inicializa o jogo
void iniciar_jogo();

//cria o vetor com todas as cartas
void Criar_Baralho(Carta* cartas[]);

//cria cada carta do baralho
Carta* Criar_Carta(int naipe, int valor);

//embaralha as cartas de posicões dentro do vetor
void Embaralhar(Carta* cartas[]);

//insere as cartas na mesa
Pilha* insere_carta(Pilha* pilha, Carta* carta);

//COMANDOS

//le os comandos
void imput_comandos(Mesa* mesa);

//mostra os comandos aceitos
int comandos_possiveis(cmd_tipo);

//le o comando para enviar para as fundacoes
void ler_cmd1(char cmd[], char* coluna_origem);

//movimenta a carta para a fundacão
void insere_fundacoes(Mesa* mesa, char* coluna_origem);

//le o comando para enviar carta para as celulas
void ler_cmd2(char cmd[], char* coluna_origem);


#endif // CARTAS_H

