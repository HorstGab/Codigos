#include "start.h"

//cria a mesa
/**
 * @brief Criar_Mesa
 * @param nenhum
 * @return nova mesa
 * @pre-condicao nenhuma
 * @pos-condicao mesa criada
 */
Mesa* Criar_Mesa(){
    Mesa* nova_mesa = (Mesa*)malloc(sizeof(Mesa));
    int i;

    //inicializa a quantidade de celulas livre como 4
    nova_mesa->celula_livre = 4;
    //inicializa a quantidade de pilhas livres como 8
    nova_mesa->qnt_pilha_livre = 8;

    //cria as pilhas, celulas e fundacoes
    for(i = 0; i < 4; i++){
        nova_mesa->pilhas[i] = criar_pilha();
        nova_mesa->pilhas[i+4] = criar_pilha();
        nova_mesa->fundacoes[i] = criar_pilha();
        nova_mesa->celulas[i] = NULL;
    }

    //retorna a nova mesa
    return nova_mesa;
}

//cria cada carta do baralho
/**
 * @brief Criar_Carta
 * @param naipe
 * @param valor
 * @return nova carta
 * @pre-condicao nenhuma
 * @pos-condicao carta criada
 */
Carta* Criar_Carta(int naipe, int valor){
    Carta* nova_carta = (Carta*)malloc(sizeof(Carta));

    //inicializa uma carta com o naipe e o valor respectivo
    nova_carta->naipe = naipe;
    nova_carta->valor = valor;

    //retorna a nova carta
    return nova_carta;
}

//cria o vetor com todas as cartas
/**
 * @brief Criar_Baralho
 * @param cartas
 * @return nenhuma
 * @pre-condicao nenhuma
 * @pos-condicao baralho com as 52 cartas criada
 */
void Criar_Baralho(Carta* cartas[]){
    int naipe, valor;

    //atribui em cada posicao do vetor uma carta
    for(naipe = 0; naipe < 4; naipe++){
        for(valor = 0; valor < 13; valor++){
            cartas[naipe*13 + valor] = Criar_Carta(naipe, valor);
        }
    }
}

//inicializa o jogo
/**
 * @brief iniciar_jogo
 * @param mesa
 * @return nenhum
 * @pre-condicao nenhuma
 * @pos-condicao cartas inseridas na mesa
 */
void iniciar_jogo(Mesa* mesa){
    Carta* cartas[52];
    int i;

    //cria o baralho e embaralha
    Criar_Baralho(cartas);
    Embaralhar(cartas);

    //insere as cartas nas pilhas
    for(i = 0; i < 52; i++){
        mesa->pilhas[i%8] = insere_carta(mesa->pilhas[i%8], cartas[i]);
    }
    //inicia a quantidade de pilhas livres como zero
    mesa->qnt_pilha_livre = 0;
}

//embaralha as cartas de posicões dentro do vetor
/**
 * @brief Embaralhar
 * @param cartas
 * @return nenhum
 * @pre-condicao nenhuma
 * @pos-condicao vetor de cartas embaralhado
 */
void Embaralhar(Carta* cartas[]){
    Carta* aux = NULL;
    int i, ind;
    srand(time(NULL));

    //embaralha o vetor de carta trocando eles de posicao
    for(i = 0; i < 52; i++){
        //ind recebe um valor ate 52
        ind = rand() % 52;
        //aux recebe a carta na posicao i
        aux = cartas[i];
        //vetor na posicao i recebe a carta na posicao ind
        cartas[i] = cartas[ind];
        //posicao ind recebe o aux
        cartas[ind] = aux;
    }
}

