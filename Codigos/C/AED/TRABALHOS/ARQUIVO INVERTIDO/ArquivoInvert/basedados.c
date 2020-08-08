#include "basedados.h"
#include <string.h>


///
/// le as stopwords do arquivo
/// \brief readStopWords
/// \param argv
/// \return estrutura com as stopwords
/// \pre nenhuma
/// \post stopwords lidos
///
StopWords* readStopWords(char **argv){

    FILE* stopWords = fopen(argv[2], "r+");
    StopWords*  vetAux = (StopWords*)malloc(sizeof(StopWords));
    int tam = 10;

    ///le as stopwprds
    vetAux->stopWords = readToVectorDynamic(stopWords, &tam);
    vetAux->count = tam;

    ///se for nulo printa uma mensagem de erro
    if(!vetAux){
        printf("%s\n", strerror(errno));
    }

    ///fecha o arquivo de stopwords
    fclose(stopWords);
    return vetAux;
}

///
/// printa as stop Words
/// \brief printfStopWords
/// \param stopWordVetor
/// \pre nenhuma
/// \post nenhuma
///
void printfStopWords(StopWords* stopWordVetor){

    int i;

    ///ordena o vetor
    QuickSortChar(stopWordVetor->stopWords, 0, stopWordVetor->count-1);
    ///percorre o vetor imprimindo as stopwords
    for(i = 0; i < stopWordVetor->count; i++){
        printf("<%s> \n", stopWordVetor->stopWords[i]);
    }

    printf("\n");
}

///
/// le os diretorio dos arquivos
/// \brief readBaseDados
/// \param argv
/// \param fila
/// \return fila contendo os diretorios
/// \pre nenhum
/// \post fila com os diretorios
///
Queue* readBaseDados(char **argv, Queue* fila){

    FILE* diretorio = fopen(argv[1], "r+");

    ///se abrir o arquivo
    if(diretorio){
        ///enquanto nao for final de arquivo
        while(!feof(diretorio)){
            ///le os diretorios
            char* aux = (char*)malloc(sizeof(char)*100);
            fscanf(diretorio, "%[^\n]%*c", aux);
            ///enfileira
            pushQ(fila,aux);
        }
    }else{
        printf("%s\n", strerror(errno));
    }

    ///fecha o arquivo
    fclose(diretorio);
    return fila;
}

///
/// le os textos do arquivo
/// \brief readDadosToFile
/// \param diretorio
/// \return fila com os os textos guardados
/// \pre nenhum
/// \post texto lido
///
Queue* readDadosToFile(Queue *diretorio){

    QNode* aux = NULL;
    Queue* textQueue = createQueue();
    baseDados* dados = NULL;
    char** vetAux;
    int tam = 10;
    FILE* text;

    ///desenfileira
    aux = popQ(diretorio);
    while(aux){
        text = fopen(aux->info, "r+");
        ///le o texto
        vetAux = readToVectorDynamic(text, &tam);

        if(vetAux){
            ///aloca e guarda as insformacoes
            dados = (baseDados*)malloc(sizeof(baseDados));
            dados->palavras = vetAux;
            dados->tamPal = tam;
            dados->fileName = aux->info;
            ///enfileira os dados
            pushQ(textQueue, dados);
        }
        free(aux);
        ///desenfileira o proximo diretorio
        aux = popQ(diretorio);
        fclose(text);
    }
    ///deleta a fila
    deleteQueue(diretorio);

    if(textQueue){
        return textQueue;
    }else{
        return NULL;
    }
}

///
/// transforma o texto em palavras isoladas
/// \brief matrizToTokens
/// \param text
/// \param numArquivos
/// \return vetor de estrutura contendo insformacoes dos textos
/// \pre nenhum
/// \post nenhum
///
baseDados **matrizToTokens(Queue *text, int *numArquivos){

    int count = text->count;
    QNode* aux = NULL;
    baseDados** dados = (baseDados**)malloc(count * sizeof(baseDados*));
    int i;

    ///desenfileira
    aux = popQ(text);
    if(aux != NULL){

        for(i = 0; i < count ; i++){
            dados[i] = (baseDados*)malloc(sizeof(baseDados));
            baseDados* baseAux = (baseDados*)aux->info;

            ///salva o diretorio
            dados[i]->fileName = baseAux->fileName;
            ///concatena o texto, quebra em palavras e salva no vetor de strings
            dados[i]->palavras = strToken(strConcatena(baseAux),&dados[i]->tamPal);

            free(aux);
            ///pega o proximo arquivo
            aux = popQ(text);
        }
    }else{
        printf("%s\n", strerror(errno));
    }

    (*numArquivos) = i;
    deleteQueue(text);
    return dados;
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

    ///enquanto esquerda for menor ou igual a direira
    while (esq <= dir) {

        /// compara se vet[esq] eh menor que o pivo e incrementa um
        while (strcasecmp(vet[esq], pivot) < 0)
            esq++;

        /// compara se vet[dir] eh maior que o pivo e decrementa um
        while (strcasecmp(vet[dir], pivot )> 0)
            dir--;

        /// se inicio for menor ou igual ao fim, troca:
        if (esq <= dir) {
            tmp = vet[esq];
            vet[esq] = vet[dir];
            vet[dir] = tmp;
            esq++;
            dir--;
        }
    };

    ///se o inicio for menor q a direira
    if (inicio < dir)
        QuickSortChar(vet, inicio, dir);
    ///se a esquerda for menor que o final
    if (esq < fim)
        QuickSortChar(vet, esq, fim);
}

///
/// le strings em um vetor dinamico
/// \brief readToVectorDynamic
/// \param arquivo
/// \param tam
/// \return vetor de strings
/// \pre nenhum
/// \post vetor de strings lido
///
char** readToVectorDynamic(FILE* arquivo, int *tam){

    char str[256];
    char** vetAux;
    int i;

    if(arquivo){
        ///aloca a matriz
        vetAux = (char**)malloc((*tam)*sizeof(char*));

        ///enquanto não for final de arquivo
        for(i = 0; !feof(arquivo); ++i){
            ///se chegar no final da capacidade da matriz
            if(i+1 > (*tam)){
                ///dobra o tamanho
                (*tam) *= 2;
                ///e realoca
                vetAux = (char**)realloc(vetAux, (*tam)*sizeof(char*));
            }
            ///le a cadeia de char do arquivo na string auxiliar
            fscanf(arquivo, "%[^\n]%*c", str);
            ///copia a string auxiliar para a matriz
            vetAux[i] = strcpy(malloc(sizeof(char)*strlen(str)+1), str);

        }
        ///tamanho recebe o numero de iteracoes
        (*tam) = i;
        ///realoca com o tamanho final
        vetAux = (char**)realloc(vetAux,(*tam)*sizeof(char*));
    }
    return vetAux;
}


///
/// quebra uma string em varias de acordo com um caractere
/// \brief strToken
/// \param strVet
/// \param tam
/// \return vetor de string
/// \pre nenhum
/// \post vetor se string
///
char** strToken(char* strVet, int *tam){

    char* token = NULL;
    (*tam) = 2;
    char** aux = (char**)malloc((*tam)*sizeof(char*));
    int i = 0;

    ///separa a strins por espaco em branco
    token = strtok(strVet, " ");
    while(token){
        ///enquanto tiver espaco vai alocando e separando
        if(i+1 == (*tam)){
            *tam *= 2;
            aux = realloc(aux, (*tam)*sizeof(char*));
        }
        aux[i] = (char*)malloc((strlen(token))*sizeof(char));
        strcpy(aux[i], token);
        token = strtok(NULL, " ");
        i++;
    }
    ///tam recebe o numero de palavras
    (*tam) = i;
    free(strVet);
    return aux;
}


///
/// concatena o texto em uma unica string
/// \brief strConcatena
/// \param dados
/// \return string contendo todo o texto
/// \pre nenhum
/// \post texto concatenado em uma unica string
///
char* strConcatena(baseDados *dados){
    int i;

    int count =  matrizLen(dados->palavras, dados->tamPal) + dados->tamPal;
    ///aloca espaço para a string de destino
    char* dest = (char*)malloc((count + 1)*sizeof(char));

    ///copia a primeira string do vetor
    strcpy(dest, dados->palavras[0]);
    ///concatena um espaco em branco
    strcat(dest, " ");

    for(i = 1; i < dados->tamPal; i++){
        ///concatena as strings do vetor de string
        strcat(dest, dados->palavras[i]);
        ///concatena um espaço em branco
        strcat(dest, " ");
    }

    freeBaseDados(dados);
    return dest;
}

///
/// calcula o tamanho total das strings
/// \brief matrizLen
/// \param src
/// \param tam
/// \return o tamanho so somatorio das strings
/// \pre nenhum
/// \post nenhum
///
int matrizLen(char** src, int tam){
    int i, count = 0;

    for(i = 0; i < tam; i++){
        ///soma o numero total do tamanho das strings
        count += strlen(src[i]);
    }
    return count;
}

///
/// libera a memoria da base
/// \brief freeBaseDados
/// \param base
/// \pre nenhum
/// \post memoria liberada
///
void freeBaseDados(baseDados* base){
    int i;
    for(i = 0; i < base->tamPal; i++){
        ///libera memoria da base
        free(base->palavras[i]);
    }
    free(base);
}

///
/// procura no texto stopwords
/// \brief findStopWords
/// \param src
/// \param stopWords
/// \return string sem stopword
/// \pre nenhum
/// \post removido stopwords
///
char* findStopWords(char* src, StopWords* stopWords){

    ///pega o tamanho da palavra
    int endIndex = (unsigned) strlen(src);

    ///se for palavra vazia coloca um espaco em branco
    if(endIndex < 2) {
        ///adiciona no vetor de stopWords
        addStopWords(src[0], stopWords);
        return " ";
    }

    ///se a ultima posicao for um caractere de pontuacao remove
    if(src[endIndex-1] < 'a' || src[endIndex-1] > 'z'){
        if(src[endIndex-1] < 'A' || src[endIndex-1] > 'Z'){
            if(src[endIndex-1] < '0' || src[endIndex-1] > '9'){
                ///e adiciona no vetor de stopwords
                addStopWords(src[endIndex-1], stopWords);
                src[endIndex-1] = '\0';
                return src;
            }
        }
    }

    return src;
}

///
/// adiciona as stopwords identificadas no texto dentro da lista
/// \brief addStopWords
/// \param c
/// \param stopWords
/// \pre nenhum
/// \post stopWord inserida
///
void addStopWords(char c, StopWords* stopWords){

    char* str = (char*)malloc(2*sizeof(char));

    str[0] = c;
    str[1] = '\0';

    ///se n existe no vetor de stopwords
    if(!buscaStopWords(str, stopWords)){
        int count = stopWords->count;

        ///adiciona no vetor
        stopWords->stopWords = realloc(stopWords->stopWords,(count+1)*sizeof(char*));
        stopWords->stopWords[count] = str;
        stopWords->count++;

    }
}

///
/// atualiza os dados de cada arquivo
/// \brief DadosUpdate
/// \param dados
/// \param stopwords
/// \param numArquivo
/// \return vetor de dados atualizado
/// \pre nenhum
/// \post dados sem stopwords e sem espaco em branco
///
baseDados** DadosUpdate(baseDados** dados, StopWords* stopwords, int numArquivo){

    int i, j;
    int count = 0;

    ///identifica as stopwords
    for(i = 0; i < numArquivo; i++){
        for(j = 0; j < dados[i]->tamPal; j++){
            dados[i]->palavras[j] = findStopWords(dados[i]->palavras[j], stopwords);
        }
    }

    /// deleta as stopwords do vetor de palavras
    dados = deleteStopWordsFromDados(dados, numArquivo, stopwords);

    ///apaga os espacos vazios do vetor
    for(i = 0; i < numArquivo; i++){
        count = dados[i]->tamPal -  countElement(dados[i], " ");
        dados[i] = deleteSpaceFromDados(dados[i], count);
    }
    return dados;
}

///
/// busca stopword no vetor de stopwords
/// \brief buscaStopWords
/// \param src
/// \param stopWords
/// \return 1 se já possui no vetor e 0 caso contrario
/// \pre nenhum
/// \post nenhum
///
int buscaStopWords(char* src, StopWords* stopWords){
    int i;
    for(i = 0; i < stopWords->count; i++){
        ///compara se a palavra já pertence ao vetor de stopwords
        if(!strcasecmp(src, stopWords->stopWords[i])){
           return 1;
        }
    }
    return 0;
}

///
/// deleta stopwords do vetor de palavra
/// \brief deleteStopWordsFromDados
/// \param dados
/// \param numFile
/// \param stopword
/// \return dados atualizados
/// \pre nenhum
/// \post texto sem stopwords
///
baseDados** deleteStopWordsFromDados(baseDados** dados, int numFile, StopWords* stopword){

    int i,j;
    for(i = 0; i < numFile; i++){
        for(j = 0; j < dados[i]->tamPal; j++){
            ///se for stopwords coloca um vazio na posicao
            if(buscaStopWords(dados[i]->palavras[j], stopword)){
                dados[i]->palavras[j] = " ";
            }
        }
    }
    return dados;
}

///
/// conta o numero de caracteres no vetor de palavras
/// \brief countElement
/// \param dados
/// \param element
/// \return numero de ocorrencias
/// \pre nenhum
/// \post nenhum
///
int countElement(baseDados* dados, char* element){

    int count = 0;
    int j;

    for(j = 0; j < dados->tamPal; j++){
        ///compara e conta a ocorrencia de um deteminado elemento na string
        if(!strcasecmp(dados->palavras[j], element)){
            count++;
        }
    }
    return count;
}

///
/// apaga espacos em branco do vetor de palavras
/// \brief deleteSpaceFromDados
/// \param dados
/// \param numElement
/// \return dados atualizados
/// \pre nenhum
/// \post vetor de palavras sem os espacos em algumas posicoes
///
baseDados* deleteSpaceFromDados(baseDados* dados, int numElement){

    char** newString = (char**)malloc(numElement*sizeof(char*));
    int i, j;

    for(j = i = 0; j < dados->tamPal; j++){

        ///se nao for espaco em branco
        if(strcmp(dados->palavras[j], " ")){
            ///adiciona ao novo vetor
            newString[i++] = dados->palavras[j];
        }else{
            free(dados->palavras[j]);
        }
    }

    free(dados->palavras);
    dados->palavras = newString;
    dados->tamPal = i;

    return dados;
}

///
/// adiciona as palavras no arquivo de indices
/// \brief addWordsToFile
/// \param arqInvertido
/// \param arqRegistro
/// \param dados
/// \param numArquivos
/// \pre vetor de palavras tratadas
/// \post palavras inseridas no arquivo de indices
///
void addWordsToFile(FILE* arqInvertido,FILE* arqRegistro, baseDados** dados, int numArquivos){

    if ((arqInvertido = fopen("arqInvertido.bin", "wb+")) == NULL) return;
    if ((arqRegistro = fopen("arqRegistro.bin", "wb+")) == NULL) return;
    createEmptyBTree(arqInvertido);
    criarHeaderArquivoInvertido(arqRegistro);

    int i,j, idArquivo;
    headerArqInv* headerArq = readHeaderArquivoInvertido(arqRegistro);
    arqInv* found = NULL;

    for(i = 0; i < numArquivos; i++){
        for(j = 0; j < dados[i]->tamPal; j++){
            idArquivo = (i+1);
            ///procura a palavra na arvore

            found = buscarPalavraBTree(arqInvertido, arqRegistro, dados[i]->palavras[j]);
            ///se a palavra nao existe na arvore
            if(!found){
                ///cria um novo registro
                arqInv* novoArq = criarArquivoInvertido();
                ///adiciona o numero do arquivo que a palavra pertence
                novoArq->arquivo = idArquivo;

                ///insere na arvore na posicao que foi escrito no arquivo
                insertBTree(arqInvertido,dados[i]->palavras[j],
                            writeArquivoInvertido(arqRegistro, headerArq, novoArq));

                found = buscarPalavraBTree(arqInvertido, arqRegistro, dados[i]->palavras[j]);
            ///se a palavra ja existe na arvore
            }else{
                ///
                arqInv* arq = found, *proxArq;


                ///enquanto o numero do arquivo for diferente do arquivo onde está a palavra
                while(arq->arquivo != idArquivo){
                    ///le o proximo registro encadeado da palavra
                    proxArq = readArquivoInvertido(arqRegistro,arq->proxPosicao);


                    ///se n tiver proximo registro
                    if(!proxArq){
                        ///cria um novo registro
                        arqInv* newArqInv = criarArquivoInvertido();

                        ///adiciona o numero do arquivo
                        newArqInv->arquivo = idArquivo;

                        ///o registro da palavra atual recebe como proximo a posicao do novo registro inserido
                        arq->proxPosicao = writeArquivoInvertido(arqRegistro, headerArq, newArqInv);

                        ///escreve o registro no arquivo
                        writeArquivoInvertido(arqRegistro,headerArq, arq);

                        ///o proximo registro recebe o novo registro
                        proxArq = newArqInv;
                    }
                    free(arq);
                    arq = proxArq;
                }

                found = arq;

            }

            ///atualiza o registro
            if(found){
                found->quantidadePalavras++;
                writeArquivoInvertido(arqRegistro,headerArq,found);
                free(found);
            }
        }
    }

    fclose(arqInvertido);
    fclose(arqRegistro);
}


///
/// printar na tela os registros
/// \brief printRegistros
/// \param arqRegistro
/// \param RegPos
/// \pre nenhum
/// \post nenhum
///
void printArquivoInverso(){
    BTreeHeader* header;
    BTreeNode* raiz;

    FILE* arqInvFile = NULL, *arqRegitroFile = NULL;

    ///abre os arquivos
    if ((arqInvFile = fopen("arqInvertido.bin", "rb+")) == NULL) return;
    if ((arqRegitroFile = fopen("arqRegistro.bin", "rb+")) == NULL) return;

    ///le o header e a raiz
    header = readBTreeHeader(arqInvFile);
    raiz = readBTreeNode(arqInvFile, header->root);

    ///se a raiz existir  printa as palavras
    if(raiz) printPalavrasToArqInvert(arqInvFile, arqRegitroFile, raiz);

    free(header);
    free(raiz);

    fclose(arqInvFile);
    fclose(arqRegitroFile);
}

///
/// printar na tela as palavras
/// \brief printPalavrasToArqInvert
/// \param arqInvertido
/// \param arqRegistro
/// \param node
/// \pre nenhum
/// \post nenhum
///
void printPalavrasToArqInvert(FILE* arqInvertido,FILE* arqRegistro, BTreeNode* node){
    BTreeNode* noAtual;

    if(!node)return;

    noAtual = readBTreeNode(arqInvertido, node->children[0]);
    printPalavrasToArqInvert(arqInvertido, arqRegistro, noAtual);
    free(noAtual);

    int i;
    for(i = 0; i < node->keyNum; i++){
        ///printa as palavras presente na arvore B
        printf("%-16s ", node->keys[i].id);
        ///printa o encadeamento
        printRegistros(arqRegistro, node->keys[i].regPos);

        noAtual = readBTreeNode(arqInvertido, node->children[i+1]);
        printPalavrasToArqInvert(arqInvertido, arqRegistro, noAtual);

        free(noAtual);
    }
}

///
/// printa na tela o arquivo de indices
/// \brief printArquivoInverso
/// \pre nenhum
/// \post nenhum
///
void printRegistros(FILE* arqRegistro, int RegPos){
    arqInv* arq = readArquivoInvertido(arqRegistro, RegPos);
    arqInv* prox;

    while(arq){

        ///printa o numero de arquivo e a quantidade de palavras
        printf("%d,%d ", arq->arquivo, arq->quantidadePalavras);

        ///le p proximo registro encadeado
        prox = readArquivoInvertido(arqRegistro, arq->proxPosicao);
        free(arq);
        arq = prox;
    }
    printf("\n");
}

/// printa na tela o resultado da pesquisa
/// \brief pesquisaregistro
/// \param dados
/// \param numArquivo
/// \pre nenhum
/// \post nenhum
///
void pesquisaregistro(baseDados** dados, int numArquivo){

    FILE* arqInvert  = NULL;
    FILE* arqRegistro = NULL;
    char pesquisa[128];
    char** palavras;
    int tamanhoPalavra;

    ///abre os arquivos
    if ((arqInvert = fopen("arqInvertido.bin", "rb+")) == NULL) return;
    if ((arqRegistro = fopen("arqRegistro.bin", "rb+")) == NULL) return;

    BTreeHeader* header = readBTreeHeader(arqInvert);
    BTreeNode* raiz = readBTreeNode(arqInvert, header->root);

    ///le a string de busca
    if(raiz){
        printf("Consulta: \n");

        fflush(stdin);
        scanf("%[^\n]%*c", pesquisa);

        ///separa em varias palavras
        palavras = separarPalavras(pesquisa, &tamanhoPalavra);

        ///pesquisa as palavras
        pesquisaPalavra(dados, arqInvert, arqRegistro, palavras, tamanhoPalavra, numArquivo);
    }

    free(raiz);
    free(header);

    fclose(arqInvert);
    fclose(arqRegistro);
}

///
/// separa as palavras da string de pesquisa
/// \brief separarPalavras
/// \param pesquisa
/// \param tamanhoPalavra
/// \return vetor de palavras
/// \pre nenhum
/// \post palavras de pesquisa separadas
///
char** separarPalavras(char *pesquisa, int *tamanhoPalavra){

    char** palavras;
    char palavraAtual[128];

    int offset, n, i;
    int tamanhoPesquisa = (int)strlen(pesquisa);

    (*tamanhoPalavra) = 2;

    palavras = (char**)malloc((*tamanhoPalavra) * sizeof(char*));

    for(offset = n = i  = 0; offset < tamanhoPesquisa; offset += n){
        sscanf((const char*)(pesquisa + offset), "%s%n", palavraAtual, &n);
        if(palavraAtual[0]){
            if(i + 1 == *tamanhoPalavra){
                *tamanhoPalavra *= 2;
                palavras = (char**)realloc(palavras, (*tamanhoPalavra) * sizeof(char*));
            }

            palavras[i++] = strcpy(malloc(strlen(palavraAtual)+1), palavraAtual);
        }
    }

    (*tamanhoPalavra) = i;
    palavras = (char**)realloc(palavras, (*tamanhoPalavra) * sizeof(char*));

    return palavras;

}

///
/// pesquisa a palavra indicada
/// \brief pesquisaPalavra
/// \param dados
/// \param arqInvert
/// \param arqRegistro
/// \param palavras
/// \param tamanhoPalavra
/// \param numArquivo
/// \pre nenhum
/// \post nenhum
///
void pesquisaPalavra(baseDados** dados, FILE *arqInvert, FILE *arqRegistro, char **palavras, int tamanhoPalavra, int numArquivo){

    arqInv* registro;
    arqInv** entrada = NULL;
    int i, tamanhoEntrada = 0;
    int total, tamanhoDiretorio;

    ///pega os diretorios
    char** diretorio = buscarDiretorio(dados,numArquivo, &tamanhoDiretorio);

    ///se existem palavras a serem buscada
    if(tamanhoPalavra){
        ///adiciona os resultados da primeira palavra
        entrada = addRegistros(arqRegistro, buscarPalavraBTree(arqInvert, arqRegistro, palavras[0]),
                &tamanhoEntrada);
    }


    ///intersecao com o resultado da proxima palavra
    for(i = 1; i < tamanhoPalavra; i++){
        registro = buscarPalavraBTree(arqInvert,arqRegistro, palavras[i]);

        entrada = updateEntrada(arqRegistro, registro, entrada, &tamanhoEntrada);
    }


    ///se existe resultado sobrando
    if(tamanhoEntrada){
        ///vetor de checagem de arquivo dulicado
        int duplicado[tamanhoDiretorio];
        memset(duplicado, 0, sizeof(int)* tamanhoDiretorio);

        for(i = total = 0; i < tamanhoEntrada; i++){
            ///se ja foi tratado
            if(!duplicado[entrada[i]->arquivo - 1]){
                total++;
                duplicado[entrada[i]->arquivo - 1] = 1;
            }
        }

        ///imprime a quantidade de ocorrencias e os diretorios
        printf("qtd: %d\n", total);
        printf("Documentos: \n");
        for(i = 0; i < tamanhoEntrada; i++){
            if(duplicado[entrada[i]->arquivo - 1]){
                printf("%s\n", diretorio[entrada[i]->arquivo - 1]);
                duplicado[entrada[i]->arquivo - 1] = 0;
            }

            free(entrada[i]);
        }
    }else{
        ///se n houver resultado
        printf("Nao existe Resultado!\n");
    }
}

///
/// busca no vetor de dados os diretorios
/// \brief buscarDiretorio
/// \param dados
/// \param numArquivo
/// \param tamanhoDiretorio
/// \return vetor com os diretorios
/// \pre nenhum
/// \post nenhum
///
char** buscarDiretorio(baseDados** dados, int numArquivo, int* tamanhoDiretorio){

    char** diretorio = (char**)malloc(sizeof(char*));
    int i;

    ///pega os diretorios do vetor de dados
    for(i = 0; i < numArquivo; i++){
        diretorio[i] = (char*)malloc(sizeof(char));
        diretorio[i] = dados[i]->fileName;
    }

    (*tamanhoDiretorio) = i;

    return diretorio;
}

///
/// adiciona os registros na lista de registros
/// \brief addRegistros
/// \param arqRegistro
/// \param registro
/// \param tamanhoEntrada
/// \return lista de registro alocada
/// \pre nenhum
/// \post nenhum
///
arqInv** addRegistros(FILE* arqRegistro ,arqInv* registro ,int* tamanhoEntrada){
    int i = 0;
    arqInv* arq = NULL;

    (*tamanhoEntrada) = 2;

    arqInv** entrada = malloc(sizeof(arqInv*) * (*tamanhoEntrada));

    arq = registro;

    ///enquanto estiver registro
    while(arq){
        ///se estourar o tamanho realoca
        if (i + 1 >= (*tamanhoEntrada)) {
            (*tamanhoEntrada) *= 2;
            entrada = realloc(entrada, sizeof(arqInv*) * (*tamanhoEntrada));
        }
        entrada[i++] = arq;
        arq = readArquivoInvertido(arqRegistro, arq->proxPosicao);
    }

    ///realoca ao tamanho final
    (*tamanhoEntrada) = i;
    entrada = realloc(entrada, sizeof(arqInv*) * (*tamanhoEntrada));


    return entrada;
}

///
/// intercessao do registro do vetor com a lista encadeada
/// \brief updateEntrada
/// \param arqRegistro
/// \param registro
/// \param entrada
/// \param tamanhoEntrada
/// \return registro atualizado
/// \pre nenhuma
/// \post nenhuma
///
arqInv** updateEntrada(FILE* arqRegistro, arqInv* registro, arqInv** entrada, int* tamanhoEntrada){
    arqInv* arq = NULL;
    arqInv* proxEntrada = NULL;


    int novoTamanhoEntrada = 2;
    int j = 0, contadorRegistro = 0;
    arqInv** novaEntrada = malloc(novoTamanhoEntrada * sizeof(arqInv*));
    int i;

     /// para cada registro faz intercessão com o vetor
    arq = registro;
    while(arq){
        proxEntrada = readArquivoInvertido(arqRegistro, arq->proxPosicao);

        contadorRegistro = 0;
        for(i = 0; i < (*tamanhoEntrada); i++){
            if(entrada[i]){
                /// se arquivo também é presente no vetor passado
                if(entrada[i]->arquivo == arq->arquivo){
                    contadorRegistro = 1;
                    if(j+1 >= novoTamanhoEntrada){
                        novoTamanhoEntrada *= 2;
                        novaEntrada = realloc(novaEntrada, sizeof(arqInv*) * (novoTamanhoEntrada));
                    }
                    novaEntrada[j++] = entrada[i];
                    entrada[i] = NULL;
                }
            }
        }
        if(contadorRegistro){
            if(j + 1 >= novoTamanhoEntrada){
                novoTamanhoEntrada *= 2;
                novaEntrada = realloc(novaEntrada, sizeof(arqInv*) * (novoTamanhoEntrada));
            }
            novaEntrada[j++] = arq;
        }else{
            free(arq);
        }

        arq = proxEntrada;
    }

    ///libera memoria do registro
    for(i = 0; i < (*tamanhoEntrada); i++){
        if(entrada[i]) free(entrada[i]);
    }

    ///realoca no tamanho final
    (*tamanhoEntrada) = j;
    novaEntrada = realloc(novaEntrada, sizeof(arqInv*) * (novoTamanhoEntrada));

    free(entrada);

    return novaEntrada;
}
