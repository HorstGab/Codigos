#include "lista_p.h"

int main()
{

    Lista* li = lista();
    cout << "Criando Lista ..." << endl;

    li = insere_Final(li,1);
    li = insere_Final(li,3);
    li = insere_Final(li, 5);
    li = insere_Final(li, 7);
    li = insere_Final(li,9);

    imprime(li);

    freeLista(li);
    return 0;
}

