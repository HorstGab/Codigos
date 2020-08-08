#ifndef DAO_H
#define DAO_H

#include <QObject>

const int INCLUIR = 0;
const int EXCLUIR = 1;
const int ATUALIZAR = 2;

class Dao : public QObject
{
    Q_OBJECT

private:
    int index;

public:
    explicit Dao( QObject *parent = 0);

    int updateIndex();


signals:

public slots:

};

#endif // DAO_H
