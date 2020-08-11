#ifndef QUIMICO_H
#define QUIMICO_H

#include "produto.h"

class Quimico : public Produto{
private:
    bool inflamavel;

public:
    Quimico();
    Quimico(int codigo);
    Quimico(int codigo, string *nome, int qnt, double valor);


    bool getInflamavel() const;
    void setInflamavel(bool value);

    string* toString();

    ~Quimico();
};

#endif // QUIMICO_H
