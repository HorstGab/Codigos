#include "data.h"
#include "pessoa.h"
#include "agenda.h"

int main(){

    data *date = new data(30,9,1998);
    data *date2 = new data(3,5,2018);

    date->diferenca(date2);

    pessoa *p = new pessoa();

    p->setNome("Gabriel Horst");
    p->setNascimento(date);
    p->setAltura(1.8);

    p->idadeCalc(date);
    p->mostrarPessoa(date);

    agenda* g = new agenda();

    g->armazenarPessoa("Gabriel Horst Montoanelli", date, 1.8);
    g->buscaPessoa("Gabriel Horst Montoanelli");
    g->mostraAgenda();
    g->mostraPessoa(1);
    g->removePessoa("Gabriel Horst Montoanelli");

    delete(date);
    delete(date2);
    delete(p);
    delete(g);
    return 0;
}

