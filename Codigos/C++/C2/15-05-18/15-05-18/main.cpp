#include "lista.h"
#include "pessoa.h"


int main() {
   Pessoa p1 ( 0, "Teresinha");
   Pessoa p2 ( 1, "Antonio");
   Pessoa p3 ( 2, "Maria");
   Pessoa p4 ( 3, "Emy");

   //cout << p1 << endl;


    Lista<Pessoa> *l = new Lista<Pessoa>();

   // Pessoa p ()

    l->InsereOrdenado( p1 );
    l->InsereOrdenado( p2 );
    l->InsereOrdenado( p3 );
    l->InsereOrdenado( p4 );

    l->Mostra();

    delete l;


    Lista<int> *i = new Lista<int>();
    i->InsereFinal(0);
    i->InsereFinal(1);
    i->InsereFinal(2);
    i->Mostra();

    delete i;


    Lista<float> *p = new Lista<float>();
    p->InsereOrdenado(70.7);
    p->InsereOrdenado(10.0);
    p->InsereOrdenado(805);
    p->InsereOrdenado(1.2);
    p->InsereOrdenado(0.5);


    p->Mostra();

    delete p;

    Pessoa *x1 = new Pessoa ( 0, "Teresinha");
    Pessoa *x2 = new Pessoa ( 1, "Antonio");
    Pessoa *x3 = new Pessoa ( 2, "Maria");
    Pessoa *x4 = new Pessoa ( 3, "Emy");

    //cout << p1 << endl;


     Lista<Pessoa*> *x = new Lista<Pessoa*>();

    // Pessoa p ()

     x->InsereOrdenado( x1 );
     x->InsereOrdenado( x2 );
     x->InsereOrdenado( x3 );
     x->InsereOrdenado( x4 );

     x->Mostra();

     delete x;

    return 0;
}
