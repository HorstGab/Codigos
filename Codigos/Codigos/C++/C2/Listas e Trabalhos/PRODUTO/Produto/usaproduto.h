#ifndef USAPRODUTO_H
#define USAPRODUTO_H

#include "produto.h"
#include "quimico.h"

class UsaProduto : public Quimico{
public:
    UsaProduto();
    UsaProduto(int codigo);
    UsaProduto(int codigo, string *nome, int qnt, double valor);

    string* toString();

    ~UsaProduto();
};

#endif // USAPRODUTO_H
