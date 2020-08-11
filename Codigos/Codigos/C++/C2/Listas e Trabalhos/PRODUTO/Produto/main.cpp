#include <produto.h>
#include <quimico.h>
#include <usaproduto.h>

int main()
{

    string *nome = new string ("gasosa");
    UsaProduto *x  = new UsaProduto(125, nome, 3, 5.00);

    //mostra informacoes iniciais
    cout << *x->toString() << endl;

    //atualiza o produto em 15%
    x->atualizar(15);

    //mostra as informacoes do produto atualizado
    cout << *x->toString() << endl;

    //setar o produto como inflamavel
    x->setInflamavel(true);

    //mostra as informacoes do produto atualizado
    cout << *x->toString() << endl;


    delete x;

    return 0;
}

