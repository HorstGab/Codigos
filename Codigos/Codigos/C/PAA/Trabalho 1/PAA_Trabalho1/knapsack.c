#include <knapsack.h>

//Faz busca por profundidade de todas as possibilidades possiveis
//Entrada: peso e o valor atual, os dois conjuntos de soluções,
//a quantidade de objetos e a capacidade da mochila
//Retorno: nenhum
//Pré-Condições: nenhuma
//Pós-Condições: conjunto solução de objetos escolhidos
void dfs(int pesoAtual, int valorAtual, int x[], int solucao[], int tam, int W){

    int i;

    //se o valor atual for maior que o valor maximo
    //ele se tornara o novo maior valor
    //e o conjunto solucao recebera novos valores
    if(valorAtual > valorMaximo){
        valorMaximo = valorAtual;
        for( i = 0; i < tamanho; i++){
            solucao[i] = x[i];
        }
    }

    //se ainda possuir comparacoes possiveis
    if(tam > 0){
        // se o peso atual mais o peso da posicao atual for menor que a capacidade
        if(pesoAtual + peso[tam] <= W){
            //essa posicao fara parte do conjunto solucao
            x[tam] = 1;
            //analisa as outras possibilidades recursivamente
            dfs((pesoAtual+=peso[tam]), (valorAtual+=valor[tam]), x, solucao, tam - 1, W);
            //desfaz as operacoes para possibilitar a comparacao as outras possibilidades
            pesoAtual-=peso[tam], valorAtual-=valor[tam];
            x[tam] = 0;
        }
        //avanca na comparacao sem o objeto
        dfs(pesoAtual,valorAtual, x, solucao, tam-1, W);
    }
}

//Faz as operações do problema da mochila por backtracking
//Entrada: capacidade da mochila e os dois vetores de solução
//Retorno: valor maximo
//Pré-Condições: nenhuma
//Pós-Condições: conjunto solução de objetos escolhidos
int knapSackBacktracking(int W, int x[], int solucao[]){
    int pesoAtual = 0, valorAtual = 0;
    valorMaximo = 0;
    int i;

    //inicializa os vetores solucao com 0
    for(i = 0; i < tamanho; i++) x[i] = solucao[i] = 0;
    dfs(pesoAtual, valorAtual, x, solucao, tamanho -  1, W);

    //retorna a maior valor
    return valorMaximo;
}

//Faz as operações do problema da mochila por programação dinamica
//Entrada: capacidade da mochila e o vetor de solução
//Retorno: valor maximo
//Pré-Condições: nenhuma
//Pós-Condições: conjunto solução de objetos escolhidos
int knapSackPD (int w, int x[]){
    int i, j;
    int a, b;
    int **K = (int**)malloc((tamanho+1)*sizeof(int*));

    for(i = 0; i < tamanho+1; i++){
        K[i] = (int*)malloc((w+1)*sizeof(int));
    }

    //inicia a primeira linha com 0
    for(a = 0; a <= w; a++) {
        K[0][a] = 0;
    }

    //inicia a primeira coluna com 0
    for(b = 0; b <= tamanho; b++) {
        K[b][0] = 0;
    }

    //opera e compara sobre a matriz calculando as possibilidades de solucao
    for (i = 1; i <= tamanho; i++){
        for(j = 1; j <= w; j++){
            // compara o peso com a capacidade da mochila e o valor com o valor da posicao anterior
            if((peso[i-1] <= j) && (valor[i-1]+K[i-1][j-peso[i-1]] > K[i-1][j])){
                K[i][j] = valor[i-1] + K[i-1][j-peso[i-1]];
            }else{
                K[i][j] = K[i-1][j];
            }
        }
    }
    //inicializa o conjunto solucao com 0
    for(i = 0; i < tamanho; i++) x[i] = 0;

    i = tamanho;
    j = w;
    //enquanto n for posicao vazia na matriz
    while(K[i][j] != 0){
        //se a posicao for igual a posicao anterior continua
        if(K[i][j] == K[i-1][j]){
            i--;
        }else{
            //senao a posicao anterior fara parte do conjunto solucao
            x[i-1] = 1;
            j -= peso[i-1];
            i--;
        }
    }

    //retorna a ultima posicao da matriz que é o maior valor
    return K[tamanho][w];
}


//Faz leitura de arquivo
//Faz alocação de memória nos respectivos vetores
//Entrada: nenhum
//Retorno: nenhum
//Pré-Condições: nenhuma
//Pós-Condições: dados lidos e salvos na memoria
void loadData(){
    char nome[30];
    int *matrizAux;
    int str;
    int i;

    FILE *f;
    printf("Digite o nome do arquivo: ");
    scanf("%[^\n]%*c", &nome);
    tamanho = 10;

    //abre o arquivo para leitura
    if ((f = fopen(nome, "r")) == NULL){
        printf("Erro ao Abrir o Arquivo\n");
        system("pause");
    }else{
        //vetor dinamico
        matrizAux = (int*)malloc(tamanho*sizeof(int));
        for(i = 0; !feof(f); i++){
            //se atingir o tamanho realoca com o dobro
            if(i + 1 > tamanho){
                tamanho *= 2;
                matrizAux = (int*)realloc (matrizAux, tamanho*sizeof(int));
            }
            fscanf(f, "%d", &str);
            matrizAux[i] = str;
        }
        //realoca com o tamanho final de iteracoes
        tamanho = i;
        matrizAux = (int*)realloc(matrizAux, tamanho*sizeof(int));
    }

    //cada vetor é alocado com o tamanho da coluna da matriz
    tamanho /= 2;
    valor = (int*)malloc(tamanho*sizeof(int));
    peso = (int*)malloc(tamanho*sizeof(int));

    if(valor == NULL || peso == NULL) return;

    //separa os vetores concatenados
    for(i = 0; i < tamanho; i++){
        valor[i] = matrizAux[2*i];
        peso[i] = matrizAux[2*i+1];
    }

    printf("%d\n", tamanho);

    free (matrizAux);
}

//Imprime os objetos que fazem parte do conjunto solução
//Entrada: vetor solução
//Retorno: nenhum
//Pré-Condições: nenhuma
//Pós-Condições: nenhuma
void imprimirSolucao(int x[]){
    int i;
    printf("Conjunto solucao\n");
    for(i = 0; i < tamanho; i++){
        //se o objeto pertencer ao conjunto solucao
        if(x[i] == 1){
            //printa na tela o peso e o valor
            printf("peso = %d - ", peso[i]);
            printf("valor = %d\n", valor[i]);
        }
     }
}

//Escolha de qual tipo de algoritmo para resolução do problema utilizar
//Entrada: capacidade da mochila
//Retorno: nenhum
//Pré-Condições: nenhuma
//Pós-Condições: nenhuma
void submenu(int W){
    clock_t start, end;
    int esc, aux = 0;
    int x[tamanho+1];
    int solucao[tamanho];
    system("cls");

    printf(" -------------------------------------\n");
    printf("|        Escolha uma opcao            | \n");
    printf("|                                     | \n");
    printf("|   0 - Tela inicial                  | \n");
    printf("|   1 - Knapsack por Prog. Dinamica   | \n");
    printf("|   2 - Knapsack por BackTracking     | \n");
    printf("|                                     | \n");
    printf(" -------------------------------------\n");

    scanf("%d", &esc);
    while(esc){
        switch(esc){
            case 1:
                //calcula o tempo de execucao
                start = clock();
                aux = knapSackPD(W, x);
                end = clock();
                printf("Tempo:%lf\n",((double)(end - start)) / CLOCKS_PER_SEC);
                //imprime a solucao
                printf("Valor Maximo: %d\n", aux);
                imprimirSolucao(x);
                system("pause");
                break;
            case 2:
                //calcula o tempo de execucao
                start = clock();
                aux = knapSackBacktracking(W,x, solucao);
                end = clock();
                printf("Tempo:%lf\n",((double)(end - start)) / CLOCKS_PER_SEC);
                //imprime a solucao
                printf("Valor Maximo: %d\n", aux);
                imprimirSolucao(solucao);
                system("pause");
                break;
            case 0:
                return;
                break;
        }

        system("cls");
        printf(" -------------------------------------\n");
        printf("|        Escolha uma opcao            | \n");
        printf("|                                     | \n");
        printf("|   0 - Tela inicial                  | \n");
        printf("|   1 - Knapsack por Prog. Dinamica   | \n");
        printf("|   2 - Knapsack por BackTracking     | \n");
        printf("|                                     | \n");
        printf(" -------------------------------------\n");

        scanf("%d", &esc);
        fflush(stdin);
    }
}

