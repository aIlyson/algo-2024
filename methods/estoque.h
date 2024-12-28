#ifndef ESTOQUE_H
#define ESTOQUE_H

// estrutura de animes
struct Anime
{
    char nome[100];
    int quantidadeBluRay;
    int codigo;
};

// funções
void cadastrarAnime(struct Anime estoque[], int *totalAnimes);
int consultarAnime(struct Anime estoque[], int totalAnimes);
void editarAnime(struct Anime estoque[], int totalAnimes);
void atualizarEstoque(struct Anime estoque[], int totalAnimes, int codigo, int quantidade, int entrada);
void removerAnime(struct Anime estoque[], int *totalAnimes);
void gerarRelatorio(struct Anime estoque[], int totalAnimes);

#endif
