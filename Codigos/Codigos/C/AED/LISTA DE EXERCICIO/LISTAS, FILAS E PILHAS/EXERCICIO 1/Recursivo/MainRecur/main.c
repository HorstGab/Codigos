#include "exerc1_rec.h"


int main(void){

   Lista *li = criarLista();
   //Lista *l = criarLista();
   printf("CRIANDO LISTA ... \n");

   li = insere(li,5);
   li = insere(li,8);
   li = insere(li,7);
   li = insere(li,9);
   li = insere(li,12);
   li = insere(li,4);
   li = insere(li,3);


   imprime(li);

   li = remover(li, 7);
   li = remover(li,5);

   printf("\n");
   imprime(li);

   //l = inverte(li);

   //imprime(l);

   if(vazia(li)){
       printf("\n EH VAZIA \n");
   }else{
       printf("\n NAO EH VAZIA \n");
   }
    return 0;
}

