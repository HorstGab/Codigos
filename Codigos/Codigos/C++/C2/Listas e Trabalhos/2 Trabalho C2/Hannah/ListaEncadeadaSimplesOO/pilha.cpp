#include "pilha.h"

/*!
    \file pilha.cpp
    \class Pilha
    \author Hannah C. Mariani
*/

Pilha::Pilha() : public Lista
{

}
/// Remoção da info no final da Lista
Pilha *Pilha::RemoveFim(Lista *&P) : public Lista{

      if(H == NULL){
          return -1;
      }else{
         delete(H);
         return 0;
      }
}
///Pilha Vazia
Pilha *Pilha::PilhaVazia(Pilha *P) : public Lista{
       boo aux = isEmpty(&P);

       if(aux == true){
            cout << "Pilha Vazia!" << endl;
       } else {
            cout << "Pilha Com Conteudo!" << endl;
       }
}



/*
  No* pop(Pilha *pilha){
      No* aux;

      if(pilha || pilha->inicio){
          aux = pilha->inicio;
          if(pilha->inicio == pilha->fim){
              pilha->inicio = NULL;
              pilha->fim = NULL;
          }else{
              pilha->inicio = pilha->inicio->prox;
          }
          pilha->tamanho--;
          aux->prox = NULL;
      }
      return aux;
  }
  */
