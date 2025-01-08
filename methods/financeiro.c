#include <stdio.h>
#include <string.h>
#include "financeiro.h" // inclui o arquivo financeiro.h para usar a estrutura Anime

// variáveis globais
float vendas[100];   // vetor para armazenar as vendas
int totalVendas = 0; // contador de vendas

// funções
float calcularValorEstoque(struct Anime estoque[], int totalAnimes) // calcula o valor total do estoque
{
    float valorTotal = 0.0;
    for (int i = 0; i < totalAnimes; i++)
    {
        valorTotal += estoque[i].precodecompra * (float)estoque[i].quantidadeBluRay;
    }

    return valorTotal;
}

float calcularLucroPotencial(struct Anime estoque[], int totalAnimes) // calcula o lucro potencial estimado
{
    float lucroTotal = 0.0;
    for (int i = 0; i < totalAnimes; i++)
    {
        float lucroPorUnidade = estoque[i].precodevenda - estoque[i].precodecompra; // calcula o lucro por unidade
        lucroTotal += lucroPorUnidade * (float)estoque[i].quantidadeBluRay;         // calcula o lucro total
    }

    return lucroTotal;
}

void contarestoqueVazio(struct Anime estoque[], int totalAnimes)
{
    int vazio = 0;

    // imprime os animes com estoque vazio
    printf("Animes com estoque vazio:\n");

    // busca pelos animes com estoque vazio
    for (int i = 0; i < totalAnimes; i++)
    {
        if (estoque[i].quantidadeBluRay == 0)
        {
            printf("- %s\n", estoque[i].nome);
            vazio++;
        }
    }

    if (vazio == 0)
    {
        printf("- Nenhum anime com estoque vazio.\n");
    }
    else
    {
        printf("Total: %d\n", vazio);
    }
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

                // calcula o valor da venda
                float valorVenda = estoque[i].precodevenda * (float)quantidadeVendida;

                if (totalVendas < 100) // verifica o limite do vetor
                {
                    vendas[totalVendas] = valorVenda; // adiciona a venda no vetor
                    totalVendas++;                    // incrementa o contador
                }
                else
                {
                    printf("ERRO... Limite de vendas atingido!\n");
                }

                printf("\nVenda realizada!\n");
                printf("====================================\n");
                printf("Produto: %s\n", estoque[i].nome);
                printf("Quantidade vendida: %d\n", quantidadeVendida);
                printf("Valor da venda: R$ %.2f\n", valorVenda);
                printf("Quantidade restante em estoque: %d\n", estoque[i].quantidadeBluRay);
                printf("====================================\n");
            }
            else
            {
                printf("ERRO... Nao ha quantidade suficiente no anime.\n");
            }
            break;
        }
    }

    if (!encontrado)
    {
        printf("Nenhum anime encontrado com o ID.\n");
    }
}

void consultarCaixa()
{
    float totalCaixa = 0.0;

    // verifica se o caixa esta vazio
    if (totalVendas == 0)
    {
        printf("Nenhuma venda realizada! Caixa vazio.\n");
        return;
    }

    printf("\nConsulta de Caixa:\n");
    printf("============================================================\n");

    // calcula o valor total
    for (int i = 0; i < totalVendas; i++)
    {
        totalCaixa += vendas[i];
    }

    printf("Valor total em caixa: R$ %.2f\n", totalCaixa);
    printf("====================================\n");
}

void gerarRelatorioFinanceiro(struct Anime estoque[], int totalAnimes)
{
    printf("\nRelatorio de Financas:\n");
    printf("============================================================\n");

    // exibe os valores gerais do estoque
    float valorTotal = calcularValorEstoque(estoque, totalAnimes);
    float lucroPotencial = calcularLucroPotencial(estoque, totalAnimes);

    printf("Valor total do estoque: R$ %.2f\n", valorTotal);
    printf("Lucro potencial estimado: R$ %.2f\n", lucroPotencial);
    contarestoqueVazio(estoque, totalAnimes);
    int totalBluRays = 0; // verifica se o estoque INTEIRO de Blu-rays esta vazio
    for (int i = 0; i < totalAnimes; i++)
    {
        totalBluRays += estoque[i].quantidadeBluRay;
    }
    if (totalBluRays == 0)
    {
        printf("AVISO... Nao ha Blu-rays no estoque!\n");
    }
    printf("============================================================\n");

    // cabeçalho
    printf("ID || Nome || Preco Compra || Preco Venda || Quantidade || Lucro Potencial\n");
    printf("------------------------------------------------------------\n");

    // imprime os produtos
    for (int i = 0; i < totalAnimes; i++)
    {
        float lucroProduto = (estoque[i].precodevenda - estoque[i].precodecompra) * (float)estoque[i].quantidadeBluRay; // calcula o lucro

        printf("%d || %s || R$ %.2f Reais || R$ %.2f Reais || %d Unidades || R$ %.2f\n",
               estoque[i].IDanime,
               estoque[i].nome,
               estoque[i].precodecompra,
               estoque[i].precodevenda,
               estoque[i].quantidadeBluRay,
               lucroProduto);
    }
}