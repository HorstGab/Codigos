#include"estado.h"
#include"transicao.h"
#include"arquivo.h"
#include"maquinaturing.h"
#include<string.h>

int main(int argc, char const* argv[]){
    char palavra[MAX] = {0};
    Arquivo *mtLeitor = NULL;
    maquinaTuring *mt = NULL;
    char op = 0;
    bool saida = false;

    system("cls");
    printf("%s / %s\n", argv[0], argv[1]);
    if(argc > 1){
        mtLeitor = new Arquivo(argv[1]);

       mt = mtLeitor->inicializarMaquina();
        system("pause");
    }else{
        cerr << "Arquivo de entrada não encontrado" << endl;
        system("pause");
    }

    if(!mt) return 1;

    while(saida != true){
        system("cls");
        cout << "       ~~ MAQUINA DE TURING COM FITA LIMITADA ~~" << endl;
        cout << "              < 1 > Testar a Gramatica" << endl;
        cout << "              < 2 > Sair" << endl;

        cout << "Digite a opcao: " ;
        cin >> op;

        if(op == '1'){
            cout << "              Entre com a palavra: " << endl;
            fflush(stdin);
            scanf("%[^\n]%*c", palavra);

            char str[MAX];

            strcpy(str, "*");
            strcat(str, palavra);
            strcat(str, "$" );

            string sequencia = string(str);
            mt->testaSequencia(&sequencia);
        }else if(op == '2'){
            cout << "Saindo do Programa!" << endl;
            saida = true;
        }else
            cout << "Comando " << op << " inexistente" << endl;
        fflush(stdin);
        getchar();
    }

    delete mtLeitor;

}
