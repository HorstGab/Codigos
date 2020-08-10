#ifndef PESSOA_H
#define PESSOA_H

#include "data.h"

class pessoa{
private:
    string nome;
    data* nascimento;
    float altura;
    int idade;
public:
    pessoa();
    pessoa(string nome, data* nascimento, float altura);

    string getNome();
    data* getNascimento();
    float getAltura();

    void setNome(string nome);
    void setNascimento(data *Data);
    void setAltura(float altura);

    void mostrarPessoa(data *nascimento);
    void idadeCalc(data* nascimento);

    ~pessoa();
};

#endif // PESSOA_H
