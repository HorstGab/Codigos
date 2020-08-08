#include "elevador.h"
#include "lampada.h"
#include "lampadatresestados.h"

int main(){

   /* Elevador *elevador = new Elevador(10,5);

    elevador->entraPessoa();
    elevador->entraPessoa();
    elevador->entraPessoa();
    elevador->entraPessoa();

    elevador->mostrarAndar();
    elevador->mostrarNumPessoa();

    elevador->subir();
    elevador->saiPessoa();

    elevador->mostrarAndar();
    elevador->mostrarNumPessoa();

    elevador->subir();
    elevador->saiPessoa();
    elevador->saiPessoa();

    elevador->mostrarAndar();
    elevador->mostrarNumPessoa();

    delete elevador;*/

    Lampada* l = new Lampada();

    l->Ligar();
    l->Mostrar();
    l->Desligar();
    l->Mostrar();

    delete l;


    return 0;
}

