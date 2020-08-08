#include "playlist.h"
#define MAX 256

Musica *criarMusica(char *nome, char *cantor, char *compositor, int ano, char *genero, double duracao, int avaliacao)
{
    Musica* musica = (Musica*)malloc(sizeof(Musica));

    musica->nome = nome;
    musica->cantor = cantor;
    musica->compositor = compositor;
    musica->ano = ano;
    musica->genero = genero;
    musica->duracao = duracao;
    musica->avaliacao = avaliacao;

    return musica;
}

void criarMusicaUi()
{
    Musica *novaMusica;
    char nomecantor[MAX], nomemusica[MAX], nomecompositor[MAX], nomegenero[MAX];
    double duracaomusica;
    int ano, avaliacaomusica;

    printf("\n             Digite o nome da Musica:\n             ");
    scanf(" %s", nomemusica);
    getchar();
    printf("             Digite o nome do Cantor:\n             ");
    scanf(" %s", nomecantor);
    getchar();
    printf("             Digite o nome do compositor:\n             ");
    scanf(" %s", nomecompositor);
    getchar();
    printf("             Digite o genero da musica:\n             ");
    scanf(" %s", nomegenero);
    getchar();
    printf("             Digite a duracao da musica:\n             ");
    scanf("%lf", &duracaomusica);
    getchar();
    printf("             Digite o ano da musica\n             ");
    scanf("%d", &ano);
    getchar();
    printf("             Avalie esta musica (0 a 5):\n             ");
    scanf("%d", &avaliacaomusica);
    getchar();

    novaMusica = criarMusica(nomemusica, nomecantor, nomecompositor, ano, nomegenero, duracaomusica, avaliacaomusica);

    system("cls");

    printf("             | MUSICAS |\n\n");
    printf("             Musica: %s\n"
           "             Cantor: %s\n"
           "             Compositor: %s\n"
           "             Genero: %s\n"
           "             Duracao: %g\n"
           "             Ano: %d\n"
           "             Avaliacao: %d\n",
           nomemusica, nomecantor, nomecompositor, nomegenero,
           duracaomusica, ano, avaliacaomusica);


    int x;
    printf("\n\n             Musica criada com Sucesso!\n");
    printf("\n             1 -> Salvar\n"
           "             2 -> Descartar\n\n             ");
    scanf("%d", &x);
    if(x == 1){
        printf("             1 -> PlayList Existente\n"
               "             2 -> Criar Nova PlayList\n             ");
        int x2;
        scanf("%d", &x2);
        if(x2 == 1){
            //encontrarPlayList();
        }else if(x2 == 2){
            CriarNovaPlaylist();
        }
    }else if(x == 2){
        printf("             1 -> Voltar ao Menu Principal\n"
               "             2 -> Sair do aplicativo\n             ");
        int x3;
        scanf("%d", &x3);
        if(x3 == 1){
            menuInicial();
        }else if(x3 == 2){
            printf("Volte Sempre!\n :D");
            exit(0);
        }
    }
}
ListaMusica *criarLista(){
    return NULL;
}

int vazia (ListaMusica *lista){
    return !lista;
}

ListaMusica *inserirMusicaPlaylist(ListaMusica *lista, Musica *mus)
{
    if(vazia(lista)){
        ListaMusica *newListaMusica = (ListaMusica*)malloc(sizeof(ListaMusica));
        newListaMusica->musica = mus;
        newListaMusica->prox = NULL;
        return newListaMusica;
    }else{
        lista->prox = inserirMusicaPlaylist(lista->prox, mus);
        return lista;
    }
}

void imprimirListaMusica(ListaMusica *lista)
{
    if(vazia(lista))
        printf("NULL\n\n");
    else{
        printf("%s\n", lista->musica->nome);
    }
}

Playlist *CriarNovaPlaylist()
{
    char nomeTitulo[MAX], nomeProprietario[MAX];

    printf("\nTitulo da PlayList:\n ");
    scanf("%s", nomeTitulo);
    printf("Proprietario:\n");
    scanf("%s", nomeProprietario);

    Playlist *nova = (Playlist*)malloc(sizeof(Playlist));
    nova->titulo = nomeTitulo;
    nova->proprietario = nomeProprietario;

    return nova;
}

// Todos que tem User Interface serao aqueles chamados no menu inicial
// E comunica com o usuario
void duracaoTotalPlaylistUi()
{
    char nomePlaylist[MAX];

    printf("Digite o nome da PlayList que deseja pesquisar:\n");
    scanf("%s", nomePlaylist);

    duracaoTotalPlaylist(nomePlaylist);

    // inacabado
}

void duracaoTotalPlaylist(Playlist *playlist)
{
    double c = 0;
    int i;
    for(i =  0; i < TAM; i++){
        c += playlist->lista[i].duracao;
     }
    printf("\nDuracao total da Playlist %s: %.2lf minutos. \n", playlist->titulo, c);
}

void menuInicial()
{
    int opcao;

    system("cls");
    printf("         ______________________________________________________\n"
           "        |                                                      |\n"
           "        |                      BEM-VINDO                       |\n"
           "        |______________________________________________________|\n");


    printf("\n                          | MENU PRINCIPAL | \n\n");

    printf("                            1 -> PlayList\n"
           "                            2 -> Musicas\n"
           "                            3 -> Sair\n");
    printf("\n\n\n\n                                                  R&G Company\n");

    printf("\n\n                            >");

    scanf("%d", &opcao);

    if(opcao == 1){
        system("cls");
        int opcaoPl;
        printf("                        | PLAYLIST |\n\n");
        printf("             O que deseja fazer? Escolha uma das opcoes...\n\n\n");
        printf("             1 -> Listar todas PlayList\n"
               "             2 -> Consultar uma PlayList\n"
               "             3 -> Criar nova Playlist\n"
               "             4 -> Avaliar PlayList\n"
               "             5 -> Editar Playlist\n"
               "             6 -> Excluir PlayList\n"
               "             7 -> Ranking das Melhores PlayList\n"
               "             8 -> Duracao Total de uma Playlist\n"
               "             9 -> Voltar ao Menu Principal\n\n"
               "             ");
        scanf("%d", &opcaoPl);
        printf("\n");
        switch (opcaoPl)
        {
//        case 1: ListarTodasPlaylist(); break;
//        case 2: ConsultarPlaylist(); break;
        case 3: ;
            Playlist* playlist = NULL;
            playlist = CriarNovaPlaylist();
            break;
//        case 4: AvaliarPlayList(); break;
//        case 5: EditarPlaylist(); break;
//        case 6: ExcluirPlaylist(); break;
//        case 7: RankingPlayList(); break;
        case 8: duracaoTotalPlaylistUi(); break;
          case 9: menuInicial();
        }
    }else if( opcao == 2){
        system("cls");
        int opcaoMs;
        printf("                        | MUSICAS |\n\n");
        printf("             O que deseja fazer? Escolha uma das opcoes...\n\n\n");
        printf("             1 -> Lista de todas musicas de uma PlayList\n"
               "             2 -> Consultar uma Musica\n"
               "             3 -> Criar nova Musica\n"
               "             4 -> Avaliar Musica\n"
               "             5 -> Editar Musica\n"
               "             6 -> Excluir Musica\n"
               "             7 -> Ranking das Melhores Musicas\n"
               "             8 -> Voltar ao Menu Principal\n\n"
               "             ");
        scanf("%d", &opcaoMs);
        switch (opcaoMs)
        {
//        case 1: ListarTodasMusicas(); break;
//        case 2: ConsultarMusica(); break;
        case 3:
            criarMusicaUi(); break;
//        case 4: AvaliarMusica(); break;
//        case 5: EditarMusica(); break;
//        case 6: ExcluirMusica(); break;
//        case 7: RankingMusica(); break;
          case 8: menuInicial();
        }
    }else if (opcao == 3){
        system("cls");
        int opcaoSair;
        printf("Deseja sair do Aplicativo? (S = 1/N = 0)\n");
        scanf("%d", &opcaoSair);
        switch (opcaoSair) {
        case 0: menuInicial();
        case 1: printf("\n\nAte a Proxima!!!\n\n"); exit(0);
        }

    }
}









///Funçoes antigas:

//Playlist *inserirMusica(Playlist *playlist, Musica *musica)
//{
//    int i;
//    if(playlist == NULL){
//        Playlist* novo = (Playlist*)malloc(sizeof(Playlist));
//        for(i = 0; i < TAM; i++){
//            if(!novo->lista[i].nome){
//                novo->lista[i] = *musica;
//                return novo;
//            }
//        }
//    }else{
//        for(i = 0; i < TAM; i++){
//            if(!playlist->lista[i].nome){
//                playlist->lista[i] = *musica;
//                return playlist;
//            }
//        }
//    }

//    printf("Playlist Cheia!\n");
//    return playlist;
//}

//Playlist *removerMusica(Playlist *playlist, Musica *musica)
//{
//    int i;
//    if(playlist == NULL){
//        printf("Essa Playlist nao Existe\n\n");
//        return NULL;
//    }else
//        for(i = 0; i < TAM; i++){
//            if(!strcmp(playlist->lista[i].nome, musica->nome)){
//                playlist->lista[i].nome = NULL;
//                musica  = NULL;
//            }
//        }
//    return playlist;
//}


//Musica zerar(Musica musica)
//{
//    printf("zerar\n");
//    musica.ano = 0;
//    musica.avaliacao = 0;
//    musica.cantor = NULL;
//    musica.compositor = NULL;
//    musica.duracao = 0.0;
//    musica.genero = NULL;
//    musica.nome = NULL;

//    return musica;
//}


//Playlist *criarPlaylist(char *titulo, char *proprietario)
//{
//    Playlist* playlist = (Playlist*)malloc(sizeof(Playlist));

//    playlist->proprietario = proprietario;
//    playlist->titulo = titulo;

//    return playlist;
//}


//void listaMusica(Playlist *playlist)
//{
//    int i;

//    printf("Titulo: %s\t Proprietario: %s\n\n", playlist->titulo, playlist->proprietario);


//    for(i = 0; i < TAM; i++){
//        if(playlist->lista[i].nome){
//            printf("Nome: %s\nCantor: %s\n\n",
//                   playlist->lista[i].nome,
//                   playlist->lista[i].cantor);
//        }
//    }
//}


//Playlist *removerplaylist(Playlist *playlist)
//{
//    if(playlist == NULL){
//        printf("Playlist Inexistente!\n");
//    }else{
//        playlist = NULL;
//    }

//    return NULL;

//}


//void consultaMusica(Playlist* playlist)
//{
//    int i;
//    char nomeMusica[100];
//    printf("\n\nInsera o nome da musica para consulta: \n");
//    gets(nomeMusica);
//    fflush(stdin);

//    for( i = 0; i < TAM; i++){
//        if(!strcmp(playlist->lista[i].nome, nomeMusica)){
//            printf("Nome: %s\nCantor: %s\nCompisitor: %s\nAno: %d\nGenero: %s\nDuracao: %.2lf\nAvaliacao: %d\n\n",
//                   playlist->lista[i].nome,
//                   playlist->lista[i].cantor,
//                   playlist->lista[i].compositor,
//                   playlist->lista[i].ano,
//                   playlist->lista[i].genero,
//                   playlist->lista[i].duracao,
//                   playlist->lista[i].avaliacao);
//            return;
//        }
//    }
//    printf("Musica inexistente na playlist!\n");

//}


//void avaliar(Playlist *playlist, Musica *musica)
//{
//    int i, nota;

//    printf("Musica '%s':", musica->nome);
//    scanf("%d", &nota);

//    for(i = 0; i < TAM; i++){
//        if(!strcmp(playlist->lista[i].nome, musica->nome)){
//            if(nota <= 5){
//                playlist->lista[i].avaliacao = nota;
//                return;
//            }else
//                printf("Nota invalida\n");
//        }
//    }

//}

//void duracaoTotalPlaylist(Playlist *playlist)
//{
//    double c = 0;
//    int i;
//    for(i =  0; i < TAM; i++){
//        c += playlist->lista[i].duracao;
//     }
//    printf("\nDuracao total da Playlist %s: %.2lf minutos. \n", playlist->titulo, c);
//}


//void rankingPlaylist(Playlist *playlist, int tamanho )
//{
//    Playlist *aux;
//    int menor, i, j;

//    for(i = 0; i < (tamanho - 1); i++){

//        menor = i;

//        for(j = i+1; j < tamanho; j++)
//            if(playlist->lista[j].avaliacao < playlist->lista[menor].avaliacao)
//                menor = j;

//        if( i != menor)
//        {
//            aux = playlist->lista[i].avaliacao;
//            playlist->lista[i].avaliacao = playlist->lista[menor].avaliacao;
//            playlist->lista[menor].avaliacao = aux;
//        }

//        for(i = 0; i < tamanho; i++)
//        {
//            printf("\n\n%s: %d\n", playlist->lista[i].nome, playlist->lista[i].avaliacao);
//        }
//    }

//}



//void printarRanking (Playlist *playlist)
//{
//     int i;
//     printf("\n\n");
//     for(i = 0; i < TAM; i++){
//           printf("%d: %s\n", i ,  playlist->lista[i].nome);
//    }
//}



//void consultaPlaylist(Playlist *playlist)
//{

//}
