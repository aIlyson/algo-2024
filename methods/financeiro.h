#ifndef FINANCEIRO_H
#define FINANCEIRO_H
#include "estoque.h" // inclui o arquivo estoque.h para usar a estrutura Anime

// funções
float calcularValorEstoque(struct Anime estoque[], int totalAnimes);
float calcularLucroPotencial(struct Anime estoque[], int totalAnimes);
void realizarVenda(struct Anime estoque[], int totalAnimes, int idAnime, int quantidadeVendida);
void consultarCaixa();
void gerarRelatorioFinanceiro(struct Anime estoque[], int totalAnimes);

#endif