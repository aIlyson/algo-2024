#include <stdio.h>
#include <string.h>
#include "estoque.h"

// funções
int cadastrarAnime(struct Anime estoque[], int totalAnimes)
{
    // verifica se o estoque esta cheio
    if (totalAnimes >= 100) // limitei para 100
    {
        printf("Capacidade maxima atingida!\n");
        return totalAnimes;
    }

    struct Anime novoAnime;

    // gera um ID ao anime
    novoAnime.IDanime = totalAnimes + 1;

    printf("Digite o nome do anime: ");
    scanf(" %[^\n]", novoAnime.nome); // le uma string com espaços (até o '\n')

    printf("Digite o genero do anime: ");
    scanf(" %[^\n]", novoAnime.genero);

    printf("Digite o preco do anime: ");
    scanf("%f", &novoAnime.preco);

    printf("Digite a quantidade inicial de Blu-rays: ");
    scanf("%d", &novoAnime.quantidadeBluRay);

    // adicina o novo anime ao estoque e incrementa o contador
    estoque[totalAnimes] = novoAnime;

    totalAnimes++;

    printf("Anime cadastrado! ID: %d\n", novoAnime.IDanime);

    return totalAnimes;
}

int consultarAnime(struct Anime estoque[], int totalAnimes)
{
    // verifica se o estoque esta vazio
    if (totalAnimes == 0)
    {
        printf("Nao ha animes cadastrados!\n");
        return 1;
    }

    int opcao;
    printf("\nDeseja buscar por:\n");
    printf("1. ID\n");
    printf("2. Nome\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    if (opcao == 1)
    {
        int idBusca;
        printf("Digite o ID do anime: ");
        scanf("%d", &idBusca);

        // busca pelo ID
        for (int i = 0; i < totalAnimes; i++)
        {
            if (estoque[i].IDanime == idBusca)
            {
                printf("\nAnime encontrado:\n");
                printf("ID: %d\n", estoque[i].IDanime);
                printf("Nome: %s\n", estoque[i].nome);
                printf("Genero: %s\n", estoque[i].genero);
                printf("Preco: %.2f\n", estoque[i].preco);
                printf("Quantidade de Blu-rays: %d\n", estoque[i].quantidadeBluRay);
                return 0;
            }
        }
        printf("Nenhum anime encontrado com o ID %d.\n", idBusca);
    }
    else if (opcao == 2)
    {
        char nomeBusca[100];
        printf("Digite o nome do anime: ");
        scanf(" %[^\n]", nomeBusca);

        // busca pelo nome
        for (int i = 0; i < totalAnimes; i++)
        {
            if (strcmp(estoque[i].nome, nomeBusca) == 0)
            {
                printf("\nAnime encontrado:\n");
                printf("ID: %d\n", estoque[i].IDanime);
                printf("Nome: %s\n", estoque[i].nome);
                printf("Genero: %s\n", estoque[i].genero);
                printf("Preco: %.2f\n", estoque[i].preco);
                printf("Quantidade de Blu-rays: %d\n", estoque[i].quantidadeBluRay);
                return 0;
            }
        }
        printf("Nenhum anime encontrado com o nome '%s'.\n", nomeBusca);
    }
    else
    {
        printf("Error... Opcao invalida!\n");
    }

    return 0;
}

void editarAnime(struct Anime estoque[], int totalAnimes)
{
    if (totalAnimes == 0)
    {
        printf("Nao ha animes cadastrados! Nada para editar.\n");
        return;
    }

    int idBusca;
    printf("Digite o ID do anime que deseja editar: ");
    scanf("%d", &idBusca);

    // busca pelo ID
    for (int i = 0; i < totalAnimes; i++)
    {
        if (estoque[i].IDanime == idBusca)
        {
            printf("\nAnime encontrado:\n");
            printf("ID: %d\n", estoque[i].IDanime);
            printf("Nome atual: %s\n", estoque[i].nome);
            printf("Genero atual: %s\n", estoque[i].genero);
            printf("Preco atual: %.2f\n", estoque[i].preco);
            printf("Quantidade atual de Blu-rays: %d\n", estoque[i].quantidadeBluRay);

            char opcao;

            printf("\nDeseja editar o nome do anime? (s/n): ");
            scanf(" %c", &opcao);
            if (opcao == 's' || opcao == 'S')
            {
                printf("Digite o novo nome do anime: ");
                scanf(" %[^\n]", estoque[i].nome);
                printf("Nome atualizado!\n");
            }

            printf("Deseja editar o genero do anime? (s/n): ");
            scanf(" %c", &opcao);
            if (opcao == 's' || opcao == 'S')
            {
                printf("Digite o novo genero do anime: ");
                scanf(" %[^\n]", estoque[i].genero);
                printf("Genero atualizado!\n");
            }

            printf("Deseja editar o preco do anime? (s/n): ");
            scanf(" %c", &opcao);
            if (opcao == 's' || opcao == 'S')
            {
                printf("Digite o novo preco do anime: ");
                scanf("%f", &estoque[i].preco);
                printf("Preco atualizado!\n");
            }

            printf("Deseja editar a quantidade de Blu-rays? (s/n): ");
            scanf(" %c", &opcao);
            if (opcao == 's' || opcao == 'S')
            {
                printf("Digite a nova quantidade de Blu-rays: ");
                scanf("%d", &estoque[i].quantidadeBluRay);
                printf("Quantidade de Blu-rays atualizada!\n");
            }

            printf("\nAnime editado!\n");
            return;
        }
    }

    printf("Nenhum anime encontrado. ID inexistente: %d.\n", idBusca);
}

void atualizarEstoque(struct Anime estoque[], int totalAnimes, int IDanime, int quantidade, int entrada)
{
    // verifica se o estoque esta vazio
    if (totalAnimes == 0)
    {
        printf("Nao ha animes cadastrados!\n");
        return;
    }

    // verifica se a quantidade e valido
    if (quantidade <= 0)
    {
        printf("Erro... Numero de Blu-rays invalido.\n");
        return;
    }

    // busca pelo ID do anime
    for (int i = 0; i < totalAnimes; i++)
    {
        if (estoque[i].IDanime == IDanime)
        {
            // salva a quantidade anterior
            int quantidadeAnterior = estoque[i].quantidadeBluRay;

            printf("\nAnime encontrado: '%s'\n", estoque[i].nome);

            if (entrada == 1)
            {
                // operação de entrada
                estoque[i].quantidadeBluRay += quantidade;
                printf("Quantidade anterior: %d Blu-rays.\nQuantidade nova: %d Blu-rays (Adicionadas %d unidades).\n",
                       quantidadeAnterior, estoque[i].quantidadeBluRay, quantidade);
            }
            else if (entrada == 0)
            {
                // operação de saída
                if (estoque[i].quantidadeBluRay >= quantidade)
                {
                    estoque[i].quantidadeBluRay -= quantidade;
                    printf("Quantidade anterior: %d Blu-rays.\nQuantidade nova: %d Blu-rays (Removidas %d unidades).\n",
                           quantidadeAnterior, estoque[i].quantidadeBluRay, quantidade);
                }
                else
                {
                    // verifica se tem estoque
                    printf("Erro... Nao ha quantidade suficiente no anime '%s'. Disponivel: %d Blu-rays.\n",
                           estoque[i].nome, estoque[i].quantidadeBluRay);
                }
            }
            else
            {
                printf("Erro... Opcao invalida.\n");
            }

            return;
        }
    }

    printf("Nenhum anime encontrado com o ID %d.\n", IDanime);
}

int removerAnime(struct Anime estoque[], int totalAnimes)
{
    // verifica se o estoque está vazio
    if (totalAnimes == 0)
    {
        printf("Nao ha animes cadastrados! Nada para remover.\n");
        return totalAnimes;
    }

    int opcao;

    // menu de opções
    printf("\nDeseja buscar para remover por:\n");
    printf("1. ID\n");
    printf("2. Nome\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    if (opcao == 1)
    {
        // busca pelo ID
        int IDBusca;
        printf("Digite o ID do anime: ");
        scanf("%d", &IDBusca);

        for (int i = 0; i < totalAnimes; i++)
        {
            if (estoque[i].IDanime == IDBusca)
            {
                printf("\nRemovendo o anime '%s' com ID %d...\n", estoque[i].nome, estoque[i].IDanime);

                // remove o elemento do array e reorganiza
                for (int j = i; j < totalAnimes - 1; j++)
                {
                    estoque[j] = estoque[j + 1];
                }
                totalAnimes--;

                printf("Anime removido!\n");
                return totalAnimes;
            }
        }
        printf("Nenhum anime encontrado com o ID %d.\n", IDBusca);
    }
    else if (opcao == 2)
    {
        // busca pelo nome
        char nomeBusca[100];
        printf("Digite o nome do anime: ");
        scanf(" %[^\n]s", nomeBusca); // le a string com espaços

        for (int i = 0; i < totalAnimes; i++)
        {
            if (strcmp(estoque[i].nome, nomeBusca) == 0)
            {
                printf("\nRemovendo o anime '%s' com ID %d...\n", estoque[i].nome, estoque[i].IDanime);

                // remove o elemento do array e reorganiza
                for (int j = i; j < totalAnimes - 1; j++)
                {
                    estoque[j] = estoque[j + 1];
                }
                totalAnimes--;

                printf("Anime removido!\n");

                return totalAnimes;
            }
        }
        printf("Nenhum anime encontrado com o nome '%s'.\n", nomeBusca);
    }
    else
    {
        printf("Erro... Opcao invalida.\n");
    }

    return totalAnimes;
}

void gerarRelatorio(struct Anime estoque[], int totalAnimes)
{
    // verifica se o estoque está vazio
    if (totalAnimes == 0)
    {
        printf("Nao ha animes cadastrados!\n");
        return;
    }

    printf("\nRelatorio de Estoque:\n");
    printf("============================================================\n");

    // cabeçalho
    printf("ID || Nome || Genero || Preco || Quantidade de Blu-rays\n");
    printf("------------------------------------------------------------\n");

    // imprime o estoque
    for (int i = 0; i < totalAnimes; i++)
    {
        printf("%d || %s || %s || %.2f Reais || %d\n",
               estoque[i].IDanime,
               estoque[i].nome,
               estoque[i].genero,
               estoque[i].preco,
               estoque[i].quantidadeBluRay);
    }

    printf("============================================================\n");
    printf("Quantidade total de animes cadastrados: %d\n", totalAnimes);
}