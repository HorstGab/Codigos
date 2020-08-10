#include "mainwindow.h"
#include "model/modelmedico.h"
#include "model/modelarvore.h"
#include "model/modelarquivo.h"
#include "model/modelfila.h"

/**
 * @brief mainWindow
 */
void mainWindow(){
    int opcao;

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
           "| |                          <1> Inserir Medico                     | |\n\t\t\t\t"
           "| |                                                                 | |\n\t\t\t\t"
           "| |                          <2> Alterar Medico                     | |\n\t\t\t\t"
           "| |                                                                 | |\n\t\t\t\t"
           "| |                          <3> Buscar Medico                      | |\n\t\t\t\t"
           "| |                                                                 | |\n\t\t\t\t"
           "| |                          <4> Remover Medico                     | |\n\t\t\t\t"
           "| |                                                                 | |\n\t\t\t\t"
           "| |                          <5> Imprimir Cadastro                  | |\n\t\t\t\t"
           "| |                                                                 | |\n\t\t\t\t"
           "| |                          <6> Imprimir Arvore B                  | |\n\t\t\t\t"
           "| |                                                                 | |\n\t\t\t\t"
           "| |                          <7> Carregar Arquivo                   | |\n\t\t\t\t"
           "| |                                                                 | |\n\t\t\t\t"
           "| |                          <8> Sair                               | |\n\t\t\t\t"
           "| |                                                                 | |\n\t\t\t\t"
           "| |                                                                 | |\n\t\t\t\t"
           "| |_________________________________________________________________| |\n\t\t\t\t"
           "|_____________________________________________________________________|\n\n\t\t\t\t"
           "                              <Opcao> ");

    scanf("%d", &opcao);
    printf("\n");

    if(opcao == 1) viewInserir();
//    if(opcao == 2) viewAlterar();
    if(opcao == 3) viewBusca();
//    if(opcao == 4) viewRemover();
//    if(opcao == 5) viewCadastro();
//    if(opcao == 6) viewArvore(x);
//    if(opcao == 7) viewCarregar();
//    if(opcao == 8){
//        viewConfirma();
//        return;
//    }
}

/**
 * @brief viewInserir
 */
void viewInserir(){


    system("cls");
    printf("\n\t\t\t\t");
    printf(" ____________________________________________________________________\n\t\t\t\t"
           "|  ________________________________________________________________  |\n\t\t\t\t"
           "| |                                                                | |\n\t\t\t\t"
           "| |                           ___________                          | |\n\t\t\t\t"
           "| |                          |           |                         | |\n\t\t\t\t"
           "| |                          |  Inserir  |                         | |\n\t\t\t\t"
           "| |                          |___________|                         | |\n\t\t\t\t"
           "| |                                                                | |\n\t\t\t\t"
           "| |                      (*): Campo Obrigatorio.                   | |\n\t\t\t\t"
           "| |________________________________________________________________| |\n\t\t\t\t"
           "|____________________________________________________________________|\n\n\t\t\t\t\t");


//    printf(" Codigo(*): ");
//    scanf("%d", &reg->codigo);
//    fflush(stdin);
//    printf("\t\t\t\t\t Nome(*): ");
//    scanf("%s", reg->nome);
//    fflush(stdin);
//    printf("\t\t\t\t\t Sexo(*): ");
//    scanf("%c", &reg->sexo);
//    fflush(stdin);
//    printf("\t\t\t\t\t CPF(*): ");
//    getc(stdin);
//    fflush(stdin);
//    printf("\t\t\t\t\t CRM(*): ");
//    getc(stdin);
//    fflush(stdin);
//    printf("\t\t\t\t\t Especialidade: ");
//    getc(stdin);
//    fflush(stdin);
//    printf("\t\t\t\t\t RG(*): ");
//    getc(stdin);
//    fflush(stdin);
//    printf("\t\t\t\t\t Telefone: ");
//    getc(stdin);
//    fflush(stdin);
//    printf("\t\t\t\t\t Celular: ");
//    getc(stdin);
//    fflush(stdin);
//    printf("\t\t\t\t\t E-mail: ");
//    getc(stdin);
//    fflush(stdin);
//    printf("\t\t\t\t\t Endereco: ");
//    getc(stdin);
//    fflush(stdin);
//    printf("\t\t\t\t\t Data de Nascimento(*): ");
//    getc(stdin);
//    fflush(stdin);

    printf("\n\t\t\t\t");
    printf(" ____________________________________________________________________\n\t\t\t\t"
           "|                                                                    |\n\t\t\t\t"
           "|____________________________________________________________________|\n\t\t\t\t");

    getc(stdin);

}

/**
 * @brief viewAlterar
 */
void viewAlterar(){

    system("cls");
    printf("\n\t\t\t\t");
    printf(" ____________________________________________________________________\n\t\t\t\t"
           "|  ________________________________________________________________  |\n\t\t\t\t"
           "| |                                                                | |\n\t\t\t\t"
           "| |                           ___________                          | |\n\t\t\t\t"
           "| |                          |           |                         | |\n\t\t\t\t"
           "| |                          |  Alterar  |                         | |\n\t\t\t\t"
           "| |                          |___________|                         | |\n\t\t\t\t"
           "| |                                                                | |\n\t\t\t\t"
           "| |________________________________________________________________| |\n\t\t\t\t"
           "|____________________________________________________________________|\n\n\t\t\t\t\t");

    printf("Telefone: \n\t\t\t\t\t");
    printf("Celular: \n\t\t\t\t\t");
    printf("E-mail: \n\t\t\t\t\t");
    printf("Endereco: \n\t\t\t\t\t");

    printf("\n\t\t\t\t");
    printf(" ____________________________________________________________________\n\t\t\t\t"
           "|                                                                    |\n\t\t\t\t"
           "|____________________________________________________________________|\n\t\t\t\t");

}

/**
 * @brief viewBusca
 */
void viewBusca(){

    system("cls");
    printf("\n\t\t\t\t");
    printf(" ____________________________________________________________________\n\t\t\t\t"
           "|  ________________________________________________________________  |\n\t\t\t\t"
           "| |                                                                | |\n\t\t\t\t"
           "| |                           ___________                          | |\n\t\t\t\t"
           "| |                          |           |                         | |\n\t\t\t\t"
           "| |                          |  Buscar   |                         | |\n\t\t\t\t"
           "| |                          |___________|                         | |\n\t\t\t\t"
           "| |                                                                | |\n\t\t\t\t"
           "| |________________________________________________________________| |\n\t\t\t\t"
           "|____________________________________________________________________|\n\n\t\t\t\t\t");

    printf("Codigo: \n\t\t\t\t\t");
    printf("Nome: \n\t\t\t\t\t");
    printf("Sexo: \n\t\t\t\t\t");
    printf("CPF: \n\t\t\t\t\t");
    printf("CRM: \n\t\t\t\t\t");
    printf("Especialidade: \n\t\t\t\t\t");
    printf("RG: \n\t\t\t\t\t");
    printf("Telefone: \n\t\t\t\t\t");
    printf("Celular: \n\t\t\t\t\t");
    printf("E-mail: \n\t\t\t\t\t");
    printf("Endereco: \n\t\t\t\t\t");
    printf("Data de Nascimento: \n\t\t\t\t\t");


    printf("\n\t\t\t\t");
    printf(" ____________________________________________________________________\n\t\t\t\t"
           "|                                                                    |\n\t\t\t\t"
           "|____________________________________________________________________|\n\t\t\t\t");
}

/**
 * @brief viewRemover
 */
void viewRemover(){

    system("cls");
    printf("\n\t\t\t\t");
    printf(" ____________________________________________________________________\n\t\t\t\t"
           "|  ________________________________________________________________  |\n\t\t\t\t"
           "| |                                                                | |\n\t\t\t\t"
           "| |                           ___________                          | |\n\t\t\t\t"
           "| |                          |           |                         | |\n\t\t\t\t"
           "| |                          |  Remover  |                         | |\n\t\t\t\t"
           "| |                          |___________|                         | |\n\t\t\t\t"
           "| |                                                                | |\n\t\t\t\t"
           "| |________________________________________________________________| |\n\t\t\t\t"
           "|____________________________________________________________________|\n\n\t\t\t\t\t");

    printf("Codigo: \n\t\t\t\t\t");
    printf("Nome: \n\t\t\t\t\t");
    printf("Sexo: \n\t\t\t\t\t");
    printf("CPF: \n\t\t\t\t\t");
    printf("CRM: \n\t\t\t\t\t");
    printf("Especialidade: \n\t\t\t\t\t");
    printf("RG: \n\t\t\t\t\t");
    printf("Telefone: \n\t\t\t\t\t");
    printf("Celular: \n\t\t\t\t\t");
    printf("E-mail: \n\t\t\t\t\t");
    printf("Endereco: \n\t\t\t\t\t");
    printf("Data de Nascimento: \n\t\t\t\t\t");

    printf("\n\t\t\t\t");
    printf(" ____________________________________________________________________\n\t\t\t\t"
           "|                                                                    |\n\t\t\t\t"
           "|____________________________________________________________________|\n\t\t\t\t");

    system("pause");
    viewConfirma();

}
/**
 * @brief viewConfirma
 * @return
 */
int viewConfirma(){
    int opcao;

//    system("cls");
    printf("\n\t\t\t\t");
    printf(" ____________________________________________________________________\n\t\t\t\t"
           "|                                                                    |\n\t\t\t\t"
           "|                          Confirma?                                 |\n\t\t\t\t"
           "|                       <1>sim   <2>nao                              |\n\t\t\t\t"
           "|____________________________________________________________________|\n\t\t\t\t"
           "                            <Opcao> ");

    scanf("%d", &opcao);
    printf("\n");

    if(opcao == 1) return 1;
    else return 0;
}

/**
 * @brief viewArvore
 * @param bd
 * @return nenhum
 * @pre nenhum
 * @post arvore mostrada no terminal
 */
void viewArvore(FILE* bd){
    // lê cabeçalho e raiz da árvore
    Header *header = lerHeader(bd);
    arvoreB *raiz= lerNode(bd, header->raiz);

    // cria fila
    Fila *q = cria_fila();
    int Count;

    // coloca raiz na fila
    enqueue(q, raiz);

    // enquanto não se acabarem os nós
    Count = q->qnt;
    while (Count) {
       // printa os nós do nível atual na saida padrão
        while (Count > 0) {
            FNode *qNode = dequeue(q);
            arvoreB *Node = (arvoreB*) qNode->info;

            //imprime no
            printNo(Node);
            printf(" ");

            int i;
            // puxa os seus filhos para a fila
            for (i = 0; i <= Node->numChaves; ++i) {
                if (Node->filho[i] != -1)
                    enqueue(q, lerNode(bd, Node->filho[i]));
            }
            //decrementa o contador
            Count--;

            //libera os nos
            free(qNode);
            free(Node);
        }
        printf("\n");
        Count = q->qnt;
    }
    //libera e deleta a fila
    free(raiz);
    deletaFila(q);

}



