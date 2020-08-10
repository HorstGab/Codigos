#include "produto.h"

double Produto::totaliza()
{
    if(this->valor)
        return this->qnt*this->valor;
    cerr << "Nao Possui Produto a ser Totalizado" << endl;
    return 0;
}

Produto::Produto()
{
    this->codigo = 0;
    this->nome = '\0';
    this->qnt = 0;
    this->valor = 0;
}

Produto::Produto(int codigo)
{
    this->codigo = codigo;
    this->nome = NULL;
    this->qnt = 0;
    this->valor = 0;
}

Produto::Produto(int codigo, string *nome, int qnt, double valor)
{
    this->codigo = codigo;
    this->nome = nome;
    this->qnt = qnt;
    this->valor = valor;
}

int Produto::getCodigo()
{
    return this->codigo;
}

string *Produto::getNome()
{
    return this->nome;
}

int Produto::getQnt()
{
    return this->qnt;
}

double Produto::getValor()
{
    return this->valor;
}

void Produto::setCodigo(int codigo)
{
    this->codigo = codigo;
}

void Produto::setNome(string *nome)
{
    this->nome = nome;
}

void Produto::setQnt(int qnt)
{
    this->qnt = qnt;
}

void Produto::setValor(double valor)
{
    this->valor = valor;
}

double Produto::atualizar(double porcent)
{
    if(this->valor)
        return this->valor += (valor*porcent)/100;
    return 0;
}

string *Produto::toString()
{

    char buffer[258] = {0};

    sprintf(buffer, "(%d):\t nome = %s\t valor = %.2lf\t qnt = %d\t total = R$ %.2lf\n", this->codigo, this->nome->c_str(), this->valor, this->qnt, this->totaliza());

    string *strBuffer = new string (buffer);

    return strBuffer;


}

Produto::~Produto()
{

}

