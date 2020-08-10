#ifndef DAOPESSOA_H
#define DAOPESSOA_H

#include <QObject>
#include <QList>

#include "dao.h"
#include "model/modelpessoa.h"

class DaoPessoa : public Dao
{
    Q_OBJECT
private:
    QList<ModelPessoa*> list;
    int getIndex(ModelPessoa *p);

public:
    DaoPessoa(QObject *parent = 0);
    QList<ModelPessoa*> *consultarTodos();
//    QList<ModelPessoa*> *consulta(Qline)

public slots:
    void salvar (ModelPessoa *p);
    void excluir (ModelPessoa *p);

signals:
    void notify(ModelPessoa *p, int action);

};

#endif // DAOPESSOA_H
