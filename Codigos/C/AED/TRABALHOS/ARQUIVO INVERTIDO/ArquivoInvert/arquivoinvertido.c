#include"arquivoinvertido.h"

/**
 * cria o header para o arquivo invertido,
 * @param file, arquivo a ser manipulado
 * Pre-condicao: funcao auxiliar writeHeaderArquivoInvertido
 * Pos-condicao: nenhuma
 */
void criarHeaderArquivoInvertido(FILE* file){

    headerArqInv* header = (headerArqInv*)malloc(sizeof(headerArqInv));

    // posiciona o header
    header->topPosicao = 0;

    // escreve no arquivo o header
    writeHeaderArquivoInvertido(file, header);
}

/**
 * crir o Arquivo Invertido, e inicializa os campos
 * @return o novo arquivo invertido criado
 * Pre-condicao: nenhuma
 * Pos-condicao: nenhuma
 */
arqInv* criarArquivoInvertido(){
    arqInv* arq = (arqInv*)malloc(sizeof(arqInv));

    // inicializa os campos
    arq->arquivo = -1;
    arq->quantidadePalavras = 0;
    arq->posicao = -1;
    arq->proxPosicao = -1;

    // novo arquivo
    return arq;
}

/**
 * escreve o cabeçalho no Arquivo Invertido
 * @param file, arquivo que vai escrever
 * @param header, cabeçalho
 * Pre-condicao: nenhuma
 * Pos-condicao: nenhuma
 */
void writeHeaderArquivoInvertido(FILE* file, headerArqInv* header){

    fseek(file, 0, SEEK_SET);

    // escreve no arquivo o que esta em header
    fwrite(header, sizeof(headerArqInv), 1, file);
}

/**
 * escreve Arquivo Invertido
 * @param file, arquivo a ser manipulado
 * @param header, cabeçalho
 * @param arq, nome do arquivo invertido
 * @return posicao
 * Pre-condicao: nenhuma
 * Pos-condicao: nenhuma
 */
int writeArquivoInvertido(FILE* file, headerArqInv* header, arqInv* arq){
    int posicao;

    // verifica a posicao do arquivo, se for igual a -1
    if((posicao = arq->posicao) == -1){

        //incrementa uma posicao no header
        posicao = header->topPosicao++;

        // escreve o novo header no arquivo invertido
        writeHeaderArquivoInvertido(file, header);
    }

    //posicao do arquivo recebe variavel posicao
    arq->posicao = posicao;

    fseek(file, sizeof(headerArqInv)+sizeof(arqInv)*posicao, SEEK_SET);
    fwrite(arq, sizeof(arqInv), 1, file);

    // retorna posicao atualizada
    return posicao;
}

/**
 * le o inicio (cabecalho) do Arquivo Invertido
 * @param file, arquivo que vai ser lido
 * @return o inicio do arquivo
 * Pre-condicao: nenhuma
 * Pos-condicao: nenhuma
 */
headerArqInv* readHeaderArquivoInvertido(FILE* file){
    headerArqInv* header = (headerArqInv*)malloc(sizeof(headerArqInv));

    fseek(file, 0, SEEK_SET);

    // le no arquivo o header
    fread(header, sizeof(headerArqInv), 1, file);

    // retorna o novo header
    return header;
}

/**
 * le Arquivo Invertido
 * @param file, arquivo que vai ser lido
 * @param posicao, posicao do arquivo
 * @return o arquvo lido
 * Pre-condicao: nenhuma
 * Pos-condicao: nenhuma
 */
arqInv* readArquivoInvertido(FILE *file, int posicao){
    arqInv* arq = (arqInv*)malloc(sizeof(arqInv));

    // se posicao for igual a -1 retorna NULL, se nao
    if(posicao == -1) return NULL;

    fseek(file, sizeof(headerArqInv)+sizeof(arqInv)*posicao, SEEK_SET);

    // le o arquivo
    fread(arq, sizeof(arqInv), 1, file);

    // retorna o arquivo
    return arq;
}

/**
 * imprime o inicio do arquivo
 * @param header, cabecalho
 * Pre-condicao: nenhuma
 * Pos-condicao: nenhuma
 */
void showheader(headerArqInv* header){

    // imprime a posicao do cabecalho
    printf("------------------------------\n");
    printf("Posicao: %d\n", header->topPosicao);
    printf("------------------------------\n");
}

/**
 * imprime o Arquivo Inverso
 * @param arq, arquivo inverso a que sera impresso
 * Pre-condicao: nenhuma
 * Pos-condicao: nenhuma
 */
void showArquivoInverso(arqInv* arq){

    // imprime todos os campos do Arquivo invertido
    printf("------------------------------\n");
    printf("arquivo: %d\n", arq->arquivo);
    printf("Quantidade de palavras: %d\n", arq->quantidadePalavras);
    printf("Posicao: %d\n", arq->posicao);
    printf("Proxima Posicao: %d\n", arq->proxPosicao);
    printf("------------------------------\n");
}

