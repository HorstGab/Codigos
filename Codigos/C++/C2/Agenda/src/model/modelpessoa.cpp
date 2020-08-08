#include "model/modelpessoa.h"
#include "model/model.h"

ModelPessoa ::ModelPessoa( QObject *parent) : Model(parent) {
    this->idPessoa = -1;
}

Model* ModelPessoa::clone () {
    ModelPessoa *m = new ModelPessoa();
    m->setIdPessoa(this->idPessoa);
    m->setCpf( this->cpf);
    m->setNome ( this->nome);
    m->setDtNascimento(this->dtNascimento);
    m->setSexo(this->sexo);
    return m;
}

QString ModelPessoa::toString () {
    return "id: " +QString::number(this->idPessoa)+
            "Nome: " + this->nome;
}



QString ModelPessoa::getNome() const
{
    return nome;
}

void ModelPessoa::setNome(const QString &value)
{
    nome = value;
}

QString ModelPessoa::getCpf() const
{
return cpf;
}

void ModelPessoa::setCpf(const QString &value)
{
    cpf = value;
}

QDate ModelPessoa::getDtNascimento() const
{
    return dtNascimento;
}

void ModelPessoa::setDtNascimento(const QDate &value)
{
    dtNascimento = value;
}

char ModelPessoa::getSexo() const
{
    return sexo;
}

void ModelPessoa::setSexo(char value)
{
    sexo = value;
}
int ModelPessoa::getIdPessoa() const
{
    return idPessoa;
}

void ModelPessoa::setIdPessoa(int value)
{
    idPessoa = value;
}
