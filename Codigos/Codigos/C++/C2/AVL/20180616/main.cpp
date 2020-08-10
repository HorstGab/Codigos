#include <QCoreApplication>

#include "avl.h"

#include "logger.h"

int main(int argc, char *argv[]) {

    qInstallMessageHandler(logHandler);

    AVL *r = NULL;

    AVL::insere( &r, 10);
    AVL::insere( &r, 15);
    AVL::insere( &r, 2);
    AVL::insere( &r, 33);
    AVL::insere( &r, 20);

    r->mostrar();
    delete r;



    delete Logger::getInstance();


    QCoreApplication a(argc, argv);

    return a.exec();
}
