#include "lista.h"

/*!
    \file lista.cpp
    \class Lista
    \author Hannah C. Mariani
*/

///Construtor
Lista::Lista(){
    this->prox = NULL;
}

Lista::Lista(int info){
        this->info = info;
        this->prox = NULL;
}

///Ponteiro que o proximo nó aponta
Lista **Lista::getProxptr(){
    return &this->prox;

}

///Nó que o ponteiro aponta
Lista *Lista::getProx(){
    return this->prox;
}

///Valor da lista
int Lista::getInfo(){
    return this->info;
}


/// Seta o proximo info da Lista
void *Lista::setProx(Lista* li){
    this->prox = li;
}

/// Inserção de uma nova info no final da Lista
Lista *Lista::InsereFim(Lista *&H, int info){

    if(H == NULL){
        H = new Lista (info);
        return H;
    }else{
       H->setProx(InsereFim(*H->getProxptr(), info));
       return H;
    }
}

Lista *Lista::isEmpty(Lista* li) const{
    if(li == NULL){
        return true;
    } else{
        return false;
    }
}


///Impreção da Lista
void Lista::Show(Lista* li){
    Lista **aux;

    cout << "! --> ";
    if(li != NULL){
        aux = &li;
        while(*aux != NULL){
            cout << (*aux)->getInfo() << " --> ";
            aux = (*aux)->getProxptr();
        }
    }
    cout << "Null" << endl;
}

///Destrutor
Lista::~Lista(){
    if(this->prox != NULL){
        delete(prox);
    }
}
