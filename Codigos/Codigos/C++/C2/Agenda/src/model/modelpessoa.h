#ifndef MODELPESSOA_H
#define MODELPESSOA_H

#include "model.h"
#include <QDate>

class ModelPessoa : public Model {
private:
    int idPessoa;
    QString nome;
    QString cpf;
    QDate dtNascimento;
    char sexo;

public:


    ModelPessoa ( QObject *parent = 0 );
    Model *clone ();
    QString toString () ;

    int getIdPessoa() const;
    void setIdPessoa(int value);

    QString getNome() const;
    void setNome(const QString &value);

    QString getCpf() const;
    void setCpf(const QString &value);

    QDate getDtNascimento() const;
    void setDtNascimento(const QDate &value);

    char getSexo() const;
    void setSexo(char value);
};

#endif // MODELPESSOA_H


