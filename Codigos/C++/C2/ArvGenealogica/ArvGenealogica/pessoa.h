#ifndef PESSOA_H
#define PESSOA_H

#include<stdlib.h>
#include<string.h>
#include <iostream>

using namespace std;

class Pessoa{
protected:
    char* nome;
    Pessoa* pai;
    Pessoa* mae;
public:
    Pessoa(char* nome, Pessoa* pai, Pessoa* mae);
    Pessoa(char* nome);
    char* getnome();
    Pessoa* getmae();
    bool equals(Pessoa* p);
    bool antecessor(Pessoa* p);
    void mostrar(char *tipo, char *espaco= "");
    ~Pessoa();
};

#endif // PESSOA_H
