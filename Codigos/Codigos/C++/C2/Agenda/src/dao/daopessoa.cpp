#include "daopessoa.h"
#include <QDebug>

DaoPessoa::DaoPessoa(QObject *parent) : Dao(parent)
{
    list.clear();
}

QList<ModelPessoa *> *DaoPessoa::consultarTodos()
{
    QList<ModelPessoa*> *l = new QList<ModelPessoa*>();
    for( int i = 0; i < list.count(); i++){
        l->append((ModelPessoa*)list.at(i)->clone());
    }
    return l;
}

int DaoPessoa::getIndex(ModelPessoa *p){
    for( int i = 0; i < list.count(); i++){
        if(p->getIdPessoa() == list.at(i)->getIdPessoa())
            return 1;
    }
    return -1;
}

void DaoPessoa::salvar(ModelPessoa *p)
{
    if(p->getIdPessoa()== -1){
        p->setIdPessoa(this->updateIndex());
        list.append(p);
        emit notify(p, INCLUIR);
    }else{
        int index = getIndex(p);
        if(index >= 0){
            list.replace(index, p);
            emit notify(p, ATUALIZAR);
        }else{
            qCritical () << "Pessoa nao localiza";
        }
    }
}

void DaoPessoa::excluir(ModelPessoa *p)
{
    int index = getIndex(p);
    if(index >= 0){
        list.removeAt(index);
        emit notify(p, EXCLUIR);
    }else{
        qCritical () << "Pessoa nao localiza";
    }
}

