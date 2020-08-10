#include "dao.h"

Dao::Dao(QObject *parent) :
    QObject(parent) {
    index = 0;
}


int Dao::updateIndex() {
    return index++;
}

