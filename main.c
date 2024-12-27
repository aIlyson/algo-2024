#include <stdio.h>
#include "methods/estoque.h"
#include <stdlib.h>

int main() {
    struct Anime estoque[100];
    int totalAnimes = 0;
    int op, subOp;
    float caixa = 0.0;

    do {
        printf("\n*** MENU PRINCIPAL ***\n");
        printf("-------------------------------------------\n");
        printf("1. Gerenciar estoque de animes\n");
        printf("2. Sair\n");
        printf("-------------------------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        switch (op) {
        case 1:
            do {
                printf("\n*** MENU DE GESTAO DE ESTOQUE DE ANIMES ***\n");
                printf("--------------------------------------------\n");
                printf("1. Adicionar anime\n");
                printf("2. Consultar anime\n");
                printf("3. Editar anime\n");
                printf("4. Atualizar estoque de Blu-rays\n");
                printf("5. Remover anime do estoque\n");
                printf("6. Gerar relatorio do estoque\n");
                printf("7. Realizar venda de Blu-rays\n");
                printf("8. Voltar ao menu principal\n");
                printf("--------------------------------------------\n");
                printf("Escolha uma opcao: ");
                scanf("%d", &subOp);

                switch (subOp) {
                case 1: {
                    char opcao = 's';
                    while (opcao != 'n') {
                        cadastrarAnime(estoque, &totalAnimes);
                        printf("Deseja cadastrar outro anime? (s/n): ");
                        scanf(" %c", &opcao);
                    }
                    system("cls");
                    break;
                }
                case 2: {
                    char opcao;
                    do {
                        if (consultarAnime(estoque, totalAnimes) != 0) break;
                        printf("Deseja consultar outro anime? (s/n): ");
                        scanf(" %c", &opcao);
                    } while (opcao == 's');
                    system("cls");
                    break;
                }
                case 3: {
                    char continuar = 's';
                    do {
                        editarAnime(estoque, totalAnimes);
                        printf("Deseja editar outro anime? (s/n): ");
                        scanf(" %c", &continuar);
                    } while (continuar != 'n');
                    system("cls");
                    break;
                }
                case 4: {
                    int escolha, codigo, quantidade;
                    system("cls");
                    printf("Atualizar estoque:\n");
                    printf("1. Entrada de Blu-rays\n");
                    printf("2. Saida de Blu-rays\n");
                    scanf("%d", &escolha);

                    printf("Digite o codigo do anime: ");
                    scanf("%d", &codigo);
                    printf("Digite a quantidade: ");
                    scanf("%d", &quantidade);

                    if (escolha == 1) {
                        atualizarEstoque(estoque, totalAnimes, codigo, quantidade, 1);
                    } else if (escolha == 2) {
                        atualizarEstoque(estoque, totalAnimes, codigo, quantidade, 0);
                    } else {
                        printf("Opcao invalida.\n");
                    }
                    
                    break;
                }
                case 5: {
                    char continuar = 's';
                    do {
                        removerAnime(estoque, &totalAnimes);
                        printf("Deseja remover outro anime? (s/n): ");
                        scanf(" %c", &continuar);
                    } while (continuar != 'n');
                    system("cls");
                    break;
                }
                case 6:
                    printf("gerando relatorio de estoque...\n");
                    gerarRelatorio(estoque, totalAnimes);
                    break;
                case 7: {
                    char continuar = 's';
                    do {
                        realizarvenda(estoque, totalAnimes, &caixa);
                        printf("deseja realizar outra venda? (s/n): ");
                        scanf(" %c", &continuar);
                    } while (continuar != 'n');
                    break;
                }
                case 8:
                    printf("voltando ao menu principal...\n");
                    break;
                default:
                    printf("error...\n");
                    break;
                }
            } while (subOp != 8);
            break;
        case 2:
            printf("saindo...\n");
            break;
        default:
            printf("error...\n");
            break;
        }
    } while (op != 2);

    return 0;
}
