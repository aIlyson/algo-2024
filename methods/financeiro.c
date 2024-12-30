#include <stdio.h>
#include <string.h>
#include "financeiro.h"

// funcoes
#include <stdio.h>
#include "financeiro.h"

// Calcula o valor total do estoque (baseado no preco de compra e quantidade disponivel)
float calcularValorTotalEstoque(struct Anime estoque[], int totalAnimes) {
    float valorTotal = 0.0;

    for (int i = 0; i < totalAnimes; i++) {
        valorTotal += estoque[i].precodecompra * (float)estoque[i].quantidadeBluRay;
    }

    return valorTotal;
}

// Calcula o lucro potencial estimado (baseado no preco de venda, compra e quantidade disponivel)
float calcularLucroPotencial(struct Anime estoque[], int totalAnimes) {
    float lucroTotal = 0.0;

    for (int i = 0; i < totalAnimes; i++) {
        float lucroPorUnidade = estoque[i].precodevenda - estoque[i].precodecompra;
        lucroTotal += lucroPorUnidade * (float)estoque[i].quantidadeBluRay;
    }

    return lucroTotal;
}

// Gera um relatorio financeiro com o valor total do estoque e lucro potencial
void gerarRelatorioFinanceiro(struct Anime estoque[], int totalAnimes) {
    printf("\n*** RELATORIO FINANCEIRO ***\n");

    float valorTotal = calcularValorTotalEstoque(estoque, totalAnimes);
    float lucroPotencial = calcularLucroPotencial(estoque, totalAnimes);

    printf("Valor total do estoque: R$ %.2f\n", valorTotal);
    printf("Lucro potencial estimado: R$ %.2f\n", lucroPotencial);

    printf("=======================================\n");
    printf("Produtos detalhados:\n");
    for (int i = 0; i < totalAnimes; i++) {
        printf("- %s (ID: %d):\n", estoque[i].nome, estoque[i].IDanime);
        printf("  Preco de Compra: R$ %.2f\n", estoque[i].precodecompra);
        printf("  Preco de Venda: R$ %.2f\n", estoque[i].precodevenda);
        printf("  Quantidade em Estoque: %d\n", estoque[i].quantidadeBluRay);
        printf("  Lucro Potencial: R$ %.2f\n", 
            (estoque[i].precodevenda - estoque[i].precodecompra) * (float)estoque[i].quantidadeBluRay);
        printf("---------------------------------------\n");
    }
}
// Função para realizar uma venda de um produto (anime)
void realizarVenda(struct Anime estoque[], int totalAnimes, int idAnime, int quantidadeVendida) {
    // Procurar o anime pelo ID
    int encontrado = 0;
    for (int i = 0; i < totalAnimes; i++) {
        if (estoque[i].IDanime == idAnime) {
            // Verificar se há quantidade suficiente para a venda
            if (estoque[i].quantidadeBluRay >= quantidadeVendida) {
                // Atualizar o estoque
                estoque[i].quantidadeBluRay -= quantidadeVendida;
                
                // Calcular o valor da venda
                float valorVenda = estoque[i].precodevenda * (float)quantidadeVendida;
                
                // Exibir o resultado da venda
                printf("Venda realizada com sucesso!\n");
                printf("Produto: %s\n", estoque[i].nome);
                printf("Quantidade vendida: %d\n", quantidadeVendida);
                printf("Valor da venda: R$ %.2f\n", valorVenda);
                printf("Quantidade restante em estoque: %d\n", estoque[i].quantidadeBluRay);
            } else {
                printf("Erro: Quantidade insuficiente em estoque.\n");
            }
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Erro: Produto não encontrado.\n");
    }
}
