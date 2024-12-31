#include <stdio.h>
#include <stdlib.h>
#include "methods/estoque.h"
#include "methods/financeiro.h"

int main()
{
    struct Anime estoque[100];
    int totalAnimes = 0;
    int op, subOp;

    do
    {
        printf("\n*** MENU PRINCIPAL ***\n");
        printf("=======================================\n");
        printf("0. Sair\n");
        printf("1. Gerenciar estoque de animes\n");
        printf("2. Gerenciar vendas de animes\n");
        printf("=======================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        switch (op)
        {
        case 0:
            // sair do programa
            printf("Saindo...\n");
            break;

        case 1:
            do
            {
                printf("\n*** MENU DE GESTAO DE ESTOQUE DE ANIMES ***\n");
                printf("============================================\n");
                printf("0. Voltar ao menu principal\n");
                printf("1. Adicionar anime\n");
                printf("2. Consultar anime\n");
                printf("3. Editar anime\n");
                printf("4. Atualizar estoque de Blu-rays\n");
                printf("5. Remover anime do estoque\n");
                printf("6. Gerar relatorio do estoque\n");
                printf("============================================\n");
                printf("Escolha uma opcao: ");
                scanf("%d", &subOp);

                switch (subOp)
                {
                case 0:
                    // voltar ao menu principal
                    printf("Voltando ao menu principal...\n");
                    system("cls");
                    break;

                case 1:
                    // cadastrar anime
                    printf("Adicionando anime...\n");

                    char opcao;
                    while (opcao != 'n')
                    {
                        totalAnimes = cadastrarAnime(estoque, totalAnimes); // atualiza 'totalAnimes'

                        printf("Deseja cadastrar outro anime? (s/n): ");
                        scanf(" %c", &opcao);
                    }
                    system("cls");
                    break;

                case 2:
                    // consultar anime
                    printf("Consultando anime...\n");

                    do
                    {
                        if (consultarAnime(estoque, totalAnimes) != 0)
                        {
                            break;
                        }

                        printf("Deseja consultar outro anime? (s/n): ");
                        scanf(" %c", &opcao);
                    } while (opcao == 's');
                    system("cls");
                    break;

                case 3:
                    // editar anime
                    printf("Editando anime...\n");
                    char continuar;

                    // verifica se tem animes antes
                    if (totalAnimes == 0)
                    {
                        printf("Nao ha animes cadastrados! Nada para editar.\n");
                    }
                    else
                    {
                        do
                        {
                            editarAnime(estoque, totalAnimes);
                            printf("Deseja editar outro anime? (s/n): ");
                            scanf(" %c", &continuar);
                        } while (continuar != 'n');
                    }
                    break;

                case 4:
                    // atualizar estoque
                    printf("Atualizar estoque de Blu-rays:\n");
                    printf("1. Entrada de Blu-rays\n");
                    printf("2. Saida de Blu-rays\n");

                    int escolha, codigo, quantidade;
                    scanf("%d", &escolha);

                    printf("Digite o codigo do anime: ");
                    scanf("%d", &codigo);
                    printf("Digite a quantidade: ");
                    scanf("%d", &quantidade);

                    if (escolha == 1)
                    {
                        atualizarEstoque(estoque, totalAnimes, codigo, quantidade, 1);
                    }
                    else if (escolha == 2)
                    {
                        atualizarEstoque(estoque, totalAnimes, codigo, quantidade, 0);
                    }
                    else
                    {
                        printf("Error... Opcao invalida!\n");
                    }
                    break;

                case 5:
                    // remover anime
                    printf("Removendo anime...\n");

                    // verifica se tem animes antes
                    if (totalAnimes == 0)
                    {
                        printf("Nao ha animes cadastrados! Nada para remover.\n");
                    }
                    else
                    {
                        do
                        {
                            totalAnimes = removerAnime(estoque, totalAnimes);

                            // verifica se tem animes restantes
                            if (totalAnimes > 0)
                            {
                                printf("Animes restantes no estoque: %d\n", totalAnimes);
                                printf("Deseja remover outro anime? (s/n): ");
                                scanf(" %c", &continuar);
                            }
                            else
                            {
                                printf("Nao ha animes cadastrados! Nada para remover.\n");
                                continuar = 'n';
                            }
                        } while (continuar != 'n');
                    }
                    break;

                case 6:
                    // gerar relatório
                    printf("Gerando relatorio de estoque...\n");
                    gerarRelatorio(estoque, totalAnimes);
                    break;

                default:
                    printf("Error... Opcao invalida!\n");
                    break;
                }
            } while (subOp != 0); // volta ao menu principal
            break;

        case 2:
            do
            {
                printf("\n*** MENU DE GESTAO FINANCEIRO ***\n");
                printf("====================================\n");
                printf("0. Voltar ao menu principal\n");
                printf("1. Realizar venda\n");
                printf("2. Gerar relatorio de financeiro\n");
                printf("====================================\n");
                printf("Escolha uma opcao: ");
                scanf("%d", &subOp);

                switch (subOp)
                {
                case 0:
                    // voltar ao menu principal
                    printf("Voltando ao menu principal...\n");
                    system("cls");
                    break;

                case 1:
                    // realizar venda
                    printf("Realizando venda...\n");
                    realizarVenda(estoque, totalAnimes, 0, 0);
                    break;

                case 2:
                    // gerar relatório
                    printf("Gerando relatorio de vendas...\n");
                    gerarRelatorioFinanceiro(estoque, totalAnimes);
                    break;

                default:
                    printf("Error... Opcao invalida!\n");
                    break;
                }
            } while (subOp != 0); // volta ao menu principal
            break;

        default:
            printf("Error... Opcao invalida!\n");
            break;
        }
    } while (op != 0); // encerra o programa

    return 0;
}