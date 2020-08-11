#include "model/modelfila.h"

/**
 * @brief cria_fila
 * @return fila nula
 * @pre nenhum
 * @post fila criada
 */
Fila* cria_fila() {

    //incializa a fila
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->qnt = 0;
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

/**
 * @brief criarNodeFila
 * @param info
 * @return no da fila nula
 * @pre nenhum
 * @post nenhum
 */
FNode* criarNodeFila(void* info){

    //inicializa o no da fila
    FNode* novoNo = (FNode*)malloc(sizeof(FNode));
    //atribui uma informacao
    novoNo->info = info;
    novoNo->prox = NULL;

    return novoNo;
}


/**
 * @brief enqueue
 * @param f
 * @param x
 * @return nenhum
 * @pre nenhum
 * @post item enfileirado
 */
void enqueue(Fila* f, void* x) {
    //se a fila n existir encerra
    if(!f) return;
    FNode* novoNo = criarNodeFila(x);

    //se o inicio n existir
    if(!f->inicio){
        //inicio e fim apontam pro novo no
        f->inicio = f->fim = novoNo;
    }else{
        //o final do proximo aponta pro novo no
        f->fim->prox = novoNo;
        //o fim aponta pro no
        f->fim = novoNo;
    }
    //incrementa a quantidade de nos
    f->qnt++;
}

/**
 * @brief dequeue
 * @param f
 * @return item do topo
 * @pre nenhum
 * @post item desenfileirado
 */
FNode* dequeue(Fila* f) {

    FNode* novoNo = NULL;
    //se a  lista ou o inicio for nulo encerra
    if(!f) return NULL;
    if(!f->inicio) return NULL;

    //novo no recebe o inicio
    novoNo = f->inicio;
    //o inicio aponta pra segunda posicao
    f->inicio = novoNo->prox;


    if(f->inicio){
    }else{
        f->fim  = NULL;
    }

    f->qnt--;

    //retorna o no da cabeca
    return novoNo;
}

/**
 * @brief deletaFila
 * @param f
 * @return nenhum
 * @pre nenhum
 * @post fila excluida
 */
void deletaFila(Fila *f){

    FNode* aux, *prox;

    //liberar todos os nos da fila
    for(aux = f->inicio; aux; aux = prox){
        prox = aux->prox;
        free(aux);
    }

    free(f);
}

/**
 * @brief printFila
 * @param f
 * @return nenhum
 * @pre nenhum
 * @post nenhum
 */
void printFila(Fila* f){

    FNode* aux;

    //mostra todos os nos da fila
    for(aux = f->inicio; aux; aux = aux->prox){
        printf("[0x%p] <->", aux->info);
    }
    printf("\n");

}
