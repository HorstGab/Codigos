#include "lista.h"


int main(){   

    Lista *li = NULL;

    cout << "CRIANDO LISTA ..." << endl;

    Lista::insere_Fim(li,1);
    Lista::insere_Fim(li,3);
    Lista::insere_Fim(li,5);
    Lista::insere_Fim(li,7);
    Lista::insere_Fim(li,9);

    Lista::imprime(li);

    li->~Lista();
    cout << "Destruindo Lista" << endl;
    return 0;
}

