#include <stdio.h>
#include "methods/estoque.h"

int main()
{
    // TODO: lembrar de definir o tamanho do array
    struct Anime estoque[100];
    int totalAnimes = 0; // contador de animes cadastrados
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
            // gerenciamento de estoque de animes
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
                    // aqui onde vamos adicionar o nome do anime e quantidade de blu-rays disponíveis
                    printf("adicionando anime...\n");
                    char opcao;
                    while (opcao != 'n')
                    {
                        cadastrarAnime(estoque, &totalAnimes);
                        printf("Deseja cadastrar outro anime? (s/n): ");
                        scanf(" %c", &opcao);
                    }

                    break;

                case 2:
                    // consultar anime
                    // aqui ele vai buscar o anime pelo nome ou código e exibir suas informações
                    printf("consultando anime...\n");

                    do
                    {

                        if (consultarAnime(estoque, totalAnimes) != 0)
                        {
                            // Se retornar diferente de 0, o estoque esta vazio
                            break; // Sai do loop imediatamente
                        }
                        // Pergunta se o usuário deseja consultar outro anime
                        printf("Deseja consultar outro anime? (s/n): ");
                        scanf(" %c", &opcao); // Nota: espaço antes do %c para limpar o buffer
                    } while (opcao == 's'); // Continua enquanto o usuário quiser

                    break;

                case 3:
                    // editar anime
                    // aqui ele vai editar o nome do anime e a quantidade disponíveis
                    printf("editando anime...\n");
                    char continuar;
                    do
                    {
                        editarAnime(estoque, totalAnimes);
                        printf("Deseja editar outro anime? (s/n): ");
                        scanf(" %c", &continuar);
                    } while (continuar != 'n');
                    break;
                case 4:
                    // atualizar estoque

                    printf("Atualizar estoque:\n");
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
                        printf("Opcao invalida.\n");
                    }
                    break;

                case 5:
                    // remover anime
                    // aqui ele vai remover o anime pelo nome ou codigo
                    printf("removendo anime...\n");
                    
                    do
                    {
                        removerAnime(estoque, &totalAnimes);
                        printf("Deseja remover outro anime? (s/n): ");
                        scanf(" %c", &continuar);
                    } while (continuar != 'n');
                    
                    break;

                case 6:
                    // gerar relatorio
                    // aqui só vai retornar quantidade de animes cadastrados
                    printf("gerando relatorio de estoque...\n");
                    gerarRelatorio(estoque, totalAnimes);
                    break;

                case 7:
                    printf("voltando ao menu principal...\n");
                    break;

                default:
                    printf("error...\n");
                    break;
                }

            } while (subOp != 7);
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
