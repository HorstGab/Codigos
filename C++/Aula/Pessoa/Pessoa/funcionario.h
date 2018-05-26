#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "pessoa.h"

class Funcionario : public Pessoa // definição de uma subclasse da classe pessoa ( funcionario herda de pessoa funcionario : pessoa)
{
private:
    int faltas;
    char data_admissao[10];
    double salario_base;
public:
    Funcionario(void);
    void setar(); // redefinando pq o setar daqui tera que fazer mais coisa que o setar de 'pessoa'
    void mostrar(); // nao querdizer que vamos perde o de 'pessoa', ele só foi redefino pq fará mais coisas. agora ele irá informar faltas, data de admissao e salario base.
    ~Funcionario();
};

#endif // FUNCIONARIO_H
