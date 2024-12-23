#include <stdio.h>
#include "methods/estoque.h"

int main()
{
    // TODO: lembrar de definir o tamanho do array
    struct Anime estoque[100];
    int totalAnimes = 0; // contador de animes cadastrados
    int op;

    do
    {
        printf("\n*** MENU PRINCIPAL - Loteria de Animes ***\n");
        printf("-------------------------------------------\n");
        printf("1. Gerenciar estoque de animes\n");
        printf("2. Consultar relatorio do estoque\n");
        printf("3. Sair\n");
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
                printf("4. Adicionar Blu-ray ao Estoque\n");
                printf("5. Remover Blu-ray do Estoque\n");
                printf("6. Remover anime do estoque\n");
                printf("7. Voltar ao menu\n");
                printf("--------------------------------------------\n");
                printf("Escolha uma opcao: ");
                scanf("%d", &op);

                switch (op)
                {
                case 1:
                    // cadastrar Anime à Loteria
                    // aqui onde vamos adicionar o nome do anime e quantidade de blu-rays disponíveis
                    printf("adicionando anime...\n");
                    // chame a função cadastrarAnime(estoque, &totalAnimes)
                    break;

                case 2:
                    // consultar anime
                    // aqui ele vai buscar o anime pelo nome ou código e exibir suas informações
                    printf("consultando anime...\n");
                    // chame a função consultarAnime(estoque, totalAnimes)
                    break;

                case 3:
                    // editar anime
                    // aqui ele vai editar o nome do anime e a quantidade disponíveis
                    printf("editando anime...\n");
                    // chame a função editarAnime(estoque, totalAnimes)
                    break;

                case 4:
                    // entrada de blu-ray em estoque
                    // aqui ele vai aumentar a quantidade de blu-rays de um anime já cadastrado
                    printf("registrando entrada de unidade...\n");
                    // chame a função entradaBluRay(estoque, totalAnimes)
                    break;

                case 5:
                    // saida de blu-ray em estoque
                    // aqui ele vai reduzir a quantidade de blu-rays (unidades) em estoque
                    printf("registrando saída da unidade...\n");
                    // chame a função saidaBluRay(estoque, totalAnimes)
                    break;

                case 6:
                    // Remover anime
                    printf("removendo anime...\n");
                    // chame a função removerAnime(estoque, &totalAnimes);
                    break;

                case 7:
                    printf("voltando ao menu...\n");
                    break;

                default:
                    printf("error...\n");
                    break;
                }

            } while (op != 6);

            break;

        case 2:
            // gerar relatorio do estoque de animes
            // aqui ele vai exibir todos os animes cadastrados, quantidade de blu-rays, o estoque total e tudo meu parceiro
            printf("gerando relatorio de estoque...\n");
            // chame a função gerarRelatorio(estoque, totalAnimes)
            break;

        case 3:
            printf("saindo...\n");
            break;

        default:
            printf("error...\n");
            break;
        }
    } while (op != 3);

    return 0;
}
