#include "controllerpessoa.h"

ControllerPessoa::ControllerPessoa(QObject *parent) : QObject(parent)
{
    dao = new DaoPessoa();

    viewConsultar = new ViewConsultarPessoa();
    viewManter = new ViewManterPessoa();
    connect (viewConsultar, SIGNAL(finished(int)), this, SLOT(deletelater()));

        //connect(_dao, SIGNAL(notify(Actions, Oblect*)), _viewConsultar, SLOT(notify(

    connect (viewConsultar, SIGNAL(consultarTodos()), this, SLOT(consultarTodos()));
    connect (viewConsultar, SIGNAL(manter(Model*)), viewManter, SLOT(manter(Model*)));
}

QWidget *ControllerPessoa::getWidget(){
    return viewConsultar;
}

void ControllerPessoa::consultarTodos()
{
    viewConsultar->mostrar(dao->consultarTodos());
}


ControllerPessoa::~ControllerPessoa()
{
    qDebug() << "Deletando ControllerPessoa";
    delete viewConsultar;
    delete viewManter;
    delete dao;
}

