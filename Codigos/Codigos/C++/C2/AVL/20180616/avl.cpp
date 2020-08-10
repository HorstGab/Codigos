#include "avl.h"

#include <QDebug>

AVL::AVL( int n) {
    this->n   = n;
    this->esq = 0;
    this->dir = 0;
}

void AVL::insere ( AVL **r, int n ) {
    if( (*r)==0) {
        (*r) = new AVL ( n );
    } else {
        if ((*r)->n>n) {
            insere ( &((*r)->esq), n );
        } else {
            insere ( &((*r)->dir), n );
        }
    }

}

void AVL::mostrar() {
    if (esq)
        esq->mostrar();
    qDebug() << n;
    qCritical () << n;
    qWarning () << n;

    if (dir)
        dir->mostrar();
}

AVL::~AVL() {
    qDebug() << "destruindo a arvores";
    if (esq) delete esq;
    if (dir) delete dir;
}
