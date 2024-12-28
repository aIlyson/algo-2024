#ifndef ESTOQUE_H
#define ESTOQUE_H

// estrutura de animes
struct Anime
{
    char nome[100];
    int quantidadeBluRay;
    int codigo;
    float precocompra;
    float precovenda;
    
};

// funções
void cadastrarAnime(struct Anime estoque[], int *totalAnimes);
int consultarAnime(struct Anime estoque[], int totalAnimes);
void editarAnime(struct Anime estoque[], int totalAnimes);
void atualizarEstoque(struct Anime estoque[], int totalAnimes, int codigo, int quantidade, int entrada);
void removerAnime(struct Anime estoque[], int *totalAnimes);
void gerarRelatorio(struct Anime estoque[], int totalAnimes);
<<<<<<< HEAD

#endif
=======
void realizarvenda(struct Anime estoque[],int totalAnimes,float *caixa);
#endif
>>>>>>> 961c6f9dabcce4be2f0148f19eff99b45dc97c3d
