#include "exercicio.h"

int main(void){

    Fila *f = criar_fila();

    enqueue(f, 1);
    enqueue(f, 6);
    enqueue(f, 7);

    imprime(f);

    printf("Retirado: %d\n", dequeue(f));
    printf("Retirado: %d\n", dequeue(f));


    imprime(f);
    return 0;
}

