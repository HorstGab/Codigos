#ifndef MODEL_H
#define MODEL_H

#include <QObject>

class Model : public QObject
{
    Q_OBJECT
public:

    Model(QObject *parent = 0) : QObject(parent){}

    virtual QString toString() {
        return this->objectName();
    }

    virtual Model *clone () {
        return 0;
    }

signals:

public slots:

};

#endif // MODEL_H


