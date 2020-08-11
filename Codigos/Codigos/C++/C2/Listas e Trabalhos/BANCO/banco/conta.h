#ifndef CONTA_CORRENTE_H
#define CONTA_CORRENTE_H

#include "movimentacao.h"
enum tipoConta {especial, normal};

class conta{
private:
    int num;
    double saldo;
    double limite;
    double limiteSaque;
    tipoConta tc;
    movimentacao *Movimentacao;
    bool active;
public:

    conta(int num, double saldo, double limite, double limiteSaque, tipoConta tc);

    int getNum();
    bool getActive();
    void setActive(bool value);
    double getSaldo();
    void setSaldo(double valor);
    double getLimite();
    double getLimiteSaldo();
    movimentacao* getMovimentacao();


    void mostrarSaldo();
    void mostrarExtrato();
    bool sacar(double valor);
    void depositar(double valor);
    bool equals(conta* cont);

    ~conta();
};

#endif // CONTA_CORRENTE_H
