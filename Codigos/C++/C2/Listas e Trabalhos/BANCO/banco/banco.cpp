#include "banco.h"

banco::banco(){
    this->contas = new vector<conta*>();
}

void banco::criar_conta(int num, double saldo, double limite, double limiteSaque, tipoConta tc){
    conta* novaConta = new conta(num, saldo, limite, limiteSaque, tc);

    //push_back = insere no final do vector
    this->contas->push_back(novaConta);
}

void banco::desativar_conta(int num){
    conta *found_conta = this->achar_conta_ID(num);

    //se a conta n for nulo
    if(found_conta) {
        //desativa a conta
        found_conta->setActive(false);
    } else {
        //senao a conta n existe
        cerr << "Conta de numero [" << num << "] insexistente" << endl;
    }
}

conta *banco::achar_conta_ID(int num) {

    //iterar sobre o vetor dinamico de contas
    for(int i = 0; i < (int)this->contas->size(); ++i) {
        //se as contas forem iguais
        if(this->contas->at(i)->getNum() == num) {
            //retorna a conta
            return this->contas->at(i);
        }
    }
    //senao retorna nulo
    return NULL;
}

bool banco::transferencia(conta *c1, conta *c2, double valor){
    if((valor <= c1->getLimiteSaldo())&&((c1->getSaldo()-valor)>c1->getLimite())){
        c1->setSaldo(c1->getSaldo() - valor);
        c2->setSaldo(c2->getSaldo() + valor);
        movimentacao::adiciona(conta::getMovimentacao(), "Transferencia", valor, debito);
        return true;
    }else{
        cout << "Impossivel realizar transferencia!!! Saque indisponivel!! " << endl;
        return false;
    }
}

banco::~banco(){
    cout << "banco excluido!" << endl;
}

