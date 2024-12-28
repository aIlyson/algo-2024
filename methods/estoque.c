#include <stdio.h>
#include <string.h>
#include "estoque.h"

// funções
int cadastrarAnime(struct Anime estoque[], int totalAnimes)
{
    // verifica se o estoque está cheio
    if (totalAnimes >= 100) // limitei para 100
    {
        printf("Capacidade maxima atingida!\n");
        return totalAnimes;
    }

    struct Anime novoAnime;

    printf("Digite o nome do anime: ");
    scanf(" %[^\n]", novoAnime.nome); // le uma string com espaços (até o '\n')

    printf("Digite a quantidade inicial de Blu-rays: ");
    scanf("%d", &novoAnime.quantidadeBluRay);

    // gera um código para o novo anime
    novoAnime.codigo = totalAnimes + 1;

    // adiciona o novo anime e incrementa o contador
    estoque[totalAnimes] = novoAnime;

    totalAnimes++;

    printf("Anime cadastrado! Codigo: %d\n", novoAnime.codigo);

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
    printf("1. Codigo\n");
    printf("2. Nome\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    if (opcao == 1)
    {
        int codigoBusca;
        printf("Digite o codigo do anime: ");
        scanf("%d", &codigoBusca);

        // busca pelo código
        for (int i = 0; i < totalAnimes; i++)
        {
            if (estoque[i].codigo == codigoBusca)
            {
                printf("\nAnime encontrado:\n");
                printf("Codigo: %d\n", estoque[i].codigo);
                printf("Nome: %s\n", estoque[i].nome);
                printf("Quantidade de Blu-rays: %d\n", estoque[i].quantidadeBluRay);
                return 0;
            }
        }
        printf("Nenhum anime encontrado com o codigo %d.\n", codigoBusca);
    }
    else if (opcao == 2)
    {
        char nomeBusca[50];
        printf("Digite o nome do anime: ");
        scanf(" %[^\n]", nomeBusca);

        // busca pelo nome
        for (int i = 0; i < totalAnimes; i++)
        {
            if (strcmp(estoque[i].nome, nomeBusca) == 0)
            {
                printf("\nAnime encontrado:\n");
                printf("Codigo: %d\n", estoque[i].codigo);
                printf("Nome: %s\n", estoque[i].nome);
                printf("Quantidade de Blu-rays: %d\n", estoque[i].quantidadeBluRay);
                return 0;
            }
        }
        printf("Nenhum anime encontrado com o nome '%s'.\n", nomeBusca);
    }
    else
    {
        printf("error...\n");
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

    int codigoBusca;
    printf("Digite o codigo do anime que deseja editar: ");
    scanf("%d", &codigoBusca);

    // busca pelo anime pelo codigo
    for (int i = 0; i < totalAnimes; i++)
    {
        if (estoque[i].codigo == codigoBusca)
        {
            printf("\nAnime encontrado:\n");
            printf("Codigo: %d\n", estoque[i].codigo);
            printf("Nome atual: %s\n", estoque[i].nome);
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

    // caso não encontre o anime
    printf("Nenhum anime encontrado. Codigo inexistente: %d.\n", codigoBusca);
}

void atualizarEstoque(struct Anime estoque[], int totalAnimes, int codigo, int quantidade, int entrada)
{
    // verifica se o estoque esta vazio
    if (totalAnimes == 0)
    {
        printf("Nao ha animes cadastrados!\n");
        return;
    }

    // verifica se a quantidade e válida
    if (quantidade <= 0)
    {
        printf("error... Numero de Blu-rays invalido\n");
        return;
    }

    // busca pelo codigo
    for (int i = 0; i < totalAnimes; i++)
    {
        if (estoque[i].codigo == codigo)
        {
            int quantidadeAnterior = estoque[i].quantidadeBluRay; // salva a quantidade anterior

            printf("Anime: '%s'\n", estoque[i].nome);

            if (entrada == 1)
            {
                // operacao de entrada
                estoque[i].quantidadeBluRay += quantidade;
                printf("Quantidade anterior: %d Blu-rays.\nQuantidade nova: %d Blu-rays (Adicionadas %d unidades).\n",
                       quantidadeAnterior, estoque[i].quantidadeBluRay, quantidade);
            }
            else if (entrada == 0)
            {
                // operacao de saida
                if (estoque[i].quantidadeBluRay >= quantidade)
                {
                    estoque[i].quantidadeBluRay -= quantidade;
                    printf("Quantidade anterior: %d Blu-rays.\nQuantidade nova: %d Blu-rays (Removidas %d unidades).\n",
                           quantidadeAnterior, estoque[i].quantidadeBluRay, quantidade);
                }
                else
                {
                    // verifica se tem estoque suficiente no anime
                    printf("error... Nao ha quantidade suficiente no anime '%s'. Disponivel: %d Blu-rays.\n",
                           estoque[i].nome, estoque[i].quantidadeBluRay);
                }
            }
            else
            {
                printf("error... Numero invalido\n");
            }

            return;
        }
    }

    printf("Nenhum anime encontrado com o codigo %d.\n", codigo);
}

int removerAnime(struct Anime estoque[], int totalAnimes)
{
    // verifica se o estoque esta vazio
    if (totalAnimes == 0)
    {
        printf("Nao ha animes cadastrados! Nada para remover.\n");
        return totalAnimes;
    }

    int opcao;

    // menu de opcoes
    printf("Deseja buscar para remover por:\n");
    printf("1. Codigo\n");
    printf("2. Nome\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    // busca pelo codigo
    if (opcao == 1)
    {
        int codigoBusca;
        printf("Digite o codigo do anime: ");
        scanf("%d", &codigoBusca);

        for (int i = 0; i < totalAnimes; i++)
        {
            if (estoque[i].codigo == codigoBusca)
            {
                printf("Removendo o anime '%s' com codigo %d...\n", estoque[i].nome, estoque[i].codigo);

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
        printf("Nenhum anime encontrado com o codigo %d.\n", codigoBusca);
    }
    // busca pelo nome
    else if (opcao == 2)
    {
        char nomeBusca[100];
        printf("Digite o nome do anime: ");
        scanf(" %[^\n]s", nomeBusca); // le a string com espaços

        for (int i = 0; i < totalAnimes; i++)
        {
            if (strcmp(estoque[i].nome, nomeBusca) == 0)
            {
                printf("Removendo o anime '%s' com código %d...\n", estoque[i].nome, estoque[i].codigo);

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
        printf("Erro... número inválido.\n");
    }

    return totalAnimes;
}

void gerarRelatorio(struct Anime estoque[], int totalAnimes)
{
    // verifica se o estoque esta vazio
    if (totalAnimes == 0)
    {
        printf("Nao ha animes cadastrados!\n");
        return;
    }

    printf("\nRelatorio de Estoque:\n");
    printf("============================================\n");

    // cabecalho
    printf("Codigo || Nome || Quantidade de Blu-rays\n");
    printf("------------------------------------------\n");

    // imprime o estoque
    for (int i = 0; i < totalAnimes; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            printf("%d || %s || %d\n", estoque[i].codigo, estoque[i].nome, estoque[i].quantidadeBluRay);
        }
    }

    printf("============================================\n");
    printf("Quantidade total de animes cadastrados: %d\n", totalAnimes);
}
