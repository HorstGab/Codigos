#include "avl.h"

AVL::AVL(int n){
    this->n = n;
    this->esq = 0;
    this->dir = 0;
}

void AVL::insere(AVL **r, int n){

    if((*r) == 0){
        (*r) = new AVL (n);
    }else{
        if((*r)->n > n){
            insere(&((*r)->esq), n);
        }else{
            insere(&((*r)->dir), n);
        }
    }
}

void AVL::mostrar(){
    if(esq){
        esq->mostrar();
        cout << n << endl;
        //qDebug() << n;
        //qWarning
        //qCritical
    }
    if(dir){
        dir->mostrar();
    }
}

AVL::~AVL(){
    if(esq) delete esq;
    if(dir) delete dir;
}
