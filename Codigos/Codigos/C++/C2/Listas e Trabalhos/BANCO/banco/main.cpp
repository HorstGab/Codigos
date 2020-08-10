
#include "conta.h"
#include "movimentacao.h"
#include "banco.h"

int main(){

    banco* b = new banco();

    b->criar_conta(1, 100, 1000, 500, especial);
    return 0;
}
