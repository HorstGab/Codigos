#ifndef BASEDADOS
#define BASEDADOS
#include "fila.h"
#include "arquivoinvertido.h"
#include "arvoreb.h"

typedef struct base{
    ///vetor de string de palavras
    char** palavras;
    ///quantidade de palavras do vetor
    int tamPal;
    ///nome do arquivo
    char* fileName;

}baseDados;

typedef struct{
    ///vetor de string de stop words
    char** stopWords;
    ///quantidade de stop words
    int count;
}StopWords;

///
/// le os textos do arquivo
/// \brief readDadosToFile
/// \param diretorio
/// \return fila com os os textos guardados
/// \pre nenhum
/// \post texto lido
///
Queue *readDadosToFile(Queue* diretorio);

///
/// le as stopwords do arquivo
/// \brief readStopWords
/// \param argv
/// \return estrutura com as stopwords
/// \pre nenhuma
/// \post stopwords lidos
///
StopWords *readStopWords(char **argv);

///
/// printa as stop Words
/// \brief printfStopWords
/// \param stopWordVetor
/// \pre nenhuma
/// \post nenhuma
///
void printfStopWords(StopWords* stopWordVetor);

///
/// le os diretorio dos arquivos
/// \brief readBaseDados
/// \param argv
/// \param fila
/// \return fila contendo os diretorios
/// \pre nenhum
/// \post fila com os diretorios
///
Queue* readBaseDados(char **argv, Queue* fila);

///
/// transforma o texto em palavras isoladas
/// \brief matrizToTokens
/// \param text
/// \param numArquivos
/// \return vetor de estrutura contendo insformacoes dos textos
/// \pre nenhum
/// \post nenhum
///
baseDados** matrizToTokens(Queue *text, int *numArquivos);

///
/// ordena o vetor
/// \brief QuickSortChar
/// \param vet
/// \param inicio
/// \param fim
/// \pre nenhum
/// \post vetor ordenado
///
void QuickSortChar(char **vet, int inicio, int fim);

///
/// le strings em um vetor dinamico
/// \brief readToVectorDynamic
/// \param arquivo
/// \param tam
/// \return vetor de strings
/// \pre nenhum
/// \post vetor de strings lido
///
char** readToVectorDynamic(FILE* arquivo, int *tam);


///
/// quebra uma string em varias de acordo com um caractere
/// \brief strToken
/// \param strVet
/// \param tam
/// \return vetor de string
/// \pre nenhum
/// \post vetor se string
///
char** strToken(char* strVet, int *tam);

///
/// concatena o texto em uma unica string
/// \brief strConcatena
/// \param dados
/// \return string contendo todo o texto
/// \pre nenhum
/// \post texto concatenado em uma unica string
///
char* strConcatena(baseDados *dados);


///
/// calcula o tamanho total das strings
/// \brief matrizLen
/// \param src
/// \param tam
/// \return o tamanho so somatorio das strings
/// \pre nenhum
/// \post nenhum
///
int matrizLen(char** src, int tam);

///
/// libera a memoria da base
/// \brief freeBaseDados
/// \param base
/// \pre nenhum
/// \post memoria liberada
///
void freeBaseDados(baseDados* base);

///
/// procura no texto stopwords
/// \brief findStopWords
/// \param src
/// \param stopWords
/// \return string sem stopword
/// \pre nenhum
/// \post removido stopwords
///
char* findStopWords(char* src, StopWords* stopWords);

///
/// adiciona as stopwords identificadas no texto dentro da lista
/// \brief addStopWords
/// \param c
/// \param stopWords
/// \pre nenhum
/// \post stopWord inserida
///
void addStopWords(char c, StopWords* stopWords);

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
baseDados** DadosUpdate(baseDados** dados, StopWords* stopwords, int numArquivo);

///
/// busca stopword no vetor de stopwords
/// \brief buscaStopWords
/// \param src
/// \param stopWords
/// \return 1 se já possui no vetor e 0 caso contrario
/// \pre nenhum
/// \post nenhum
///
int buscaStopWords(char* src, StopWords* stopWords);

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
baseDados** deleteStopWordsFromDados(baseDados** dados, int numFile, StopWords* stopword);

///
/// conta o numero de caracteres no vetor de palavras
/// \brief countElement
/// \param dados
/// \param element
/// \return numero de ocorrencias
/// \pre nenhum
/// \post nenhum
///
int countElement(baseDados *dados, char* element);

///
/// apaga espacos em branco do vetor de palavras
/// \brief deleteSpaceFromDados
/// \param dados
/// \param numElement
/// \return dados atualizados
/// \pre nenhum
/// \post vetor de palavras sem os espacos em algumas posicoes
///
baseDados *deleteSpaceFromDados(baseDados *dados, int numElement);


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
void addWordsToFile(FILE* arqInvertido,FILE* arqRegistro, baseDados** dados, int numArquivos);

///
/// printar na tela os registros
/// \brief printRegistros
/// \param arqRegistro
/// \param RegPos
/// \pre nenhum
/// \post nenhum
///
void printRegistros(FILE* arqRegistro, int RegPos);

///
/// printar na tela as palavras
/// \brief printPalavrasToArqInvert
/// \param arqInvertido
/// \param arqRegistro
/// \param node
/// \pre nenhum
/// \post nenhum
///
void printPalavrasToArqInvert(FILE* arqInvertido,FILE* arqRegistro, BTreeNode* node);

///
/// printa na tela o arquivo de indices
/// \brief printArquivoInverso
/// \pre nenhum
/// \post nenhum
///
void printArquivoInverso();


/// printa na tela o resultado da pesquisa
/// \brief pesquisaregistro
/// \param dados
/// \param numArquivo
/// \pre nenhum
/// \post nenhum
///
void pesquisaregistro(baseDados **dados, int numArquivo);

///
/// separa as palavras da string de pesquisa
/// \brief separarPalavras
/// \param pesquisa
/// \param tamanhoPalavra
/// \return vetor de palavras
/// \pre nenhum
/// \post palavras de pesquisa separadas
///
char** separarPalavras(char* pesquisa, int* tamanhoPalavra);

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
void pesquisaPalavra(baseDados **dados, FILE* arqInvert, FILE* arqRegistro, char** palavras, int tamanhoPalavra, int numArquivo);

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
char** buscarDiretorio(baseDados** dados, int numArquivo, int* tamanhoDiretorio);

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
arqInv **addRegistros(FILE* arqRegistro ,arqInv* registro ,int* tamanhoEntrada);

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
arqInv** updateEntrada(FILE* arqRegistro, arqInv* registro, arqInv** entrada, int* tamanhoEntrada);
#endif // BASEDADOS

