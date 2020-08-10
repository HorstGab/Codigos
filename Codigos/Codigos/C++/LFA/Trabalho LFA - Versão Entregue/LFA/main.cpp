#include <iostream>

#include"automatos.h"
#include"arquivo.h"

using namespace std;

#define MAX 256

int main(int argc, char const* argv[])
{
    Automatos *automato = new Automatos();
    char palavra[MAX] = {0};
    char op = 0;
    bool saida = false;

    if(argc > 1)
        Arquivo::inicializarAutomato(automato, argv[1]);

    while(saida != true){
        system("cls");
        cout << "Testar a Gramatica -> 1" << endl;
        cout << "Printar a Gramatica -> 2" << endl;
        cout << "Exit -> 3" << endl;

        cout << "Digite a opcao: " ;
        cin >> op;

        if(op == '1'){
            cout << "Entre com a palavra ... " << endl;
            cin >> palavra;
            fflush(stdin);
            automato->testaSequencia((char*)palavra);
        }else if(op == '2'){
            automato->imprimir();
        }else if(op == '3'){
            cout << "Saindo do Programa!" << endl;
            saida = true;
        }else
            cout << "Comando " << op << " inexistente" << endl;
        fflush(stdin);
        getchar();
    }

    return 0;
}

