#ifndef ESTOQUE_H
#define ESTOQUE_H

// estrutura de animes
struct Anime
{
    int IDanime;
    char nome[100];
    char genero[100];
    float preco;
    int quantidadeBluRay;
};

// funções
int cadastrarAnime(struct Anime estoque[], int totalAnimes);
int consultarAnime(struct Anime estoque[], int totalAnimes);
void editarAnime(struct Anime estoque[], int totalAnimes);
void atualizarEstoque(struct Anime estoque[], int totalAnimes, int codigo, int quantidade, int entrada);
int removerAnime(struct Anime estoque[], int totalAnimes);
void gerarRelatorio(struct Anime estoque[], int totalAnimes);

#endif
