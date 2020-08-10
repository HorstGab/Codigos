#ifndef ELEVADOR_H
#define ELEVADOR_H

#include <iostream>

using namespace std;

class Elevador{
protected:
    int andarAtual;
    int andarTotal;
    int capacidade;
    int numPessoas;
public:
    Elevador(int capacidade, int andarTotal);
    void entraPessoa();
    void saiPessoa();
    void subir();
    void descer();

    int getAndarAtual();
    int getAndarTotal();
    int getCapacidade();
    int getNumPessoa();

    void mostrarAndar();
    void mostrarNumPessoa();

    ~Elevador();

};

#endif // ELEVADOR_H
