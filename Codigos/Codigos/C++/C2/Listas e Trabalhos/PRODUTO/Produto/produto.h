#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>
#include <string>
using namespace std;
using std::string;

#define MAX 10

class Produto{
private:
    int codigo;
    string *nome;
    int qnt;
    double valor;

    double totaliza();

public:
    Produto();
    Produto(int codigo);
    Produto(int codigo, string *nome, int qnt, double valor);

    int getCodigo();
    string* getNome();
    int getQnt();
    double getValor();

    void setCodigo(int codigo);
    void setNome(string *nome);
    void setQnt(int qnt);
    void setValor(double valor);

    double atualizar(double porcent);
    string* toString();

    ~Produto();
};

#endif // PRODUTO_H
