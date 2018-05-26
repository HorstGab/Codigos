#include "lista.h"

Lista::Lista(){
    this->prox = NULL;
}

Lista::Lista(int info){
        this->info = info;
        this->prox = NULL;
}

Lista **Lista::getProxptr(){ //pegar o ponteiro que o proximo nó aponta
    return &this->prox;

}

Lista *Lista::getProx(){ //pega o nó que o ponteiro aponta
    return this->prox;
}

int Lista::getInfo(){ //pega o valor da lista
    return this->info;
}

void *Lista::setProx(Lista* li){
    this->prox = li;
}

Lista *Lista::insere_Fim(Lista *&H, int info){

    if(H == NULL){
        H = new Lista (info);
        return H;
    }else{
       H->setProx(insere_Fim(*H->getProxptr(), info));
       return H;
    }
}

void Lista::imprime(Lista* li){
    Lista **aux;

    cout << "->";
    if(li != NULL){
        aux = &li;
        while(*aux != NULL){
            cout << (*aux)->getInfo() << "-> ";
            aux = (*aux)->getProxptr();
        }
    }
    cout << "Null" << endl;
}

Lista::~Lista(){
    if(this->prox != NULL){
        delete(prox);
    }
}

