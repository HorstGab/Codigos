#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

struct Musica{
    char* nome;
    char* cantor;
    char* compositor;
    int ano;
    char* genero;
    double duracao;
    int avaliacao;
};

typedef struct Musica Musica;

struct Playlist{
    char* titulo;
    char* proprietario;
    Musica lista[TAM];
};

typedef struct Playlist Playlist;

struct No{
    Playlist *playlist;
    Musica *musica;
    struct No *prox;
};

typedef struct No ListaMusica;

void menuInicial();

ListaMusica *criarLista();
void imprimirListaMusica(ListaMusica *lista);
ListaMusica *inserirMusicaPlaylist(ListaMusica *lista, Musica *mus);


Playlist* criarPlaylist(char* titulo, char* proprietario);
Playlist* removerplaylist(Playlist* playlist);

Musica zerar(Musica musica);
Musica* criarMusica(char* nome, char* cantor, char* compositor, int ano, char* genero, double duracao, int avaliacao);
Playlist* inserirMusica(Playlist* playlist, Musica* musica);
Playlist* removerMusica(Playlist* playlist, Musica* musica);
Playlist *CriarNovaPlaylist();

void listaMusica(Playlist* playlist);
void consultaMusica(Playlist *playlist);
void printarRanking (Playlist *playlist);
void todasPlaylist(Playlist *playlist[]);
void consultaPlaylist(Playlist *playlist);
void duracaoTotalPlaylist(Playlist *playlist);
void avaliar(Playlist *playlist, Musica* musica);
void rankingPlaylist(Playlist *playlist, int tamanho);

#endif // PLAYLIST_H

