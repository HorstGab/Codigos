#include "quimico.h"

Quimico::Quimico() : Produto()
{
    this->inflamavel = false;
}

Quimico::Quimico(int codigo) : Produto(codigo)
{
    this->inflamavel = false;
}

Quimico::Quimico(int codigo, string *nome, int qnt, double valor) : Produto(codigo, nome, qnt, valor)
{
    this->inflamavel = false;
}

bool Quimico::getInflamavel() const
{
    return inflamavel;
}

void Quimico::setInflamavel(bool value)
{
    inflamavel = value;
}

string *Quimico::toString()
{
    char buffer[258] = {0};

    sprintf(buffer, "(%d):\t nome = %s\t inflamavel = %s\t valor = %.2lf\t qnt = %d\n",
           this->getCodigo(), this->getNome()->c_str(), this->inflamavel ? "sim" : "Nao" ,this->getValor(), this->getQnt());

    string *strBuffer = new string (buffer);

    return strBuffer;

}

Quimico::~Quimico()
{

}

