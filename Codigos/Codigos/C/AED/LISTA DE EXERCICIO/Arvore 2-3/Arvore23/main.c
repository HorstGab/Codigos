#include "arvore23.h"


int main(void)
{
    arvore23 r = NULL;
    r = inserir(r,5);
    r = inserir(r,7);
    r = inserir(r,2);
//    r = inserir(r,11);
//    r = inserir(r,50);
//    r = inserir(r,35);
//    r = inserir(r,22);
//    r = inserir(r,13);
//    r = inserir(r,37);
//    r = inserir(r,6);
//    r = inserir(r,9);
//    r = inserir(r,44);
//    r = inserir(r,19);
//    r = inserir(r,83);
//    r = inserir(r,12);
//    r = inserir(r,8);
//    r = inserir(r,21);

    mostraArvore(r);

    printf("\nminimo = %d\n", minimo(r));
    printf("maximo = %d\n", maximo(r));
    printf("No = %d\n", conta_nos(r));

    in_ordem(r);
    return 0;
}

