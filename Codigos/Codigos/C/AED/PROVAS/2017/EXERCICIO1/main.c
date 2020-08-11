#include "exercicio1.h"


int main(void){

    Lista* li = cria_lista();

    li = insere(li, 2);
    li = insere(li, 5);
    li = insere(li, 6);
    li = insere(li, 6);
    li = insere(li, 1);

    imprime(impares(li));
    imprime(li);

    //li = remove_intervalo(li, 2, 5);
    printf(" MAIOR: %d \n", maximo(li));
    return 0;
}

