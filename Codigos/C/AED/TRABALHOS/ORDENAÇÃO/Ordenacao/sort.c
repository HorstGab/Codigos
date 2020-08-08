#include "sort.h"

/**
 * @brief InsertionSort
 * @param vet
 * @param n
 * @pre nenhuma
 * @post vetor ordenado
 */
void InsertionSort(int *vet, int n){
    int i, j, x;

    //percorre o vetor
    for(i = 1; i < n; i++){
        //x recebe a posicao
        x = vet[i];
        //j recebe uma posicao anterior e testa enquanto for maior que zero e a posicao maior q x
        for(j = i - 1; j >= 0 && vet[j] > x; j--){
            //troca
            vet[j+1] = vet[j];
        }
        //posicao j recebe valor x
        vet[j+1] = x;
    }
}

/**
 * @brief SelectionSort
 * @param vet
 * @param n
 * @pre nenhuma
 * @post vetor ordenado
 */
void SelectionSort(int *vet, int n){
    int i, j, min, x;

    //percorre o vetor
    for(i = 0; i < n-1; i++){
        min = i;
        //percorre o vetor com um indice a frente do anterior
        for(j = i+1; j < n; j++){
            //compara o valor
            if(vet[j] < vet[min]){
                //minimo recbe o valor atual
                min = j;
            }
        }
        //troca
        x = vet[i];
        vet[i] = vet[min];
        vet[min] = x;
    }
}

/**
 * @brief QuickSort
 * @param vet
 * @param e
 * @param d
 * @pre nenhuma
 * @post vetor ordenado
 */
void QuickSort(int *vet, int e, int d) {

      int i = e, j = d;
      int tmp;
      int pivot = vet[(e + d) / 2];

      //enquanto esquerda menor q direita
      while (i <= j) {
          //enquanto a esquerda q o pivo incrementa
          while (vet[i] < pivot)
              i++;
          //enquanto a direita maoir que o pivo decrementa
          while (vet[j] > pivot)
              j--;
          //se esquerda for menor ou igual a direita
          if (i <= j) {
              //troca
              tmp = vet[i];
              vet[i] = vet[j];
              vet[j] = tmp;
              i++;
              j--;
          }
      };

      //se esquerda for menor q j
      if (e < j)
            QuickSort(vet, e, j);
      //se o i  for menor q a direita
      if (i < d)
            QuickSort(vet, i, d);
}


/**
 * @brief MergeSort
 * @param vet
 * @param e
 * @param d
 * @pre nenhuma
 * @post vetor ordenado
 */
void MergeSort(int *vet, int e, int d){
    //se a esquerda menor q a direira+1
    if( e < d-1){
        //pega o meio
        int m = (e+d)/2;
        MergeSort(vet, e, m);
        MergeSort(vet, m, d);
        intercala(vet, e, m, d);
    }
}

/**
 * @brief intercala
 * @param vet
 * @param e
 * @param m
 * @param d
 * @pre nenhuma
 * @post separa o vetor
 */
void intercala(int *vet,int e, int m, int d) {
    int i, j, k, *vet_aux;

    //aloca o auxiliar
    vet_aux = malloc((d-e)*sizeof(int));
    i = e;
    j = m;
    k = 0;
    //enquanto a esquerda for menor q a direita
    while(i < m && j < d){
        //se a posicao da esquerda for menor q o da direita
        if(vet[i] <= vet[j]){
            vet_aux[k++] = vet[i++];
        }else{
            vet_aux[k++] = vet[j++];
        }
    }
    //enquanto esquerda menor q o tamanho
    while(i < m){
        vet_aux[k++] = vet[i++];
    }
    //enquanto j menor q a direira
    while(j < d){
        vet_aux[k++] = vet[j++];
    }

    for(i = e; i < d; i++){
        vet[i] = vet_aux[i-e];
    }
    //libera o auxiliar
    free(vet_aux);
}

/**
 * @brief HeapSort
 * @param vet
 * @param n
 * @pre nenhuma
 * @post ordena o vetor
 */
void HeapSort(int *vet, int n){
    int m;

    //percorre o vetor
    for(m = 1; m < n; m++){
        insereHeap(vet, m);
    }
    //percorre o vetor ao contrario e troca
    for(m = n; m > 1; m--){
        int t = vet[1];
        vet[1] = vet[m];
        vet[m] = t;
        sacodeHeap(vet, m-1);
    }
}

/**
 * @brief insereHeap
 * @param vet
 * @param m
 * @pre nenhuma
 * @post vetor com uma posicao trocada
 */
void insereHeap(int *vet, int m){
    int f = (m + 1);

    //enquanto f for maior que 1 e a posicao da metade for menor q o vetor
    while((f > 1) && (vet[f/2] < vet[f])){
        //troca
        int t = vet[f/2];
        vet[f/2] = vet[f];
        vet[f] = t;

        //f recebe a metade
        f = f/2;
    }
}

/**
 * @brief sacodeHeap
 * @param vet
 * @param m
 * @pre nenhuma
 * @post
 */
void sacodeHeap(int *vet, int m){
    int t, f = 2;

    //enquanto f for menor que o tamanho do vetor
    while(f <= m){
        //se f for menor que o vetor e for ordenado incrementa f
        if(f < m && vet[f] < vet[f+1]) ++f;
        //se o meio do vetor for maior ou igaul a f
        if(vet[f/2] >= vet[f]) break;

        //troca
        t = vet[f/2];
        vet[f/2] = vet[f];
        vet[f] = t;

        //f dobra
        f *= 2;
    }
}

/**
 * @brief InsertionSortChar
 * @param vet, vetor que sera ordenado
 * @param tamanho, tamanho do vetor
 * Pre-condicao: nenhuma
 * Pos-condicao: vetor ordenado
 * Modo: Baseado na ideia de colocar cada elemento na posição
 * correta em relação aos seus antecessores
 */
void InsertionSortChar(char **vet, int tamanho)
{
    int i, j;
    char *aux;

    // loop para percorrer o vetor
    for(j = 1; j < tamanho; j++){
        aux = vet[j];

        for(i = j - 1; i >= 0; i--){

            // compara se vet[i] eh menor que aux
            if(strcasecmp(vet[i],aux) < 0){
                break;
            }

            vet[i+1] = vet[i];
        }
        // inserir o aux no lugar que ficou vago (posicao correta)
        vet[i+1] = aux;
    }
}

/**
 * @brief SelectionSortChar
 * @param vet, vetor que sera ordenado
 * @param tamanho, tamanho do vetor
 * Pre-condicao: nenhuma
 * Pos-condicao: vetor ordenado
 * Modo: Baseado na ideia de escolher o menor elemento do vetor,
 * depois o segundo menor, e assim por diante.
 */
void SelectionSortChar(char **vet, int tamanho)
{
    int i, j, menor;
    char *aux;

    // loop para percorrer o vetor
    // Por isso (-1), eh o tamanho do vetor - a primeira posicao que ja eh o menor valor
    for(i = 0; i < tamanho-1; i++){

        // atribuo a variavel menor a primeira posicao do vetor
        menor = i;

        // loop para procurar menor elemento em relacao a "i"
        for(j = i+1; j < tamanho; j++)

            // se quem está vet[j] for menor que o vet[menor]
            if(strcasecmp(vet[j], vet[menor]) < 0)

                // atualizar quem eh o menor
                menor = j;

        aux = vet[i];
        vet[i] = vet[menor];
        vet[menor] = aux;
    }
}


/**
 * @brief MergeChar
 * @param vet, vetor que sera ordenado
 * @param inicio, inicio do vetor
 * @param meio, meio do vetor
 * @param fim, final do vetor
 */
void MergeChar(char **vet, int inicio, int meio, int fim)
{
    int esq, m, k = 0;
    char **aux;

    //aloca o auxili
    aux = (char**)malloc((fim-inicio)*sizeof(char*));
    esq = inicio;
    m = meio;

    //enquanto esquerda for menor que o meio e o meio menor que o fim
    while(esq < meio && m < fim){

        // comparar se vet[esq] eh menor ou igual a vet[m]
        if(strcmp(vet[esq],vet[m]) <= 0)
            aux[k++] = vet[esq++];
        else
            aux[k++]=vet[m++];
    }

    //enquanto esquerda for menor que o meio
    while(esq < meio) aux[k++] = vet[esq++];
    //enquanto o meio for menor que
    while(m < fim) aux[k++] =vet[m++];

    for(esq = inicio; esq < fim; esq++){
        vet[esq] = aux[esq-inicio];
    }

    //libera o auxiliar
    free(aux);
}

/**
 * @brief MergeSortChar
 * @param vet, vetor que serÃ¡ ordenado
 * @param inicio, inÃ­cio do vetor
 * @param fim, final do vetor
 * Pre-condicao: funcao auxiliar MergeChar();
 * Pos-condicao: vetor ordenado
 * Baseado na ideia de ordenar cada metade do vetor separadamente e depois fazer
 * a intercalação dos subvetores ordenados para obter o vetor totalmente ordenado.
 */
void MergeSortChar(char **vet, int inicio, int fim)
{
    //se inicio for menor que o final
    if(inicio < fim - 1){
        //pega o meio do vetor
        int meio = (inicio + fim)/2;

        MergeSortChar(vet, inicio, meio);
        MergeSortChar(vet, meio, fim);
        MergeChar(vet, inicio, meio, fim);
    }
}

/**
 * @brief sacodeHeap
 * @param vet, vetor a ser ordenado
 * @param tamanho, tamanho do vetor
 */
void sacodeHeapChar(char **vet, int tamanho)
{
    int f = 2;
    char *aux;

    // enquanto f for menor ou igual ao tamanho
    while( f <= tamanho){

        // compara se vet[f] eh menor que vet[f+1] e se for:
        if(f < tamanho && strcasecmp(vet[f], vet[f+1]) < 0)

            // acrescenta 1 a f
            ++f;

        // compara se vet[f/2] eh maior e igual a vet[f]
        if(strcasecmp(vet[f/2],vet[f]) >= 0) break;

        // se nao for: fazer a troca
        aux = vet[f/2];
        vet[f/2] = vet[f];
        vet[f] = aux;

        // atualiza o valor de f
        f *= 2;
    }
}

/**
 * @brief inserirHeapSortChar
 * @param vet, vetor a ser ordenado
 * @param tamanho, tamanho do vetor
 */
void inserirHeapSortChar(char **vet, int tamanho){
    int f = tamanho + 1;

    // se f for maior que 1 e o vet[f/2] for menor que o vet[f]
    while(f > 1 && strcasecmp(vet[f/2], vet[f]) < 0){

        // cria-se uma variavel para trocar
        char *temp = vet[f/2];
        vet[f/2] = vet[f];
        vet[f] = temp;

        // atualiza o valor de f
        f = f/2;
    }
}

/**
 * @brief HeapSortChar
 * @param vet, vetor a ser ordenado
 * @param tamanho, tamanho do vetor
 * Pre-condicao: funcoes auxiliares inserirHeapSortChar(); e sacodeHeap();
 * Pos-condicao: vetor ordenado
 * Baseado na construcao de um heap e sucessivas trocas
 * com o elemento da primeira posicao
 */
void HeapSortChar(char **vet, int tamanho){
    int i;

    // loop para percorrer o vetor e fazer a insercao
    for(i = 1; i < tamanho; i++){
        inserirHeapSortChar(vet, i);
    }

    // loop que percorre o vetor do fim ao inicio
    for(i = tamanho; i > 1; i--){

        // trocar
        char *aux = vet[1];
        vet[1] = vet[i];
        vet[i] = aux;

        sacodeHeapChar(vet, i-1);
    }
}

/**
 * @brief QuickSortChar
 * @param vet, vetor que sera ordenado
 * @param inicio, ini­cio do vetor
 * @param fim, final do vetor
 * Pre-condicao: nenhuma
 * Pos-condicao: vetor ordenado
 * Baseado na ideia de escolher um elemento x do vetor, denominado pivo, e separar os
 * demais em duas partes: os menores ou iguais a x e os maiores que x.
 */
void QuickSortChar(char **vet, int inicio, int fim) {

    int esq = inicio, dir = fim;
    char *tmp;
    char *pivot = vet[(inicio + fim) / 2];

    //enquanto esquerda for menor ou igual a direira
    while (esq <= dir) {

        // compara se vet[esq] eh menor que o pivo e incrementa um
        while (strcasecmp(vet[esq], pivot) < 0)
            esq++;

        // compara se vet[dir] eh maior que o pivo e decrementa um
        while (strcasecmp(vet[dir], pivot )> 0)
            dir--;

        // se inicio for menor ou igual ao fim, troca:
        if (esq <= dir) {
            tmp = vet[esq];
            vet[esq] = vet[dir];
            vet[dir] = tmp;
            esq++;
            dir--;
        }
    };

    //se o inicio for menor q a direira
    if (inicio < dir)
        QuickSortChar(vet, inicio, dir);
    //se a esquerda for menor que o final
    if (esq < fim)
        QuickSortChar(vet, esq, fim);
}
