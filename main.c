#include <stdio.h>
#include <stdlib.h>
#include "methods/estoque.h"

int main()
{
    struct Anime estoque[100];
    int totalAnimes = 0;
    int op, subOp;

    do
    {
        printf("\n*** MENU PRINCIPAL ***\n");
        printf("-------------------------------------------\n");
        printf("1. Gerenciar estoque de animes\n");
        printf("2. Sair\n");
        printf("-------------------------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            do
            {
                printf("\n*** MENU DE GESTAO DE ESTOQUE DE ANIMES ***\n");
                printf("--------------------------------------------\n");
                printf("1. Adicionar anime\n");
                printf("2. Consultar anime\n");
                printf("3. Editar anime\n");
                printf("4. Atualizar estoque de Blu-rays\n");
                printf("5. Remover anime do estoque\n");
                printf("6. Gerar relatorio do estoque\n");
                printf("7. Voltar ao menu principal\n");
                printf("--------------------------------------------\n");
                printf("Escolha uma opcao: ");
                scanf("%d", &subOp);

                switch (subOp)
                {
                case 1:
                    // cadastrar anime
                    printf("Adicionando anime...\n");

                    char opcao;
                    while (opcao != 'n')
                    {
                        // A função 'cadastrarAnime' agora retorna o novo valor de 'totalAnimes'.
                        // assim, precisamos capturar esse valor retornado e atualizá-lo,
                        // pois 'totalAnimes' foi passado por valor para a função, e ela retorna
                        // o valor atualizado de 'totalAnimes' após o cadastro do anime.
                        totalAnimes = cadastrarAnime(estoque, totalAnimes); // atualiza 'totalAnimes' com o valor retornado
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
                        // verifica se o estoque esta vazio
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
                    do
                    {
                        editarAnime(estoque, totalAnimes);
                        printf("Deseja editar outro anime? (s/n): ");
                        scanf(" %c", &continuar);
                    } while (continuar != 'n');
                    system("cls");
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
                        printf("error... Numero invalido\n");
                    }
                    system("cls");
                    break;

                case 5:
                    // remover anime
                    printf("Removendo anime...\n");

                    do
                    {
                        totalAnimes = removerAnime(estoque, totalAnimes);
                        printf("Deseja remover outro anime? (s/n): ");
                        scanf(" %c", &continuar);
                    } while (continuar != 'n');
                    system("cls");
                    break;

                case 6:
                    // gerar relatório
                    printf("Gerando relatorio de estoque...\n");
                    gerarRelatorio(estoque, totalAnimes);
                    break;

                case 7:
                    // voltar ao menu principal
                    printf("Voltando ao menu principal...\n");
                    system("cls");
                    break;

                default:
                    printf("error... Numero invalido\n");
                    break;
                }
            } while (subOp != 7); // volta ao menu principal
            break;

        case 2:
            // sair do programa
            printf("Saindo...\n");
            break;

        default:
            printf("error... Numero invalido\n");
            break;
        }
    } while (op != 2); // encerra o programa

    return 0;
}
