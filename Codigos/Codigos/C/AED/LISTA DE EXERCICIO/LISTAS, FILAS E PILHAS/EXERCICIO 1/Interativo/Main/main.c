#include "exercicio1.h"


int main(void){

   Lista *li = criarLista();
   Lista *l = criarLista();
   printf("CRIANDO LISTA ... \n");

   li = insere(li,5);
   li = insere(li,8);
   li = insere(li,7);
   li = insere(li,9);
   li = insere(li,5);
   li = insere(li,5);
   li = insere(li,5);


   imprime(li);

   li = remover(li, 7);
   li = remover(li,5);

   imprime(li);

   l = inverte(li);

   imprime(l);

   printf("Numero 5 ocorre ... %d vezes \n", conta_ocorrencias(li, 5));

   if(vazia(li)){
       printf("EH VAZIA \n");
   }else{
       printf("NAO EH VAZIA \n");
   }


    return 0;
}

