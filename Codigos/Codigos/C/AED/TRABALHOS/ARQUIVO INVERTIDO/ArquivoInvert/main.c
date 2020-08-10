#include "arvoreb.h"
#include "fila.h"
#include <ctype.h>
#include "basedados.h"
#include "arquivoinvertido.h"


int main(int argc, char **argv)
{

    FILE *arqBTree = NULL, *arqRegistro = NULL;
    StopWords* stopWordVetor = NULL;
    Queue* dados = createQueue();
    ///fila com os diretorios do arquivos txt
    Queue* diretorioQueue = createQueue();
    baseDados** dadosVetor = NULL;
    int numArquivos;

    stopWordVetor = readStopWords(argv);
    dados = readDadosToFile(readBaseDados(argv, diretorioQueue));
    dadosVetor = matrizToTokens(dados, &numArquivos);
    dadosVetor = DadosUpdate(dadosVetor, stopWordVetor, numArquivos);
    addWordsToFile(arqBTree, arqRegistro, dadosVetor, numArquivos);


    int opcao;

    while(1){
        system("cls");
        printf("\n\n\n\t\t\t\t");
        printf(" _____________________________________________________________________\n\t\t\t\t"
               "|  _________________________________________________________________  |\n\t\t\t\t"
               "| |                                                                 | |\n\t\t\t\t"
               "| |                                                                 | |\n\t\t\t\t"
               "| |                     _______________________                     | |\n\t\t\t\t"
               "| |                    |                       |                    | |\n\t\t\t\t"
               "| |                    | ~~~~  BEM-VINDO  ~~~~ |                    | |\n\t\t\t\t"
               "| |                    |_______________________|                    | |\n\t\t\t\t"
               "| |                                                                 | |\n\t\t\t\t"
               "| |                                                                 | |\n\t\t\t\t"
               "| |                       ~ MENU PRINCIPAL ~                        | |\n\t\t\t\t"
               "| |                                                                 | |\n\t\t\t\t"
               "| |                          <1> Imprimir StopWords                 | |\n\t\t\t\t"
               "| |                                                                 | |\n\t\t\t\t"
               "| |                          <2> Imprimir Indices                   | |\n\t\t\t\t"
               "| |                                                                 | |\n\t\t\t\t"
               "| |                          <3> Consultar                          | |\n\t\t\t\t"
               "| |                                                                 | |\n\t\t\t\t"
               "| |                          <4> Sair                               | |\n\t\t\t\t"
               "| |                                                                 | |\n\t\t\t\t"
               "| |                                                                 | |\n\t\t\t\t"
               "| |_________________________________________________________________| |\n\t\t\t\t"
               "|_____________________________________________________________________|\n\n\t\t\t\t"
               "                              <Opcao> ");

        scanf("%d", &opcao);
        printf("\n");

        switch (opcao) {
        case 1:
            printfStopWords(stopWordVetor);
            break;
        case 2:
            printArquivoInverso();
            break;
        case 3:
            pesquisaregistro(dadosVetor, numArquivos);
            break;
        case 4:
            return 0;
        default:
            break;
        }

        system("PAUSE");
    }
    return 0;
}



