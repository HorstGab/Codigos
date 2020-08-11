#include<iostream>
#include "funcionario.h"

using namespace std;

Funcionario::Funcionario() : Pessoa ()
{
    // this-> "RAY"; não é permitido, pq ele é private da classe 'pessoa e não da classe 'funcionario'
    this->faltas = 0;
    this->data_admissao[0] ='\0';
    this->salario_base = 0;


}
    void Funcionario::setar(){
            char newline;
            cout << "Entre com os dados do funcionario:" << endl;
            Pessoa::setar(); // chama o setar da classe anterior. sem o pessoa antes ele chamará o setar da propria classe e entraria em um recurso eterno at
            cout << "Digite o salario base: ";
            cin >> salario_base;
            cout << "Digite a data de admissao: (dd/mm/yyyy) ";
            cin.get(newline);
            cin.get(this->data_admissao, 10, '\n');
            cin.get(newline);
            cout << "\nDigite o numero de faltas: ";
            cin >> faltas;

    }

    void Funcionario::mostrar(){
            cout << "SAIDA DE DADOS DE FUNCIONARIO" << endl;
            Pessoa::mostrar(); // chama o setar da classe anterior. sem o pessoa antes ele chamará o setar da propria classe e entraria em um recurso eterno at
            cout << "\nDigite o salario base: " << salario_base;
            cout << "\nDigite a data de admissao: " << data_admissao;
            cout << "\nFaltas: " << faltas << endl;
    }

    Funcionario::~Funcionario()
    {
        cout << "Destruindo funcionario\n" << endl;
    }


