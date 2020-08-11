#include "arquivo.h"

#define MAX 256

void Arquivo::lerAlfabeto(Automatos *automato, FILE *arq)
{
    char strAux[MAX] = {0}, simbolo;
    int i, n, tam;


    // o formato de leitura: ler até encontrar }
    fscanf(arq, " alfabeto={ %[^}] }", strAux);

    tam = strlen(strAux);
    for(i = n = 0; i < tam; i += n){

        //le o simbolo do alfabeto e adiciciona no vetor
        sscanf(strAux + i, "%c ,%n", &simbolo, &n);

        //se o simbolo já existe
        if(automato->contemSimbolo(simbolo))
            //mostre uma mensagem de erro
            cerr << "Simbolo " << simbolo << " ja existente." << endl;

        //se não existir adicione no vetor
        automato->setAlfabeto(&simbolo);
    }
}

void Arquivo::lerEstado(Automatos *automato, FILE *arq)
{
    char estadoStr[MAX] = {0}, aux[MAX] = {0};
    int i, n;

    //o formato de leitura: ler ate encontrar }
    fscanf(arq, " estados={ %[^}] }", estadoStr);

    int tam = strlen(estadoStr);
    for(i = n = 0; i < (int)tam; i += n){

        //le o simbolo do estado e adiciona no vetor
        sscanf(estadoStr + i, "%[^,], %n", (char*)&aux, &n);

        //cria uma string com o vetor de char
        string *nomeEstado = new string(aux);

        // setar a nova variável como Estado

        //testa se o estado já existe
        if(automato->encontrarEstado(nomeEstado) != NULL)
            cerr << "Erro: Estado " << *nomeEstado << " ja existe no automato." << endl;

        //se não, insere no vetor
        automato->setEstado(nomeEstado);
    }
}

void Arquivo::lerEstadoFinal(Automatos *automato, FILE *arq)
{
    char estadoStr[MAX] = {0}, aux[MAX] = {0};
    int i, n;

    //o formato da leitura: ler até encontrar }
    fscanf(arq, " finais= {%[^}] }", estadoStr);

    for(i = n = 0; i < (int)strlen(estadoStr); i += n){
        //le o simbolo do estado e adiciona o vetor
        sscanf(estadoStr + i, "%[^,],%n", (char*)&aux, &n);

        //cria uma string com o vetor de char
        string *nomeEstado = new string(aux);

        // procura o estado e guarda em uma variável auxiliar
        Estado *aux1 = automato->encontrarEstado(nomeEstado);

        // se o estado encontrado for nulo, imprimir mensagem de erro
        if(aux1 == NULL)
            cerr << "Erro: Estado " << *nomeEstado << " nao encontrado" << endl;

        //adiciona o estado estado final no vetor
        automato->setFinal(aux1);

        delete nomeEstado;

    }
}


void Arquivo::lerEstadoInicial(Automatos *automato, FILE *arq)
{
    char str[MAX] = {0};

    getc(arq);
    //formato da leitura: o simbolo do estado inicial
    fscanf(arq, "inicial=%s", (char*)str);


    //cria uma string com o vetor de char
    string *nomeEstadoInicial = new string(str);

    // setar a nova variável como Estado Inicial
    automato->setInicial(nomeEstadoInicial);

    delete nomeEstadoInicial;
}


void Arquivo::lerTransicao(Automatos *automato, FILE *arq)
{
    char estadoOrigem[MAX] = {0}, estadoDestino[MAX] = {0};
    char simbolo = 0;

    // enquanto não chegar no final do arquivo
    while(!feof(arq)){

        //o formato da leitura: até a virgula, o simbolo e o estado
        fscanf(arq, " (%[^,],%c)= %s", (char*)estadoOrigem, &simbolo, (char*)estadoDestino);

        //cria uma nova string com os vetores de char
        string *nomeestadoOrigem = new string(estadoOrigem);
        string *nomeEstadoDestino = new string(estadoDestino);

        //encontra o estado e guarda nas variaveis
        Estado *origem = automato->encontrarEstado(nomeestadoOrigem);
        Estado *destino = automato->encontrarEstado(nomeEstadoDestino);

        //procura se existe o simbolo no alfabeto
        if(!automato->contemSimbolo(simbolo))
            cerr << "Simbolo " << simbolo << " inexistente." << endl;

        //se a origem e destino existem adiciona a transição
        if(origem && destino)
            origem->adicionarTransicao(simbolo, destino);

        //se um dos dois forem nulos exibe uma mensagm de erro
        if(!origem)
            cerr << "Estado de origem " << origem << " inexistente." << endl;
        if(!destino)
            cerr << "Estado de destino " << destino << " inexistente." << endl;

        //deleta os objetos da classe string
        delete nomeestadoOrigem;
        delete nomeEstadoDestino;
    }
}

void Arquivo::inicializarAutomato(Automatos *automato, const char *nomeArquivo)
{

    FILE *arq = fopen(nomeArquivo, "r+");

    if(arq == NULL){
        cout << "Erro na abertura do arquivo." << endl;
        return;
    }

    // Ler alfabeto
    lerAlfabeto(automato, arq);

    // Ler estado
    lerEstado(automato, arq);

    // Colocar atributos dos estados
    lerEstadoInicial(automato, arq);

    lerEstadoFinal(automato, arq);

    // Atribuir transições
    lerTransicao(automato, arq);


    fclose(arq);
}
