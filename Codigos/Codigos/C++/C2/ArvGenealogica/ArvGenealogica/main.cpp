#include "pessoa.h"

int main()
{

    Pessoa *avom1 = new Pessoa("Rosalia");
    Pessoa *avom2 = new Pessoa("Rolasinda");
    Pessoa *avoh1 = new Pessoa("Antonio");
    Pessoa *avoh2 = new Pessoa("Pedro");

    Pessoa *pai = new Pessoa("Aloisio", avoh1, avom1);
    Pessoa *mae = new Pessoa("iraci", avoh2, avom2);

    Pessoa *eu = new Pessoa ("Gabriel", pai, mae);
    Pessoa *irmao = new Pessoa ("Jonas", pai, mae);

    eu->mostrar("eu: ");
    irmao->mostrar("irmao: ");

    cout << "EQUALS: " << eu->equals(avoh1) << endl;
    return 0;
}

