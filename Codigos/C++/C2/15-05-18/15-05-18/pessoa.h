#ifndef PESSOA_H
#define PESSOA_H


#include <iostream>
using namespace std;

class Pessoa {
protected:
    friend ostream &operator<<(ostream &output, Pessoa &p);
    friend ostream &operator<<(ostream &output, Pessoa *p);
    int idpessoa;
    char nome[100];
public:
    Pessoa(int idpessoa, char nome[] );
    Pessoa(const Pessoa&p);
    char *getNome();
    int  getIdPessoa();
    virtual bool operator>(Pessoa &p);
    virtual bool operator>(Pessoa *p);
    ~Pessoa();
};

#endif // PESSOA_H
