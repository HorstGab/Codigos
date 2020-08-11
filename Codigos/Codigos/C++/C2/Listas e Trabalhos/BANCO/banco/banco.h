#ifndef BANCO_H
#define BANCO_H

#include <vector>
#include "conta.h"
#include <iostream>
using namespace std;


class banco{
private:
    vector<conta*> *contas;
public:
    banco();

    void criar_conta(int num, double saldo, double limite, double limiteSaque, tipoConta tc);
    void desativar_conta(int num);
    bool transferencia(conta* c1, conta* c2, double valor);

    conta *achar_conta_ID(int num);

    ~banco();
};

#endif // BANCO_H
