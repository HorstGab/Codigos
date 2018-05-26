#ifndef PILHA_H
#define PILHA_H

#include <iostream>

using namespace std;


template < class T>
class Pilha{
protected:
    Lista <T>* pilha;
public:
    Pilha(){
        this->pilha = new Lista <T> ();
    }

    T pop(){//remove

    }
    T topo();//retorna
    void push(const T& t){
        this->pilha->insere_inicio(t);
    }

    bool isEmpty();
    ~Pilha();

};


#endif // PILHA_H
