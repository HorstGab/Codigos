#include "exercicio.h"


int main(void){

    Lista* l = criar_lista();

    l = insere(l, 5);
    l = insere(l, 8);

    imprime(l);

    return 0;
}

