#include <QCoreApplication>

#include "avl.h"
#include <QDebug>

int main(int argc, char *argv[]){

    AVL *r = NULL;

    AVL::insere(&r, 15);
    AVL::insere(&r, 05);
    AVL::insere(&r, 10);
    AVL::insere(&r, 20);

    r->mostrar();

    QCoreApplication a(argc, argv);

    return a.exec();
}
