#include "modelarvore.h"

/**
 * @brief offSet
 * @param pos
 * @return posicao dentro do arquivo
 * @pre nenhum
 * @post nenhum
 */
long int offSet(int pos){
    //retorna calculo da posicao
    return (sizeof (Header) + sizeof(arvoreB) * pos);
}


/**
 * @brief abrirArquivoBinario
 * @param nomeArquivo
 * @param modo
 * @return arquivo aberto
 * @pre nenhum
 * @post nenhum
 */
FILE* abrirArquivoBinario(char *nomeArquivo, char *modo){
    //retorna o arquivo aberto
    return fopen(nomeArquivo, modo);
}


/**
 * @brief criarHeader
 * @param bd
 * @return nenhum
 * @pre nenhum
 * @post header criado
 */
void criarHeader(FILE *bd){

    //declara um novo header
    Header header;

    //inicializa o header
    header.raiz = -1;
    header.qntNo = 0;
    header.raizLivre = -1;
    header.qntNoLivre = 0;

    //escreve o header no arquivo
    escreverHeader(bd, &header);
}

/**
 * @brief criarNode
 * @return nó nulo
 * @pre nenhum
 * @post nó criado
 */
arvoreB* criarNode(){

    //declara um no da arvore
    arvoreB* node = (arvoreB*)malloc(sizeof(arvoreB));
    int  i;
    for(i = 0; i < ORDEM; ++i){
        //inicializa
        node->chaves[i].id = 0;
        node->chaves[i].posicao = -1;
        node->filho[i] = -1;
    }

    node->numChaves = 0;
    node->posicao = -1;

    //retorna o no
    return node;
}

/**
 * @brief criarNoLivre
 * @return nó livre
 * @pre nenhum
 * @post nenhum
 */
noLivre* criarNoLivre(){

    //declara um no
    noLivre* novoNoLivre = (noLivre*)malloc(sizeof(noLivre));

    //inicializa o no
    novoNoLivre->proxNode = -1;

    //retorna o no
    return novoNoLivre;
}


/**
 * @brief escreverHeader
 * @param bd
 * @param header
 * @return nenhum
 * @pre nenhum
 * @post header escrito no arquivo
 */
void escreverHeader(FILE *bd, Header *header){
    //se o header n existir retorna null
    if(!header) return;

    //caso contrario posiciona o cursor e le o header
    fseek(bd, 0, SEEK_SET);
    fwrite(header, sizeof(Header), 1, bd);
}

/**
 * @brief escreverNode
 * @param bd
 * @param header
 * @param node
 * @return posicao q o no foi inserido
 * @pre nenhum
 * @post no escrito no arquivo
 */
int escreverNode(FILE *bd, Header *header, arvoreB *node){

    int pos;

    //se o header ou o no forem invalidos retorna null
    if(!header || !node) return -1;

    //se o nao estiver no arquivo
    if((pos = node->posicao) == -1){
        //se a raiz n tiver no arquivo
        if((pos = header->raizLivre) == -1){
            //a posicao será igual a quantidade de nos existente
            pos = header->qntNo++;
        }else{
            //declara um no com a posicao e atribui a raiz da arvore
            noLivre* nodeL = lerNoLivre(bd, pos);
            header->raizLivre = nodeL->proxNode;
            //libera
            free(nodeL);
        }
    }
    //posicao do no recebe a posicao inserida
    node->posicao = pos;

    //posiciona o cursor e le o no
    fseek(bd, offSet(pos), SEEK_SET);
    fwrite(node, sizeof(arvoreB), 1, bd);

    //retorna a posicao
    return pos;
}


/**
 * @brief lerHeader
 * @param bd
 * @return header lido
 * @pre nenhum
 * @post header lido
 */
Header* lerHeader(FILE *bd){

    //declara o header
    Header* header = (Header*)malloc(sizeof(Header));

    //posciona o cursor e le o header do arquivo
    fseek(bd, 0, SEEK_SET);
    fread(header, sizeof(Header), 1, bd);

    //retorna o header lido
    return header;
}

/**
 * @brief lerNode
 * @param bd
 * @param pos
 * @return no lido
 * @pre nenhum
 * @post no lido
 */
arvoreB* lerNode(FILE *bd, int pos){

    arvoreB* node;
    //se a posicao for invalida retorna null
    if(pos == -1) return NULL;

    //aloca espaco de memoria para o no da arvore
     node = (arvoreB*)malloc(sizeof(arvoreB));

    //posiciona o cursor e le o no do arquivo
    fseek(bd, offSet(pos), SEEK_SET);
    fread(node, sizeof(arvoreB), 1, bd);

    //retorna o no lido
    return node;
}

/**
 * @brief lerNoLivre
 * @param bd
 * @param pos
 * @return no lido
 * @pre nenhum
 * @post nenhum
 */
noLivre* lerNoLivre(FILE *bd, int pos){

    noLivre* nodeL;

    //se a posicao for invalida retorna null
    if(pos == -1) return NULL;

    //aloca espaco de memoria
    nodeL = (noLivre*)malloc(sizeof(noLivre));

    //posiciona o cursor e le do arquivo
    fseek(bd, offSet(pos), SEEK_SET);
    fread(nodeL, sizeof(noLivre), 1, bd);

    return nodeL;

}


/**
 * @brief insereChave
 * @param bd
 * @param id
 * @param posReg
 * @return nenhum
 * @pre nenhum
 * @post no inserido no arquivo
 */
void insereChave(FILE *bd, int id, int posReg){

    //le do arquivo  oheader e  raiz da arvore
    Header* header = lerHeader(bd);
    arvoreB* raiz = lerNode(bd, header->raiz);
    arvoreB* novoNode;

    //atribui os dados a serem incluidos no no
    RegDados dados;
    dados.id = id;
    dados.posicao = posReg;


    //se a raiz n existir
    if(!raiz){
        //cria uma nova raiz
        raiz = criarNode();

        //atribui os dados e incrementa a quantidade de chaves
        raiz->chaves[0] = dados;
        raiz->numChaves = 1;

        //o header recebe a posicao da raiz no arquivo
        header->raiz = escreverNode(bd, header, raiz);
    //se existir
    }else{
        //busca no a ser inserido
        insere_aux(bd, header, raiz, dados);

        //se tiver overflow
        if(overflow(raiz)){
            RegDados m;

            //faz um split do no
            novoNode = split(raiz, &m);
            //cria uma nova raiz
            arvoreB* novaRaiz = criarNode();


            //nova raiz recebe a chave mediana
            novaRaiz->chaves[0] = m;
            //recebe o filho da esquerda da antiga raiz
            novaRaiz->filho[0] = header->raiz;
            novaRaiz->numChaves = 1;

            //o filho da esquerda será a posicao onde o restante do no for inserido
            novaRaiz->filho[1] = escreverNode(bd, header, novoNode);
            //atualiza a nova raiz no header
            header->raiz = escreverNode(bd, header, novaRaiz);

            //libera os nos
            free(novoNode);
            free(novaRaiz);
        }
        //escrever o no no arquivo
        escreverNode(bd, header, raiz);
    }

    //escreve o header no arquivo
    escreverHeader(bd, header);
    //libera a raiz e o header
    free(raiz);
    free(header);
}

/**
 * @brief insere_aux
 * @param bd
 * @param header
 * @param r
 * @param dados
 * @return nenhum
 * @pre a raiz deve existir
 * @post no inserido no arquivo
 */
void insere_aux(FILE *bd, Header *header, arvoreB *r, RegDados dados){

    int pos = 0;
    //busca pela posicao a ser inserida a chve no no
    if(!buscaPos(r, dados.id, &pos)){
        //se for folha
        if(eh_folha(r)){
            //adiciona no no
            adicionaDireita(r, pos, dados, -1);
        }else{
            //se nao for, desce pelos filhos até chegar no nó
            arvoreB* node = lerNode(bd, r->filho[pos]);
            insere_aux(bd, header, node, dados);

            //se o no tiver com overflow
            if(overflow(node)){
                RegDados m;
                //faz um split do no
                arvoreB* aux = split(node, &m);
                //adiciona no no
                adicionaDireita(r, pos, m, escreverNode(bd, header, aux));

                //escreve no arquivo o no
                escreverNode(bd, header, node);

                free(aux);
            }
        }
    }
    //escreve no arquivo o no
    escreverNode(bd, header, r);
}

/**
 * @brief adicionaDireita
 * @param r
 * @param pos
 * @param dados
 * @param p
 * @return nenhum
 * @pre o no deve ser folha
 * @post chave inserido no no
 */
void adicionaDireita(arvoreB *r, int pos, RegDados dados, int p){

    int i;
    //desloca as chaves e os filhos a direita
    for(i = r->numChaves; i > pos; i--){
        r->chaves[i] = r->chaves[i - 1];
        r->filho[i + 1] = r->filho[i];
    }

    //insere os dados no espaco vazio
    r->chaves[pos] = dados;
    r->filho[pos + 1] = p;
    r->numChaves++;
}


/**
 * @brief overflow
 * @param r
 * @return 1 se ocorrer overflow e 0 caso contrario
 * @pre nenhum
 * @post nenhum
 */
int overflow(arvoreB *r){
    //retorna verdadeiro se ocorrer overflow
     return (r->numChaves == ORDEM);
}

/**
 * @brief eh_folha
 * @param r
 * @return 1 se for folha e 0 caso contrario
 * @pre nenhum
 * @post nenhum
 */
int eh_folha(arvoreB *r){
    //retorna verdadeiro se for folha
    return (r->filho[0] == -1);
}


/**
 * @brief split
 * @param r
 * @param m
 * @return no nó
 * @pre no com overflow
 * @post separa o nó em dois mais a raiz
 */
arvoreB* split(arvoreB *r, RegDados *m){

    arvoreB* novoNo = criarNode();
    int i;
    //pega a posicao da chave mediana
    int q = (ORDEM - 1)/2;
    //atribui aos dois nos o numero de chaves
    novoNo->numChaves = q;
    r->numChaves = q;

    //pega a chave da posicao mediana
    *m = r->chaves[q];

    //redistribui as chaves e os filhos
    novoNo->filho[0] = r->filho[q + 1];
    for(i = 0; i < novoNo->numChaves; i++){
        novoNo->chaves[i] = r->chaves[q + i + 1];
        novoNo->filho[i + 1] = r->filho[q + i + 2];
    }
    //retorna o novo no
    return novoNo;
}

/**
 * @brief buscaPos
 * @param r
 * @param info
 * @param pos
 * @return a posicao que deve ser inserido o no
 * @pre nenhum
 * @post nenhum
 */
int buscaPos(arvoreB *r, int info, int *pos){

    //busca a posicao dentro do no
    for((*pos) = 0; (*pos) < r->numChaves; (*pos)++){
        //se a chave ja existir
        if(info == r->chaves[(*pos)].id){
            return 1;
        }else{
            //se a chave n pertencer ao no
            if(info < r->chaves[(*pos)].id){
                return 0;
            }
        }
    }
    return 0;
}


/**
 * @brief printNo
 * @param r
 * @param nenhum
 * @pre nenhum
 * @post nenhum
 */
void printNo(arvoreB* node){
    int i;
    printf("[");
    // se for valida o numero de nos
    if (node->numChaves) {
        for (i = 0; i < node->numChaves - 1; ++i) {
            //printa a chave
            printf(" %d,", node->chaves[i].id);
        }
        printf("%d", node->chaves[node->numChaves - 1].id);
    }
    printf("]");
}
