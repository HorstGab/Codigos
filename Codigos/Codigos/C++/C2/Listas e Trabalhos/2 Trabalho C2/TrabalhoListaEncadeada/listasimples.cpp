#include "listasimples.h"

/**
 * construtor
 * @brief No::No
 */
No::No(){
    //o proximo do no e nulo
    this->prox = NULL;
}

/**
 * construtor
 * @brief No::No
 * @param info
 */
No::No(int info){
    //no recebe a informacao e o proximo nulo
    this->info = info;
    this->prox = NULL;
}

/**
 * testa se eh vazia
 * @brief No::vazia
 * @param no
 * @return true se for vazia ou false se nao for
 */
bool No::vazia(No *&no)const{
    //se no eh nulo
    if(no == NULL){
        //retorna verdadeiro
        return true;
    }else{
        //caso contrario retorna falso
        return false;
    }
}

/**
 * insere no inicio da lista
 * @brief No::inserir_inicio
 * @param l
 * @param info
 * @return lista modificada
 */
No *No::inserir_inicio(No *&l, int info){
    //se a cabeca for nula
    if(l == NULL){
        //instancia nova lista
        l = new No(info);
        //retorna a lista
        return l;
    }else{
        //a lista recebe a informacao
        l->info = info;
        //proximo da lista recebe a nova cabeca
        l->prox = l;
        //retorna a nova cabeca
        return l;
    }
}

/**
 * insere no final da lista
 * @brief No::inserir_final
 * @param l
 * @param info
 * @return lista modificada
 */
No *No::inserir_final(No *&l, int info){
    //se a lista for vazia
    if(l == NULL){
        //instancia nova lista
        l = new No(info);
        //retorna a nova lista
        return l;
    }else{
        //recursivamente vai ate o ultimo elemento
        l->setProx(inserir_final(*l->getProxptr(),info));
        //retorna a lista
        return l;
    }
}

/**
 * remove a cabeca da lista
 * @brief No::remove_inicio
 * @param l
 */
void No::remove_inicio(No *&l){
    No *aux = NULL;

    //se a lista nao for nula
    if(l != NULL){
        //aux aponta pra cabeca
        aux = l;
        //pega a proxima cabeca
        l = l->prox;
        //libera a antiga cabeca
        free(aux);
    }
}

/**
 * remove o ultimo elemento da lista
 * @brief No::remove_final
 * @param l
 * @return lista modificada
 */
No *No::remove_final(No *&l){
    //se a cabeca ou o proximo forem nulo
    if(!l || !l->prox){
        //libera a cabeca
        free(l);
        //retorna nulo
        return NULL;
    }else{
        //recursivamnete vai ate o ultimo elemento
        l->prox = remove_final(*l->getProxptr());
        //retorna a lista
        return l;
    }
}

/**
 * mostra o numero de elementos da lista
 * @brief No::num_elem
 * @param li
 * @return no
 */
void No::num_elem(No *li){
    int aux = 0;

    //enquanto a lista n for vazia
    while(li != NULL){
        //incrementa aux a cada interacao
        aux++;
        li = li->prox;
    }
    //mostra a quantidade de elementos
    cout << "quantidade de elementos: " << aux << endl ;
    cout << endl;
}

/**
 * printa na tela a lista
 * @brief No::imprime
 * @param li
 */
void No::imprime(No* li){
    No *aux;

    cout << "->";
    // se a cabeca n for nula
    if(li != NULL){
        //aux recebe a cabeca da lista
        aux = li;
        //enquanto aux n for nulo
        while(aux != NULL){
            cout << aux->getInfo() << "-> ";
            //aux recebe o proximo
            aux = aux->getProx();
        }
    }
    cout << "Null" << endl;
}

/**
 * retorna o elemento de uma posicao e retorna ele
 * @brief No::return_no
 * @param li
 * @param pos
 * @return elemento retirado
 */
No *No::return_no(No *li, int pos){
    No *aux = NULL;

    //aux recebe a cabeca
    aux = li;

    for(int i = 1; i <= pos-1; i++){
        //se o proximo n for nulo
        if(aux->prox){
            //avanca pro proximo
            aux = aux->prox;
        }else{
            return NULL;
        }
    }
}

/**
 * pegar o ponteiro que o proximo nó aponta
 * @brief No::getProxptr
 * @return ponteiro do proximo do proximo
 */
No **No::getProxptr(){
    return &this->prox;
}


/**
 * pega o nó que o ponteiro aponta
 * @brief No::getProx
 * @return ponteiro do proximo
 */
No *No::getProx(){
    return this->prox;
}


/**
 * insere o valor da lista
 * @brief No::setProx
 * @param li
 */
void No::setProx(No* li){
    this->prox = li;
}


/**
 * pega o valor da lista
 * @brief No::getInfo
 * @return o valor do no
 */
int No::getInfo(){
    return this->info;
}


/**
 * destrutor
 * @brief No::~No
 */
No::~No(){
    cout << "Destruindo Lista" << endl;
}
