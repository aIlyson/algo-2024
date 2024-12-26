#ifndef ESTOQUE_H
#define ESTOQUE_H

// TODO: estrutura de animes
// template para os animes gerado pelo codeium, vamos editar depois
struct Anime {
    char nome[100];
    int quantidadeBluRay;
    int codigo;
    float precocompra;
    float precovenda;
    
};

// função para os animes fica abaixo
// ...
void cadastrarAnime(struct Anime estoque[], int *totalAnimes);
int consultarAnime(struct Anime estoque[], int totalAnimes);
void editarAnime(struct Anime estoque[], int totalAnimes);
void atualizarEstoque(struct Anime estoque[], int totalAnimes, int codigo, int quantidade, int entrada);
void removerAnime(struct Anime estoque[], int *totalAnimes);
void gerarRelatorio(struct Anime estoque[], int totalAnimes);
#endif
