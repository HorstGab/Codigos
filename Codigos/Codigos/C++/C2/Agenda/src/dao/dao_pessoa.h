#ifndef DAO_ALUNO_H
#define DAO_ALUNO_H

#include <QVector>
#include "dao.h"
#include "Util/global.h"
#include "Model/model_aluno.h"

class Dao_Aluno : public Dao
{
    Q_OBJECT
private:
    FILE *f;
    QString fileName;
    void insert( Model_Aluno *obj );
    void update ( Model_Aluno *obj );
    fpos_t findId( int id );

public:
    explicit Dao_Aluno(QObject *parent = 0);
    QVector<Model_Aluno*> *search(QString name="" );

signals:
    void notify ( Actions action, Model_Aluno *obj );

public slots:
    void save   ( Model_Aluno *obj );
    void remove ( Model_Aluno *obj );
};

#endif // DAO_ALUNO_H
