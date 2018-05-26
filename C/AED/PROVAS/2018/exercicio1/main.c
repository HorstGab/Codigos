#include "exercicio.h"

int main(void){

    Lista* l = cria_lista();

    l = insere(l, 1);
    l = insere(l, 5);
    l = insere(l, 5);
    l = insere(l, 9);
    l = insere(l, 5);

    imprime(l);

    printf("O numero 5 repete: %d \n", conta_ocorrencias(l, 5));

    l = remover_enesimo(l, 4);
    imprime(l);

    return 0;
}

