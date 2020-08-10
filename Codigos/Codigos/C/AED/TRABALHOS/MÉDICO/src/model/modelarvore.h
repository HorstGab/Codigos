#ifndef MODELARVORE
#define MODELARVORE

#include <stdio.h>
#include <stdlib.h>
#include "model/modelmedico.h"
#include "model/modelarquivo.h"

#define ORDEM 5

typedef struct pilha{
    int posicao; // posicao no arquivo
    int id; //id de intificacao
}RegDados;

typedef struct no{
    int numChaves; //numero de chaves do no
    RegDados chaves[ORDEM]; //vetor de chaves
    int filho[ORDEM]; //vetor de filho
    int posicao; //posicao do no dentro do arquivo
}arvoreB;


typedef struct {
    int proxNode; //proxima posicao
}noLivre;

typedef struct {
    int raiz; //posicao da raiz
    int qntNo; //quantidade de nos
    int raizLivre; //raiz da lista de nós livres
    int qntNoLivre; //quantidades de nos livres
}Header;

/**
 * @brief offSet
 * @param pos
 * @return posicao dentro do arquivo
 * @pre nenhum
 * @post nenhum
 */
long int offSet(int pos);


/**
 * @brief abrirArquivoBinario
 * @param nomeArquivo
 * @param modo
 * @return arquivo aberto
 * @pre nenhum
 * @post nenhum
 */
FILE* abrirArquivoBinario(char* nomeArquivo, char* modo);


/**
 * @brief criarHeader
 * @param bd
 * @return nenhum
 * @pre nenhum
 * @post header criado
 */
void criarHeader (FILE* bd);


/**
 * @brief criarNode
 * @return nó nulo
 * @pre nenhum
 * @post nó criado
 */
arvoreB* criarNode ();


/**
 * @brief criarNoLivre
 * @return nó livre
 * @pre nenhum
 * @post nenhum
 */
noLivre* criarNoLivre();


/**
 * @brief escreverHeader
 * @param bd
 * @param header
 * @return nenhum
 * @pre nenhum
 * @post header escrito no arquivo
 */
void escreverHeader(FILE* bd, Header* header);

/**
 * @brief escreverNode
 * @param bd
 * @param header
 * @param node
 * @return posicao q o no foi inserido
 * @pre nenhum
 * @post no escrito no arquivo
 */
int escreverNode(FILE* bd, Header *header, arvoreB* node);


/**
 * @brief lerHeader
 * @param bd
 * @return header lido
 * @pre nenhum
 * @post header lido
 */
Header* lerHeader(FILE* bd);


/**
 * @brief lerNode
 * @param bd
 * @param pos
 * @return no lido
 * @pre nenhum
 * @post no lido
 */
arvoreB* lerNode (FILE* bd, int pos);

/**
 * @brief lerNoLivre
 * @param bd
 * @param pos
 * @return no lido
 * @pre nenhum
 * @post nenhum
 */
noLivre* lerNoLivre(FILE* bd, int pos);


/**
 * @brief insereChave
 * @param bd
 * @param id
 * @param posReg
 * @return nenhum
 * @pre nenhum
 * @post no inserido no arquivo
 */
void insereChave(FILE* bd, int id, int posReg);


/**
 * @brief insere_aux
 * @param bd
 * @param header
 * @param r
 * @param dados
 * @return nenhum
 * @pre a raiz deve existir
 * @post no inserido no arquivo
 */
void insere_aux(FILE* bd, Header* header, arvoreB* r, RegDados dados);

/**
 * @brief adicionaDireita
 * @param r
 * @param pos
 * @param dados
 * @param p
 * @return nenhum
 * @pre o no deve ser folha
 * @post chave inserido no no
 */
void adicionaDireita(arvoreB* r, int pos, RegDados dados, int p);

/**
 * @brief overflow
 * @param r
 * @return 1 se ocorrer overflow e 0 caso contrario
 * @pre nenhum
 * @post nenhum
 */
int overflow(arvoreB* r);

/**
 * @brief eh_folha
 * @param r
 * @return 1 se for folha e 0 caso contrario
 * @pre nenhum
 * @post nenhum
 */
int eh_folha(arvoreB* r);

/**
 * @brief split
 * @param r
 * @param m
 * @return no nó
 * @pre no com overflow
 * @post separa o nó em dois mais a raiz
 */
arvoreB* split(arvoreB* r, RegDados *m);

/**
 * @brief buscaPos
 * @param r
 * @param info
 * @param pos
 * @return a posicao que deve ser inserido o no
 * @pre nenhum
 * @post nenhum
 */
int buscaPos(arvoreB* r, int info, int* pos);

/**
 * @brief printNo
 * @param r
 * @param nenhum
 * @pre nenhum
 * @post nenhum
 */
void printNo(arvoreB* r);


#endif // MODELARVORE
