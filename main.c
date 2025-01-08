#include <stdio.h>              // inclui a biblioteca stdio.h para usar as funcoes basicas
#include <stdlib.h>             // inclui a biblioteca stdlib.h para usar o system("cls")
#include "methods/estoque.h"    // inclui o arquivo estoque.h para usar a estrutura Anime e as funcoes
#include "methods/financeiro.h" // inclui o arquivo financeiro.h para usar as funcoes

int main()
{
    // variaveis
    struct Anime estoque[100];
    int totalAnimes = 0;
    int op, subOp;

    // menu principal
    do
    {
        printf("\n           MENU PRINCIPAL           \n");
        printf("=======================================\n");
        printf("0. Sair\n");
        printf("1. Gerenciar estoque de animes\n");
        printf("2. Gerenciar vendas de animes\n");
        printf("=======================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        system("cls");

        switch (op)
        {
        case 0:
            // sair do programa
            printf("Saindo...\n");
            break;

        case 1: // gerenciar estoque
            do
            {
                printf("\n     MENU DE GESTAO DE ESTOQUE DE ANIMES     \n");
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
                case 0: // voltar ao menu principal
                    system("cls");
                    printf("Voltando ao menu principal...\n");
                    break;

                case 1: // cadastrar anime
                    printf("Cadastrar anime\n");
                    char opcao;
                    do
                    {
                        totalAnimes = cadastrarAnime(estoque, totalAnimes); // atualiza o 'totalAnimes'

                        do
                        {
                            printf("Deseja cadastrar outro anime? (s/n): ");
                            scanf(" %c", &opcao);

                            if (opcao != 's' && opcao != 'n')
                            {
                                printf("ERRO... Opcao invalida.\n");
                            }
                        } while (opcao != 's' && opcao != 'n');

                    } while (opcao == 's');

                    system("cls");
                    break;

                case 2: // consultar anime
                    printf("Consultar anime\n");

                    // verifica se há animes antes
                    if (totalAnimes == 0)
                    {
                        system("cls");
                        printf("Nao ha animes cadastrados! Nada para consultar.\n");
                    }
                    else
                    {
                        do
                        {
                            if (consultarAnime(estoque, totalAnimes) != 0)
                            {
                                break;
                            }

                            do
                            {
                                printf("Deseja consultar outro anime? (s/n): ");
                                scanf(" %c", &opcao);

                                if (opcao != 's' && opcao != 'n')
                                {
                                    printf("ERRO... Opcao invalida!\n");
                                }
                            } while (opcao != 's' && opcao != 'n');

                            system("cls");

                        } while (opcao == 's');
                    }
                    break;

                case 3: // editar anime
                    printf("Editar anime\n");

                    // verifica se há animes antes
                    if (totalAnimes == 0)
                    {
                        system("cls");
                        printf("Nao ha animes cadastrados! Nada para editar.\n");
                    }
                    else
                    {
                        do
                        {
                            editarAnime(estoque, totalAnimes);

                            do
                            {
                                printf("Deseja editar outro anime? (s/n): ");
                                scanf(" %c", &opcao);

                                if (opcao != 's' && opcao != 'n')
                                {
                                    printf("ERRO... Opcao invalida!\n");
                                }
                            } while (opcao != 's' && opcao != 'n');

                            system("cls");

                        } while (opcao == 's');
                    }
                    break;

                case 4: // atualizar estoque
                    printf("Atualizar estoque de Blu-rays\n");

                    if (totalAnimes == 0)
                    {
                        system("cls");
                        printf("Nao ha animes cadastrados! Nada para atualizar.\n");
                        break;
                    }

                    printf("1. Entrada de Blu-rays\n");
                    printf("2. Saida de Blu-rays\n");

                    int escolha, codigo, quantidade;
                    scanf("%d", &escolha);

                    printf("Digite o codigo do anime: ");
                    scanf("%d", &codigo);
                    // mostra o estoque
                    printf("Estoque atual do anime: %d\n", estoque[codigo - 1].quantidadeBluRay);

                    // notificação de estoque baixo
                    if (estoque[codigo - 1].quantidadeBluRay <= 3)
                    {
                        printf("AVISO... Estoque muito baixo!\n");
                    }

                    printf("Digite a quantidade: ");
                    scanf("%d", &quantidade);

                    // valida a escolha
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
                        printf("ERRO... Opcao invalida!\n");
                    }
                    break;

                case 5: // remover anime
                    printf("Remover anime\n");

                    // verifica se há animes antes
                    if (totalAnimes == 0)
                    {
                        system("cls");
                        printf("Nao ha animes cadastrados! Nada para remover.\n");
                    }
                    else
                    {
                        do
                        {
                            totalAnimes = removerAnime(estoque, totalAnimes);

                            // verifica se há animes restantes
                            if (totalAnimes > 0)
                            {
                                printf("Animes no estoque: %d\n", totalAnimes);

                                do
                                {
                                    printf("Deseja remover outro anime? (s/n): ");
                                    scanf(" %c", &opcao);

                                    if (opcao != 's' && opcao != 'n')
                                    {
                                        printf("ERRO... Opcao invalida!\n");
                                    }

                                } while (opcao != 's' && opcao != 'n');
                            }
                            else
                            {
                                printf("Nao ha animes cadastrados! Nada para remover.\n");
                                opcao = 'n';
                            }

                            system("cls");

                        } while (opcao == 's');
                    }
                    break;

                case 6: // gerar relatório
                    system("cls");
                    printf("====================================\n");
                    gerarRelatorio(estoque, totalAnimes);
                    if (totalAnimes == 0)
                    {
                        system("cls");
                        printf("Nao ha animes cadastrados! Nada para exibir.\n");
                    }
                    break;

                default:
                    printf("ERRO... Opcao invalida!\n");
                    break;
                }
            } while (subOp != 0); // volta ao menu principal
            break;

        case 2: // gerenciar financeiro
            do
            {
                printf("\n      MENU DE GESTAO FINANCEIRO      \n");
                printf("====================================\n");
                printf("0. Voltar ao menu principal\n");
                printf("1. Realizar venda\n");
                printf("2. Consultar caixa da locadora\n");
                printf("3. Gerar relatorio de financeiro\n");
                printf("====================================\n");
                printf("Escolha uma opcao: ");
                scanf("%d", &subOp);

                switch (subOp)
                {
                case 0: // voltar ao menu principal
                    system("cls");
                    printf("Voltando ao menu principal...\n");
                    break;

                case 1: // realizar venda
                    printf("Realizar venda\n");

                    if (totalAnimes == 0)
                    {
                        system("cls");
                        printf("Nao ha animes cadastrados!\n");
                    }
                    else
                    {
                        int idAnime;
                        int quantidadeVendida;

                        printf("Digite o ID do produto para venda: ");
                        scanf("%d", &idAnime);
                        printf("Digite a quantidade a ser vendida: ");
                        scanf("%d", &quantidadeVendida);

                        realizarVenda(estoque, totalAnimes, idAnime, quantidadeVendida);
                    }
                    break;

                case 2: // consultar caixa da locadora
                    system("cls");
                    consultarCaixa();
                    break;

                case 3: // gerar relatório
                    system("cls");
                    printf("====================================\n");
                    gerarRelatorioFinanceiro(estoque, totalAnimes);

                    if (totalAnimes == 0)
                    {
                        system("cls");
                        printf("Nao ha animes cadastrados! Nada para exibir.\n");
                    }
                    break;

                default:
                    printf("ERRO... Opcao invalida!\n");
                    break;
                }
            } while (subOp != 0); // volta ao menu principal
            break;

        default:
            printf("ERRO... Opcao invalida!\n");
            break;
        }
    } while (op != 0); // encerra o programa

    return 0;
}