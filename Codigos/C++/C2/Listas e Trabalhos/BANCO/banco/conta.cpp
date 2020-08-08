#include "conta.h"

conta::conta(int num, double saldo, double limite, double limiteSaque, tipoConta tc){
    this->num = num;
    this->saldo = saldo;
    this->limite = limite;
    this->limiteSaque = limiteSaque;
    this->tc = tc;
    this->Movimentacao = NULL;
    this->active = true;
}

int conta::getNum(){
    return this->num;
}

bool conta::getActive(){
    return active;
}

void conta::setActive(bool value){
    this->active = value;
}

double conta::getSaldo(){
    return this->saldo;
}

void conta::setSaldo(double valor){
    this->saldo = valor;
}

double conta::getLimite(){
    return this->limite;
}

double conta::getLimiteSaldo(){
    return this->limiteSaque;
}

movimentacao* conta::getMovimentacao(){
    return this->Movimentacao;
}

void conta::mostrarSaldo(){
    cout << "Saldo" << endl << "Conta: " << this->num;
    cout << " -> Valor: " << this->saldo << endl;
}

void conta::mostrarExtrato(){
    cout << "Extrato" << endl << "Conta: " << this->num << endl;
    if(Movimentacao){
        Movimentacao->listar();
    }
}

bool conta::sacar(double valor){
    if((valor <= this->limiteSaque)&&((this->saldo-valor)>this->limite)){
        movimentacao::adiciona(&Movimentacao, "Saque", valor, debito);
        this->saldo -= valor;
        return true;
    }else{
        cout << "Saque indisponivel! " << endl << "Conta: " << this->num << endl;
        return false;
    }
}

void conta::depositar(double valor){

    movimentacao::adiciona(&Movimentacao, "Depositar", valor, credito);
    this->saldo += valor;
}

bool conta::equals(conta *cont){
    if(this->num == cont->num){
        return true;
    }else{
        return false;
    }
}

conta::~conta(){
    cout << "destruindo conta bancaria!!" << endl;
    if(Movimentacao){
        delete Movimentacao;
    }
}

