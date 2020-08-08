#include "main.h"


int main(int argc, char const *argv[]){

    int tam = 10;
    int *vet = NULL;
    Arg cmd = inicializar(cmd);

    cmd_main(argc, argv, &cmd);
    cmd_ordenacao(&vet, &tam, cmd);

    return 0;
}

void cmd_main(int argc, char const *argv[], Arg *cmd){


        //copia o argumento 2 para a struct
        strcpy(cmd->tipo, argv[1]);
        //se for N
        if(isN(cmd)){
            cmd->qnt = atoi(argv[2]);
            if(argv[3] && argv[4]){
                strcpy(cmd->ordem, argv[3]);
                strcpy(cmd->output, argv[4]);
            }else{
                printf("caso de testar todos os sort!\n");
            }
        }else{
            //ou se for C
            if(isC(cmd)){
                strcpy(cmd->input, argv[2]);
                if(argv[3] && argv[4]){
                    strcpy(cmd->ordem, argv[3]);
                    strcpy(cmd->output, argv[4]);
                }else{
                    printf("caso de testar todos os sort!\n");
                }
            }
        }
    mostrarCmd(*cmd);
}

void cmd_ordenacao(int **vet, int *tam, Arg cmd){

    if(isN(&cmd)){
        printf("N\n");
        *tam = cmd.qnt;
        num_rand(vet, *tam);
        ordem_sort(*vet, *tam, cmd.ordem);
        Wfile(*vet, *tam, cmd);
        //printf("escrito no arquivo\n");
        //mostrar(*vet, *tam);
    }else{
        if(isC(&cmd)){
            printf("C\n");
            lerVet(vet, tam, cmd);
            ordem_sort_Char(*vet, *tam, cmd.ordem);
            Wfile(*vet, *tam, cmd);
        }else{
            printf("Comando Invalido\n");
        }
    }
}

///
/// \brief mostrar
/// \param vet
/// \param n
///
void mostrar (int vet[], int tam){
    int i;

    //enquanto no for final do vetor
    for(i = 0; i < tam; i++){
        //mostra na tela o vetor
        printf("[%d]\n", vet[i]);
    }
}

///
/// \brief lerVet
/// \param vet
/// \param tam
///
void lerVet(int **vet, int *tam, Arg cmd){
    FILE* f;
    int i;

    //se o arquivo abrir
    if((f = fopen(cmd.input, "r+"))){
        //aloca o tamanho inicial do vetor
        (*vet) = (int*)malloc((*tam)*sizeof(int));

        //enquanto n for fim de arquivo
        for(i = 0; !feof(f) ; i++){
            //compara se i esta na ultima posicao
            if(i == *tam) {
                //dobra o tamanho
                (*tam) *= 2;
                //realoca o vetor com o novo tamanho
                (*vet) = (int*)realloc(*vet,(*tam)*sizeof(int));
            }

            //le o elemento do arquivo
            fscanf(f, "%d", &((*vet)[i]));
        }

        //tamanho recebe o numero de iteracoes
        (*tam) = i;
        //vetor realoca com o tamanho exato do vetor
        (*vet) = (int*)realloc(*vet,(*tam)*sizeof(int));

    //se n abrir
    }else{
        //mensagem de erro
        printf("erro ao abrir o arquivo!\n");
        printf("%s\n", strerror(errno));
    }
    printf("lido o vetor do arquivo\n");
    //fecha o arquivo
    fclose(f);
}

void num_rand(int **vet, int tam){
    int i;
    srand(time(NULL));

    //aloca o tamanho do vetor
    (*vet) = (int*)malloc((tam)*sizeof(int));
    //enquanto n for final do vetor
    for(i = 0; i < tam; i++){
        //posicao do vetor recebe um numero aleatorio
        (*vet)[i] = rand();
    }
}

void Wfile(int *vet, int tam, Arg cmd){
    FILE *f;
    int i;


    //se abrir o arquvo
    if((f = fopen(cmd.output, "w+"))){

        //enquanto nao for final do vetor
        for(i = 0; i < tam; i++){
            //escreve no arquivo
            fprintf(f, "vetor[%d] = %d\n", i, vet[i]);
            printf("vetor[%d] = %d\n", i, vet[i]);
        }

    //senao printa na tela uma mensagem de erro
    }else{
        printf("erro ao abrir o arquivo! \n");
        printf("%s\n", strerror(errno));

    }
    //fecha o arquivo
    fclose(f);
}

int isN (char tipo){
    if(!strcmp(tipo, "N") || !strcmp(tipo, "n")){
        return 1;
    }else{
        return 0;
    }
}

int isC(Arg *cmd){
    if(!strcmp(cmd->tipo, "C")||!strcmp(cmd->tipo, "c")){
        return 1;
    }else{
        return 0;
    }
}

void ordem_sort (int *vet, int tam, char* ordem){

    if(!strcmp(ordem, "insertionsort")) InsertionSort(vet, tam);
    if(!strcmp(ordem, "selectionsort")) SelectionSort(vet, tam);
    if(!strcmp(ordem, "quicksort")) QuickSort(vet,0,tam-1);
    if(!strcmp(ordem, "mergesort")) MergeSort(vet,0,tam);
    if(!strcmp(ordem, "heapsort")) HeapSort(vet, tam);
}

void mostrarCmd(Arg cmd){

    printf("Tipo: %s\n", cmd.tipo);
    printf("Qnt: %d\n", cmd.qnt);
    printf("Ordem: %s\n", cmd.ordem);
    printf("Input: %s\n", cmd.input);
    printf("Output: %s\n", cmd.output);
}

Arg inicializar(Arg cmd){

    cmd.tipo[0] = '\0';
    cmd.qnt = 0;
    cmd.ordem[0] = '\0';
    cmd.input[0] = '\0';
    cmd.output[0] = '\0';
    return cmd;
}

void stringQuickSort(char *vet[], int left, int right) {
    int j;
    if(left < right) {
        j = stringSeparate(vet, left, right);
        stringQuickSort(vet, left, j-1);
        stringQuickSort(vet, j+1, right);
    }
}

int stringSeparate(char *vet[], int left, int right) {
    int j, k;
    char *temp, *pivot;

    pivot = vet[right]; j = left;
    for(k = left; k < right; k++) {
        if(strcmp(vet[k], pivot) <= 0) {
            temp = vet[j]; vet[j] = vet[k]; vet[k] = temp;
            j++;
        }
    }

    vet[right] = vet[j]; vet[j] = pivot;
    return j;
}