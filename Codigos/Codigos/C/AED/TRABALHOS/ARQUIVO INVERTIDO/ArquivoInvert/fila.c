#include"fila.h"

/**
 * cria uma nova fila
 * @return fila alocada e inicializada
 * @precondition nenhuma
 * @postcondition fila é criada e retornada
 */
Queue *createQueue() {
    Queue *newQueue = (Queue *) malloc(sizeof(Queue));

    // inicializa os campos da Fila
    newQueue->count = 0;
    newQueue->first = NULL;
    newQueue->last = NULL;

    // retorna uma nova fila
    return newQueue;
}

/**
 * cria um nó de fila
 * @param info valor a ser armazenado pelo novo nó
 * @return nó alocado e inicializado
 * @precondition nenhuma
 * @postcondition nó é criado e retornado
 */
QNode *createQNode(void *info) {
    QNode *newQNode = (QNode *) malloc(sizeof(QNode));

    // inicializa o campo da lista encadeada
    newQNode->info = info;
    newQNode->prox = NULL;

    // retorna um novo no da fila
    return newQNode;
}

//- UPDATE -//

/**
 * insere valor no final da fila
 * @param queue fila a ser inserido o valor
 * @param info valor a ser inserido na fila
 * @precondition nenhuma
 * @postcondition nenhuma
 */
void pushQ(Queue *queue, void *info) {
    if (!queue) return;

    // cria um novo no
    QNode *newQNode = createQNode(info);

    // se a fila estiver vazia
    if (!queue->first) {

        // o novo no sera igual ao primeiro e ultima da fila (eh o unico)
        queue->first = queue->last = newQNode;
    } else {

        // senao, o proximo no apos o ultimo sera o novo no
        queue->last->prox = newQNode;

        // novo no passa ser o ultimo no da fila
        queue->last = newQNode;
    }

    // incrementa em um o numero de elementos da fila
    queue->count++;
}

/**
 * retorna valor o começo da fila
 * @param queue é a fila ser modificada
 * @return nó no começo da fila
 * @precondition nenhuma
 * @postcondition nó no começo da fila é modificado
 */
QNode *popQ(Queue *queue) {
    QNode *node = NULL;

    // verifica se a fila ja nao esta vazia
    if (!queue) return NULL;
    if (!queue->first) return NULL;

    // guarda o primeiro no em uma auxiliar
    node = queue->first;

    // o segundo elemento da fila passa ser o primeiro
    queue->first = node->prox;

    if (queue->first) {
    } else {
        queue->last = NULL;
    }

    // decrementa em um o numero de elementos da fila
    queue->count--;

    // retorna o no
    return node;
}

//- DELETE -//

/**
 * remove a fila
 * @param queue fila a ser liberada
 * @precondition nenhuma
 * @postcondition nenhuma
 */
void deleteQueue(Queue *queue) {
    QNode *i, *next;

    // loop para percorrer a fila
    for(i = queue->first; i; i = next) {
        next = i->prox;
        // libera cada posicao da fila
        free(i);
    }

    // libera espaço alocado para fila inteira
    free(queue);
}

//- SHOW -//

/**
 * printa na saida padrão a fila indicada
 * @param queue fila indicada
 * @precondition nenhuma
 * @postcondition nenhuma
 */
void printQ(Queue *queue) {
    QNode *i;

    // loop que percoda a fila
    for(i = queue->first; i; i = i->prox) {
        // e imprime cada elemento
        printf("[%s]\n", (char*)i->info);
    }
    printf("\n");
}
