#ifndef FINANCEIRO_H
#define FINANCEIRO_H

// funções
#include "estoque.h"

// Funções para cálculos financeiros
float calcularValorTotalEstoque(struct Anime estoque[], int totalAnimes);
float calcularLucroPotencial(struct Anime estoque[], int totalAnimes);
void gerarRelatorioFinanceiro(struct Anime estoque[], int totalAnimes);
void realizarVenda(struct Anime estoque[], int totalAnimes, int idAnime, int quantidadeVendida);
#endif
