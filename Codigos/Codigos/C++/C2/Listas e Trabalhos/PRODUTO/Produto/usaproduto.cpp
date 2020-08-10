#include "usaproduto.h"

UsaProduto::UsaProduto() : Quimico()
{

}

UsaProduto::UsaProduto(int codigo) : Quimico(codigo)
{

}

UsaProduto::UsaProduto(int codigo, string *nome, int qnt, double valor) : Quimico(codigo, nome, qnt, valor)
{

}

string *UsaProduto::toString()
{
    char buffer[258] = {0};

    sprintf(buffer, "(%d):\t nome = %s\t inflamavel = %s\t valor = %.2lf\t qnt = %d\n",
           this->getCodigo(), this->getNome()->c_str(), this->getInflamavel()? "sim" : "Nao" ,this->getValor(), this->getQnt());

    string *strBuffer = new string (buffer);

    return strBuffer;

}

UsaProduto::~UsaProduto()
{

}

