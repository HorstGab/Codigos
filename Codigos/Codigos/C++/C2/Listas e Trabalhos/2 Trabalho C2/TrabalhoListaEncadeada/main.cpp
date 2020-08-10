#include "listasimples.h"

int main(){
    No *li = NULL;

    cout << "CRIANDO LISTA ..." << endl;

    No::num_elem(li);
    No::inserir_inicio(li,0);
    No::inserir_final(li,1);
    No::inserir_final(li,3);
    No::inserir_final(li,5);
    No::inserir_final(li,7);
    No::inserir_final(li,9);
    No::imprime(li);
    No::num_elem(li);

    No::remove_inicio(li);
    No::imprime(li);
    No::num_elem(li);

    No::remove_final(li);
    No::imprime(li);
    No::num_elem(li);

    No::return_no(li, 1);


    delete li;
    return 0;
}

