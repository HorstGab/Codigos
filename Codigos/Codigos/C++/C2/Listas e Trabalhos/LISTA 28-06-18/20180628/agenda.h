#ifndef AGENDA_H
#define AGENDA_H

#include "pessoa.h"

class agenda{
private:
    pessoa* p[10];
    string nome;
    data* nascimento;
    float altura;
public:
    agenda();

    void armazenarPessoa(string nome, data *nascimento, float altura);
    void removePessoa(string nome);
    int buscaPessoa(string nome);
    void mostraAgenda();
    void mostraPessoa(int index);

    ~agenda();
};

#endif // AGENDA_H
