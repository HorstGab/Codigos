// Aula 27/03, 29/03,
#include <iostream>

using namespace std;

#include"pessoa.h"
#include"funcionario.h"

int main()
{
    /*Pessoa pessoa;
    pessoa.setar();
    pessoa.mostrar();

    Pessoa *pessoa=0; // =0 ou =NULL
    pessoa = new Pessoa ();
    pessoa->setar(); // sem ser ponteiro eh o ponto(.), com ponteiro (->)
    pessoa->mostrar();
    delete pessoa; // desalocação dinamica.*/

    Funcionario *f = new Funcionario();

    f->setar();
    f->mostrar();

    delete f;
    return 0;
}

