#include "exercicio1.h"

int main(void)
{
    struct no* l = cria_lista();

    l = insere(l, 50);
    imprime(l);
    l = inserir_apos(l, 50, 1);
    imprime(l);
    l = inserir_apos(l, 1, 2);
    imprime(l);
    l = inserir_apos(l, 2, 5);
    imprime(l);
    l = inserir_apos(l, 6, 6);
    imprime(l);

    return 0;
}

