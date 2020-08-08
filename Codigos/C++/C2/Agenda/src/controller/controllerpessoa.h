#ifndef CONTROLLERPESSOA_H
#define CONTROLLERPESSOA_H

#include <QObject>
#include <QDebug>
#include "dao/daopessoa.h"
#include "view/viewconsultarpessoa.h"
#include "view/viewmanterpessoa.h"

class ControllerPessoa : public QObject
{
    Q_OBJECT
private:
    DaoPessoa *dao;
    ViewConsultarPessoa *viewConsultar;
    ViewManterPessoa *viewManter;


public:
    explicit ControllerPessoa(QObject *parent = 0);
    QWidget *getWidget();
    void consultarTodos();

    ~ControllerPessoa();
signals:

public slots:
};

#endif // CONTROLLERPESSOA_H
