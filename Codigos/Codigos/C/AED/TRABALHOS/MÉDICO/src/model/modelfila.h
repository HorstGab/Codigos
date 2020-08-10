#ifndef MODELFILA_H
#define MODELFILA_H

#include "model/modelarvore.h"


typedef struct noL{
    void* info; //informacao do no
    struct noL* prox; //proximo no
}FNode;

typedef struct{
    FNode* inicio; //inicio da fila
    FNode* fim; //fim da fila
    int qnt; //quantidade de nos
} Fila;


/**
 * @brief cria_fila
 * @return fila nula
 * @pre nenhum
 * @post fila criada
 */
Fila* cria_fila();

/**
 * @brief criarNodeFila
 * @param info
 * @return no da fila nula
 * @pre nenhum
 * @post nenhum
 */
FNode* criarNodeFila(void *info);

/**
 * @brief enqueue
 * @param f
 * @param x
 * @return nenhum
 * @pre nenhum
 * @post item enfileirado
 */
void enqueue(Fila* f, void* x);

/**
 * @brief dequeue
 * @param f
 * @return item do topo
 * @pre nenhum
 * @post item desenfileirado
 */
FNode* dequeue(Fila* f);
/**
 * @brief deletaFila
 * @param f
 * @return nenhum
 * @pre nenhum
 * @post fila excluida
 */
void deletaFila(Fila* f);

/**
 * @brief printFila
 * @param f
 * @return nenhum
 * @pre nenhum
 * @post nenhum
 */
void printFila(Fila* f);
#endif // MODELFILA_H

