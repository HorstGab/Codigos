#include "pilhas.h"

//cria uma pilha vazia
/**
 * @brief criar_pilha
 * @param nenhuma
 * @return nova pilha
 * @pre-condicao nenhuma
 * @pos-condicao pilha criada
 */
Pilha* criar_pilha(){
    //aloca uma nova pilha
    Pilha* nova_pilha = (Pilha*)malloc(sizeof(Pilha));
    //inicia o tamanho com 0 e o topo e o fim da pilha apontando para null
    nova_pilha->tamanho = 0;
    nova_pilha->inicio = NULL;
    nova_pilha->fim = NULL;

    //retorna a nova pilha
    return nova_pilha;
}

//insere as cartas na mesa
/**
 * @brief insere_carta 
 * @param pilha
 * @param carta a ser inserida na pilha
 * @return pilha ou uma nova pilha se a anterior nao existir
 * @pre-condicao nenhuma
 * @pos-condicao carta inserida na pilha
 */
Pilha* insere_carta(Pilha* pilha, Carta* carta){
    No* aux = NULL;

    //se a carta for nula retorna a pilha
    if(!carta) return pilha;
    //se a pilha for nula
    if(!pilha){
        //aloca uma nova pilha
        Pilha* nova_pilha = criar_pilha();
        //pilha incrementa o tamanho
        nova_pilha->tamanho++;
        //o topo recebe uma carta
        nova_pilha->inicio = criar_no(carta);
        //o final recebe o topo;
        nova_pilha->fim = nova_pilha->inicio;
        //retorna a pilha
        return nova_pilha;
    }

    //no aux recebe o topo da pilha
    aux = pilha->inicio;
    //o topo recebe uma carta
    pilha->inicio = criar_no(carta);
    //a carta abaixo do topo recebe o no aux
    pilha->inicio->prox = aux;
    //incrementa o tamanho da pilha
    pilha->tamanho++;

    //retorna a pilha
    return pilha;
}

// cria um novo no
/**
 * @brief criar_no
 * @param carta
 * @return novo no
 * @pre-condicao nenhuma
 * @pos-condicao cria um novo no da carta
 */
No* criar_no(Carta *carta){
    //aloca um novo no
    No* novo_no = (No*)malloc(sizeof(No));

    //no recebe as informacoes da carta e o ponteiro para o proximo recebe nulo
    novo_no->carta = carta;
    novo_no->prox = NULL;

    //retorna o novo no
    return novo_no;
}

//remove um elemento da pilha
/**
 * @brief pop
 * @param pilha
 * @return retorna o topo da pilha
 * @pre-condicao nenhuma
 * @pos-condicao o topo eh removida da pilha
 */
No* pop(Pilha *pilha){
    No* aux;

    //se a pilha ou o topo nao forem nulos
    if(pilha || pilha->inicio){
        //no recebe o topo
        aux = pilha->inicio;
        //se o topo for igual ao final
        if(pilha->inicio == pilha->fim){
            //topo e final recebe NULL
            pilha->inicio = NULL;
            pilha->fim = NULL;
        }else{
            //caso contrario o topo recebe o proximo
            pilha->inicio = pilha->inicio->prox;
        }
        //decrementa o tamanho da pilha
        pilha->tamanho--;
        //proximo do no recebe NULL
        aux->prox = NULL;
    }
    //retorna o no
    return aux;
}

//inverte as pilha
/**
 * @brief inverte_pilha
 * @param pilha
 * @param pilha_reversa
 * @param andares
 * @return nenhum
 * @pre-condicao nenhuma
 * @pos-condicao a pilha eh invertida
 */
void inverte_pilha(Pilha* pilha[], No* pilha_reversa[], int *andares){
    int i;

    //enquanto o i for menor que o numero de pilhas do vetor
    for(i = *andares = 0; i < 8; i++){
        //se a pilha na posicao i do vetor nao for nula
        if(pilha[i]){
            //se o tamanho da pilha na posicao i do vetor for maior q o numero de elementos da pilha
            if(pilha[i]->tamanho > *andares){
                //andares recebe o tamanho da pilha da posicao i do vetor
                *andares = pilha[i]->tamanho;
            }
            //vetor de no recebe os nos invertidos
            pilha_reversa[i] = inverte_lista(pilha[i]->inicio);
        }
    }
}

//inverte uma pilha
/**
 * @brief inverte_lista
 * @param no
 * @return cabeça de uma cópia da lista invertida
 * @pre-condicao nenhuma
 * @pos-condicao nenhuma
 */
No* inverte_lista(No* no){
    //se o no for nulo retorna nulo
    if(!no)return NULL;

    //retorna a chamada da funcao para inserir no na cauda
    return insere_no_cauda(inverte_lista(no->prox), no->carta);
}

//insere um no na cauda
/**
 * @brief insere_no_cauda
 * @param lista
 * @param carta
 * @return lista alterada
 * @pre-condicao nenhuma
 * @pos-condicao no inserido na cauda
 */
No* insere_no_cauda(No* no, Carta* carta){
    //se o no for nulo crie uma nova
    if(!no) return criar_no(carta);
    //recursivamente atribua o proximo No no anterior
    no->prox = insere_no_cauda(no->prox, carta);

    //retorna o no
    return no;
}

