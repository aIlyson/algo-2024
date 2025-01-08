#include <stdio.h>
#include <string.h>  // inclui a biblioteca string.h para usar a funcao strcmp, que compara strings
#include "estoque.h" // inclui o arquivo estoque.h para usar a estrutura Anime

// funções
int cadastrarAnime(struct Anime estoque[], int totalAnimes)
{
    // verifica se o estoque esta cheio
    if (totalAnimes >= 100) // limitei para 100
    {
        printf("Capacidade maxima atingida!\n");
        return totalAnimes;
    }

    struct Anime novoAnime; // struct para armazenar os dados do anime

    // gera um ID ao anime
    novoAnime.IDanime = totalAnimes + 1;

    printf("Digite o nome do anime: ");
    scanf(" %[^\n]", novoAnime.nome); // le uma string com espaços (até o '\n')

    // verifica se o anime existe
    for (int i = 0; i < totalAnimes; i++)
    {
        if (strcmp(estoque[i].nome, novoAnime.nome) == 0)
        {
            printf("Anime ja cadastrado!\n");
            return totalAnimes;
        }
    }

    printf("Digite o genero do anime: ");
    scanf(" %[^\n]", novoAnime.genero);

    printf("Digite o preco de compra do anime: ");
    scanf("%f", &novoAnime.precodecompra);

    // verifica o preco de compra
    if (novoAnime.precodecompra <= 0 || novoAnime.precodecompra > 499)
    {
        printf("ERRO... O preco de compra invalido!\n");
        return totalAnimes;
    }

    printf("Digite o preco de venda do anime: ");
    scanf("%f", &novoAnime.precodevenda);

    // verifica o preco de venda
    if (novoAnime.precodevenda <= 0 || novoAnime.precodevenda < novoAnime.precodecompra || novoAnime.precodevenda > 500)
    {
        printf("ERRO... O preco de venda invalido!\n");
        return totalAnimes;
    }

    printf("Digite a quantidade inicial de Blu-rays: ");
    scanf("%d", &novoAnime.quantidadeBluRay);

    // verifica a quantidade de Blu-rays
    if (novoAnime.quantidadeBluRay <= 0 || novoAnime.quantidadeBluRay > 1000)
    {
        printf("ERRO... A quantidade de Blu-rays invalida!\n");
        return totalAnimes;
    }

    // adicina o novo anime ao estoque e incrementa o contador
    estoque[totalAnimes] = novoAnime;

    totalAnimes++;

    printf("Anime cadastrado! ID: %d\n", novoAnime.IDanime);

    return totalAnimes;
}

int consultarAnime(struct Anime estoque[], int totalAnimes)
{
    int opcao;
    printf("\nDeseja buscar por:\n");
    printf("1 - ID\n");
    printf("2 - Nome\n");
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
                printf("====================================\n");
                printf("ID: %d\n", estoque[i].IDanime);
                printf("Nome: %s\n", estoque[i].nome);
                printf("Genero: %s\n", estoque[i].genero);
                printf("Preco de compra: %.2f\n", estoque[i].precodecompra);
                printf("Preco de venda: %.2f\n", estoque[i].precodevenda);
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
                printf("====================================\n");
                printf("ID: %d\n", estoque[i].IDanime);
                printf("Nome: %s\n", estoque[i].nome);
                printf("Genero: %s\n", estoque[i].genero);
                printf("Preco: %.2f\n", estoque[i].precodecompra);
                printf("Preco: %.2f\n", estoque[i].precodevenda);
                printf("Quantidade de Blu-rays: %d\n", estoque[i].quantidadeBluRay);
                return 0;
            }
        }
        printf("Nenhum anime encontrado com o nome '%s'.\n", nomeBusca);
    }
    else
    {
        printf("ERROR... Opcao invalida!\n");
    }

    return 0;
}
void editarAnime(struct Anime estoque[], int totalAnimes)
{
    int idBusca;
    printf("Digite o ID do anime que deseja editar: ");
    scanf("%d", &idBusca);

    // busca pelo ID
    for (int i = 0; i < totalAnimes; i++)
    {
        if (estoque[i].IDanime == idBusca)
        {
            printf("\nAnime encontrado:\n");
            printf("====================================\n");
            printf("ID: %d\n", estoque[i].IDanime);
            printf("Nome atual: %s\n", estoque[i].nome);
            printf("Genero atual: %s\n", estoque[i].genero);
            printf("Preco de compra atual: %.2f\n", estoque[i].precodecompra);
            printf("Preco de venda atual: %.2f\n", estoque[i].precodevenda);
            printf("Quantidade atual de Blu-rays: %d\n", estoque[i].quantidadeBluRay);
            printf("====================================\n");

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

            printf("Deseja editar o preco de compra do anime? (s/n): ");
            scanf(" %c", &opcao);
            if (opcao == 's' || opcao == 'S')
            {
                float novoPrecoCompra; // auxiliar para salvar o preco de compra
                printf("Digite o novo preco de compra: ");
                scanf("%f", &novoPrecoCompra);

                // verifica se o preco de compra e valido
                if (novoPrecoCompra <= 0 || novoPrecoCompra > estoque[i].precodevenda || novoPrecoCompra > 499)
                {
                    printf("ERRO... Preco de compra invalido!\n");
                }
                else
                {
                    estoque[i].precodecompra = novoPrecoCompra;
                    printf("Preco de compra atualizado!\n");
                }
            }

            printf("Deseja editar o preco de venda do anime? (s/n): ");
            scanf(" %c", &opcao);
            if (opcao == 's' || opcao == 'S')
            {
                float novoPrecoVenda; // auxiliar para salvar o preco de venda
                printf("Digite o novo preco de venda: ");
                scanf("%f", &novoPrecoVenda);

                // verifica se o preco de venda é valido
                if (novoPrecoVenda <= 0 || novoPrecoVenda < estoque[i].precodecompra || novoPrecoVenda > 500)
                {
                    printf("ERRO... O preco de venda invalido!\n");
                }
                else
                {
                    estoque[i].precodevenda = novoPrecoVenda;
                    printf("Preco de venda atualizado!\n");
                }
            }

            printf("Deseja editar a quantidade de Blu-rays? (s/n): ");
            scanf(" %c", &opcao);
            if (opcao == 's' || opcao == 'S')
            {
                int novaQuantidade; // auxiliar para salvar a quantidade
                printf("Digite a nova quantidade de Blu-rays: ");
                scanf("%d", &novaQuantidade);

                if (novaQuantidade < 0)
                {
                    printf("ERRO... Quantidade invalida!\n");
                }
                else
                {
                    estoque[i].quantidadeBluRay = novaQuantidade;
                    printf("Quantidade de Blu-rays atualizada!\n");
                }
            }

            printf("\nAlteracoes concluidas!\n");
            return;
        }
    }

    printf("Nenhum anime encontrado com o ID %d.\n", idBusca);
}

void atualizarEstoque(struct Anime estoque[], int totalAnimes, int IDanime, int quantidade, int entrada)
{
    // verifica se o estoque esta vazio
    if (totalAnimes == 0)
    {
        printf("Nao ha animes cadastrados!\n");
        return;
    }

    // verifica se tem quantidade suficiente de Blu-rays
    if (quantidade <= 0)
    {
        printf("ERRO... Numero de Blu-rays invalido.\n");
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
            printf("====================================\n");

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
                    printf("ERRO... Nao ha quantidade suficiente no anime '%s'. Disponivel: %d Blu-rays.\n",
                           estoque[i].nome, estoque[i].quantidadeBluRay);
                }
            }
            else
            {
                printf("ERRO... Opcao invalida.\n");
            }

            return;
        }
    }

    printf("Nenhum anime encontrado com o ID %d.\n", IDanime);
}

int removerAnime(struct Anime estoque[], int totalAnimes)
{
    int opcao; // variavel auxiliar

    // menu de opções
    printf("\nDeseja buscar para remover por:\n");
    printf("1 - ID\n");
    printf("2 - Nome\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    if (opcao == 1)
    {
        // busca pelo ID
        int IDBusca;
        printf("Digite o ID do anime: ");
        scanf("%d", &IDBusca);

        // busca pelo ID
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

                // reorganiza e atualiza os IDs
                for (int j = 0; j < totalAnimes; j++)
                {
                    estoque[j].IDanime = j + 1;
                }

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

                // reorganiza e atualiza os IDs
                for (int j = 0; j < totalAnimes; j++)
                {
                    estoque[j].IDanime = j + 1;
                }

                printf("Anime removido!\n");

                return totalAnimes;
            }
        }
        printf("Nenhum anime encontrado com o nome '%s'.\n", nomeBusca);
    }
    else
    {
        printf("ERRO... Opcao invalida.\n");
    }

    return totalAnimes;
}

void gerarRelatorio(struct Anime estoque[], int totalAnimes)
{
    printf("\nRelatorio de Estoque:\n");
    printf("============================================================\n");

    // cabeçalho
    printf("ID || Nome || Genero || Preco de compra || Preco de venda || Quantidade de Blu-rays\n");
    printf("------------------------------------------------------------\n");

    // imprime o estoque
    for (int i = 0; i < totalAnimes; i++)
    {
        printf("%d || %s || %s || %.2f Reais || %.2f Reais || %d Unidades\n",
               estoque[i].IDanime,
               estoque[i].nome,
               estoque[i].genero,
               estoque[i].precodecompra,
               estoque[i].precodevenda,
               estoque[i].quantidadeBluRay);
    }

    printf("============================================================\n");
    printf("Quantidade total de animes cadastrados: %d\n", totalAnimes);
}