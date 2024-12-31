#include <stdio.h>
#include <string.h>
#include "financeiro.h"

// funções
float calcularValorEstoque(struct Anime estoque[], int totalAnimes)
{
    float valorTotal = 0.0;
    for (int i = 0; i < totalAnimes; i++)
    {
        valorTotal += estoque[i].precodecompra * estoque[i].quantidadeBluRay;
    }

    return valorTotal;
}

float calcularLucroPotencial(struct Anime estoque[], int totalAnimes)
{
    float lucroTotal = 0.0;
    for (int i = 0; i < totalAnimes; i++)
    {
        float lucroPorUnidade = estoque[i].precodevenda - estoque[i].precodecompra;
        lucroTotal += lucroPorUnidade * estoque[i].quantidadeBluRay;
    }

    return lucroTotal;
}

int contarestoqueVazio(struct Anime estoque[], int totalAnimes)
{
    int vazio = 0;
    for (int i = 0; i < totalAnimes; i++)
    {
        if (estoque[i].quantidadeBluRay == 0)
        {
            vazio += 1;
        }
    }

    return vazio;
}

void realizarVenda(struct Anime estoque[], int totalAnimes, int idAnime, int quantidadeVendida)
{
    int encontrado = 0;

    // busca pelo ID
    for (int i = 0; i < totalAnimes; i++)
    {
        if (estoque[i].IDanime == idAnime)
        {
            encontrado = 1;

            // verifica se tem estoque
            if (estoque[i].quantidadeBluRay >= quantidadeVendida)
            {
                estoque[i].quantidadeBluRay -= quantidadeVendida; // diminui a quantidade em estoque

                // calcula o valor e exibe detalhes da venda
                float valorVenda = estoque[i].precodevenda * quantidadeVendida;

                printf("\nVenda realizada!\n");
                printf("Produto: %s\n", estoque[i].nome);
                printf("Quantidade vendida: %d\n", quantidadeVendida);
                printf("Valor da venda: R$ %.2f\n", valorVenda);
                printf("Quantidade restante em estoque: %d\n", estoque[i].quantidadeBluRay);
            }
            else
            {
                printf("Erro... Nao ha quantidade suficiente no anime.\n");
            }
            break;
        }
    }

    if (!encontrado)
    {
        printf("Nenhum anime encontrado com o ID.\n");
    }
}

void gerarRelatorioFinanceiro(struct Anime estoque[], int totalAnimes)
{
    // verifica se o estoque esta vazio
    if (totalAnimes == 0)
    {
        printf("Nao ha animes cadastrados!\n");
        return;
    }

    printf("\n*** Relatorio Financeiro ***\n");
    printf("============================================================\n");

    // exibe os valores gerais do estoque
    float valorTotal = calcularValorEstoque(estoque, totalAnimes);
    float lucroPotencial = calcularLucroPotencial(estoque, totalAnimes);
    int estoqueVazio = contarestoqueVazio(estoque, totalAnimes);

    printf("Valor total do estoque: R$ %.2f\n", valorTotal);
    printf("Lucro potencial estimado: R$ %.2f\n", lucroPotencial);
    printf("Estoque vazio: %d\n", estoqueVazio);
    printf("============================================================\n");

    // cabeçalho
    printf("ID || Nome || Preco Compra || Preco Venda || Quantidade || Lucro Potencial\n");
    printf("------------------------------------------------------------\n");

    // imprime os produtos
    for (int i = 0; i < totalAnimes; i++)
    {
        float lucroProduto = (estoque[i].precodevenda - estoque[i].precodecompra) * estoque[i].quantidadeBluRay;

        printf("%d || %s || R$ %.2f || R$ %.2f || %d || R$ %.2f\n",
               estoque[i].IDanime,
               estoque[i].nome,
               estoque[i].precodecompra,
               estoque[i].precodevenda,
               estoque[i].quantidadeBluRay,
               lucroProduto);
    }
}