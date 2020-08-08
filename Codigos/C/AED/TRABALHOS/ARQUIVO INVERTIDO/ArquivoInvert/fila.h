#ifndef FILA_H
#define FILA_H
#include <stdio.h>
#include <stdlib.h>

/**
  * estrutura de n� para fila de lista encadeada
  */
typedef struct QNode {

    /**
     * @brief info, valor armazenado
     * @brief next, ponteiro para o proximo
    */
    void *info;
    struct QNode *prox;

} QNode;

/**
 *estrutura de fila de lista encadeada
 */
typedef struct Queue {

    /**
     * @brief ponteiro para comeco e fim da fila, e um contador
     */
    QNode *first, *last;
    int count;

} Queue;

//- INITIALIZE -//

/**
 * cria uma nova fila
 * @return fila alocada e inicializada
 * @precondition nenhuma
 * @postcondition fila � criada e retornada
 */
Queue *createQueue();

/**
 * cria um n� de fila
 * @param info valor a ser armazenado pelo novo n�
 * @return n� alocado e inicializado
 * @precondition nenhuma
 * @postcondition n� � criado e retornado
 */
QNode *createQNode(void *info);

//- UPDATE -//

/**
 * insere valor no final da fila
 * @param queue fila a ser inserido o valor
 * @param info valor a ser inserido na fila
 * @precondition nenhuma
 * @postcondition nenhuma
 */
void pushQ(Queue *queue, void *info);

/**
 * retorna valor o come�o da fila
 * @param queue � a fila ser modificada
 * @return n� no come�o da fila
 * @precondition nenhuma
 * @postcondition n� no come�o da fila � modificado
 */
QNode *popQ(Queue *queue);

//- DELETE -//

/**
 * remove a fila
 * @param queue fila a ser liberada
 * @precondition nenhuma
 * @postcondition nenhuma
 */
void deleteQueue(Queue *queue);

//- SHOW -//

/**
 * printa na saida padr�o a fila indicada
 * @param queue fila indicada
 * @precondition nenhuma
 * @postcondition nenhuma
 */
void printQ(Queue *queue);
#endif // FILA_H

