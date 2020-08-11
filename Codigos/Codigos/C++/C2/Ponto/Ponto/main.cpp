#include <iostream>

using namespace std;

#include "ponto.h"

int main()
{
    Ponto *p = new Ponto (10, 20);

    p->show();

    p->setx(40); // alterou o estado incial de x

    p->show(); // imprimindo novamente para mostrar o valor de x alterado

    delete p;
    return 0;
}

// encapsula os dados para protege-los, dizendo o que pode ou não ser feito com esse objeto
 /* ENCAPSULAMENTO
  * encapsulamento constitui-se no 'coração' da programação orientada a objetos;.
  * Especificadores de acesso, mais conhecidos:
  * "private" : Membros Privados :  acessíveis apenas pelos membros da própria classe.
  * "public" : Membors Públicos : liberado para todos.
  * "protected" : Membros Protegidos : acessíveis pelos membros da própria classe e classes derivadas. Quando esquecemos de informar o especificador, por padrão os membros seão protegidos.
  * HERANÇA:
  * definição de uma hierarquia de classes :: uma " ÁRVORE " de classes, onde cada uma posui 0 ou mais subclasses.
  * nesse sistema, quando mais a baixo a classe está, mais especializada e específica ela será.
  * exercicio funcionario.h < - classe funcionario é subclasse
  */



