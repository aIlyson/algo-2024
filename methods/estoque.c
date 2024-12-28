#include <stdio.h>
#include <string.h>
#include "estoque.h"
#include <stdlib.h>

// funções
void cadastrarAnime(struct Anime estoque[], int *totalAnimes)
{
<<<<<<< HEAD
    // verifica se o estoque esta cheio
    if (*totalAnimes >= 100) // limitei para 100
    {
        printf("Capacidade maxima atingida!\n");
=======
    system("cls");
    printf("adicionando anime...\n");
    if (*totalAnimes >= 100)
    {
        printf("Erro: Estoque cheio. Não eh possivel cadastrar mais animes.\n");
>>>>>>> 961c6f9dabcce4be2f0148f19eff99b45dc97c3d
        return;
    }

    struct Anime novoAnime;

    printf("Digite o nome do anime: ");
    scanf(" %[^\n]", novoAnime.nome); // le uma string com espaços (até o '\n')

    printf("Digite a quantidade inicial de Blu-rays: ");
    scanf("%d", &novoAnime.quantidadeBluRay);

<<<<<<< HEAD
    // gera um codigo para o novo anime
=======
    printf("digite o preco de compra: ");
    scanf("%f", &novoAnime.precocompra);

    printf("digite o preco de venda: ");
    scanf("%f", &novoAnime.precovenda);

    // Gera o código automaticamente
>>>>>>> 961c6f9dabcce4be2f0148f19eff99b45dc97c3d
    novoAnime.codigo = *totalAnimes + 1;

    // adiciona o novo anime e incrementa o contador
    estoque[*totalAnimes] = novoAnime;

    (*totalAnimes)++;

    printf("Anime cadastrado! Codigo: %d\n", novoAnime.codigo);
}
int consultarAnime(struct Anime estoque[], int totalAnimes)
{
<<<<<<< HEAD
    // verifica se o estoque esta vazio
=======
    system("cls");
    printf("consultando anime...\n");
>>>>>>> 961c6f9dabcce4be2f0148f19eff99b45dc97c3d
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
<<<<<<< HEAD
                return 0;
=======
                printf("Preco de compra: %.2f\n", estoque[i].precocompra);
                printf("Preco de venda: %.2f\n", estoque[i].precovenda);
                return 0; // Sucesso: anime encontrado
>>>>>>> 961c6f9dabcce4be2f0148f19eff99b45dc97c3d
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
<<<<<<< HEAD
                return 0;
=======
                printf("Preco de compra: %.2f\n", estoque[i].precocompra);
                printf("Preco de venda: %.2f\n", estoque[i].precovenda);
                return 0; // Sucesso: anime encontrado
>>>>>>> 961c6f9dabcce4be2f0148f19eff99b45dc97c3d
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
    system("cls");
    printf("editando anime...\n");
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
            printf("Preco de compra atual: %.2f\n", estoque[i].precocompra);
            printf("Preco de venda atual: %.2f\n", estoque[i].precovenda);

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

<<<<<<< HEAD
            printf("\nAnime editado!\n");
            return;
=======
            printf("Deseja editar o preco de compra? (s/n): ");
            scanf(" %c", &opcao);

            if (opcao == 's' || opcao == 'S')
            {
                printf("Digite o novo preco de compra: ");
                scanf("%f", &estoque[i].precocompra);
                printf("Preco de compra atualizado com sucesso!\n");
            }
            printf("Deseja editar o preco de venda? (s/n): ");
            scanf(" %c", &opcao);

            if (opcao == 's' || opcao == 'S')
            {
                printf("Digite o novo preco de venda: ");
                scanf("%f", &estoque[i].precovenda);
                printf("Preco de venda atualizado com sucesso!\n");
            }
            printf("\nEdicao concluida!\n");
            return; // Sai da função após editar
>>>>>>> 961c6f9dabcce4be2f0148f19eff99b45dc97c3d
        }
    }

    // caso não encontre o anime
    printf("Nenhum anime encontrado. Codigo inexistente: %d.\n", codigoBusca);
}
<<<<<<< HEAD

void atualizarEstoque(struct Anime estoque[], int totalAnimes, int codigo, int quantidade, int entrada)
{
    // verifica se o estoque esta vazio
    if (totalAnimes == 0)
    {
        printf("Nao ha animes cadastrados!\n");
        return;
    }

    // busca pelo anime pelo codigo
    for (int i = 0; i < totalAnimes; i++)
    {
        if (estoque[i].codigo == codigo)
=======
void atualizarEstoque(struct Anime estoque[], int totalAnimes, int codigo, int quantidade, int entrada)
{
    
    for (int i = 0; i < totalAnimes; i++) // percorre o estoque procurando o anime
    {
        if (estoque[i].codigo == codigo) // se for encontrado,continua, se nao, mostra uma mensagem de erro
>>>>>>> 961c6f9dabcce4be2f0148f19eff99b45dc97c3d
        {
            if (entrada == 1)
            {
                // operacao de entrada no estoque
                estoque[i].quantidadeBluRay += quantidade;
                printf("Adicionadas %d unidades ao estoque do anime '%s'. Novo total: %d Blu-rays.\n",
                       quantidade, estoque[i].nome, estoque[i].quantidadeBluRay);
            }
<<<<<<< HEAD
            else if (entrada == 0)
            {
                // operacao de saída do estoque
                if (estoque[i].quantidadeBluRay >= quantidade)
                {
                    estoque[i].quantidadeBluRay -= quantidade;
                    printf("Removidas %d unidades do estoque do anime '%s'. Novo total: %d Blu-rays.\n",
                           quantidade, estoque[i].nome, estoque[i].quantidadeBluRay);
                }
                else
                {
                    printf("error... Estoque insuficiente para o anime '%s'. Disponível: %d Blu-rays.\n",
=======
            else // se for diferente de 1,subtrai do estoque pq é a saída
            {
                if (estoque[i].quantidadeBluRay >= quantidade) // verifica se tem o suficiente
                {
                    estoque[i].quantidadeBluRay -= quantidade; // se sim,tira do estoque
                    printf("Removidas %d unidades do estoque do anime '%s'. Novo total: %d Blu-rays.\n",
                           quantidade, estoque[i].nome, estoque[i].quantidadeBluRay);
                }
                else // se nao,mensagem de erro
                {
                    printf("Erro: Estoque insuficiente para o anime '%s'. Disponivel: %d Blu-rays.\n",
>>>>>>> 961c6f9dabcce4be2f0148f19eff99b45dc97c3d
                           estoque[i].nome, estoque[i].quantidadeBluRay);
                }
            }
            else
            {
                printf("error... numero invalido\n");
            }
            return;
        }
    }
<<<<<<< HEAD

    // caso não encontre o anime
    printf("Nenhum anime encontrado com o codigo %d.\n", codigo);
}

void removerAnime(struct Anime estoque[], int *totalAnimes)
{
    // verifica se o estoque esta vazio
    if (*totalAnimes == 0)
    {
        printf("Nao ha animes cadastrados! Nada para remover.\n");
=======
    printf("Erro: Anime com codigo %d nao encontrado no estoque.\n", codigo);
}
void removerAnime(struct Anime estoque[], int *totalAnimes)
{
    system("cls");
    printf("removendo anime...\n");
    if (*totalAnimes == 0)
    {
        printf("O estoque esta vazio!\n");
>>>>>>> 961c6f9dabcce4be2f0148f19eff99b45dc97c3d
        return;
    }

    int opcao;

    // menu de opcoes
    printf("Deseja buscar para remover por:\n");
    printf("1. Codigo\n");
    printf("2. Nome\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

<<<<<<< HEAD
    // busca pelo codigo
=======
>>>>>>> 961c6f9dabcce4be2f0148f19eff99b45dc97c3d
    if (opcao == 1)
    {
        int codigoBusca;
        printf("Digite o codigo do anime: ");
        scanf("%d", &codigoBusca);

        for (int i = 0; i < *totalAnimes; i++)
        {
            if (estoque[i].codigo == codigoBusca)
            {
                printf("Removendo o anime '%s' com codigo %d...\n", estoque[i].nome, estoque[i].codigo);
<<<<<<< HEAD

                // remove o elemento do array e reorganiza
=======
                // Reorganiza o array para remover o elemento
>>>>>>> 961c6f9dabcce4be2f0148f19eff99b45dc97c3d
                for (int j = i; j < *totalAnimes - 1; j++)
                {
                    estoque[j] = estoque[j + 1];
                }
                (*totalAnimes)--;

                printf("Anime removido!\n");
                return;
            }
        }
        printf("Nenhum anime encontrado com o codigo %d.\n", codigoBusca);
    }
<<<<<<< HEAD
    // busca pelo nome
=======
>>>>>>> 961c6f9dabcce4be2f0148f19eff99b45dc97c3d
    else if (opcao == 2)
    {
        char nomeBusca[100];
        printf("Digite o nome do anime: ");
<<<<<<< HEAD
        scanf(" %[^\n]s", nomeBusca); // le a string com espaços
=======
        scanf(" %[^\n]s", nomeBusca); // Lê a string com espaços
>>>>>>> 961c6f9dabcce4be2f0148f19eff99b45dc97c3d

        for (int i = 0; i < *totalAnimes; i++)
        {
            if (strcmp(estoque[i].nome, nomeBusca) == 0)
            {
<<<<<<< HEAD
                printf("Removendo o anime '%s' com codigo %d...\n", estoque[i].nome, estoque[i].codigo);

                // remove o elemento do array e reorganiza
=======
                printf("Removendo o anime '%s' com código %d...\n", estoque[i].nome, estoque[i].codigo);
                // Reorganiza o array para remover o elemento
>>>>>>> 961c6f9dabcce4be2f0148f19eff99b45dc97c3d
                for (int j = i; j < *totalAnimes - 1; j++)
                {
                    estoque[j] = estoque[j + 1];
                }
                (*totalAnimes)--;

                printf("Anime removido!\n");
                return;
            }
        }
        printf("Nenhum anime encontrado com o nome '%s'.\n", nomeBusca);
    }
    else
    {
<<<<<<< HEAD
        printf("error... numero invalido\n");
    }
}

void gerarRelatorio(struct Anime estoque[], int totalAnimes)
{
    // verifica se o estoque esta vazio
    if (totalAnimes == 0)
    {
        printf("Nao ha animes cadastrados!\n");
=======
        printf("Opçao invalida.\n");
    }
}
void gerarRelatorio(struct Anime estoque[], int totalAnimes)
{
    system("cls");
    if (totalAnimes == 0)
    {
        printf("O estoque esta vazio!\n");
>>>>>>> 961c6f9dabcce4be2f0148f19eff99b45dc97c3d
        return;
    }

    printf("\nRelatorio de Estoque:\n");
    printf("----------------------\n");
<<<<<<< HEAD

    // imprime os animes
=======
>>>>>>> 961c6f9dabcce4be2f0148f19eff99b45dc97c3d
    for (int i = 0; i < totalAnimes; i++)
    {
        printf("Anime %d:\n", i + 1);
        printf("  Codigo: %d\n", estoque[i].codigo);
        printf("  Nome: %s\n", estoque[i].nome);
        printf("  Quantidade de Blu-rays: %d\n", estoque[i].quantidadeBluRay);
        printf("  Preco de compra: %.2f\n", estoque[i].precocompra);
        printf("  Preco de venda: %.2f\n", estoque[i].precovenda);
        printf("----------------------\n");
    }

    printf("Quantidade total de animes cadastrados: %d\n", totalAnimes);
}
<<<<<<< HEAD
=======
void realizarvenda(struct Anime estoque[], int totalAnimes, float *caixa)
{
    system("cls");
    if (totalAnimes == 0)
    {
        printf("O estoque esta vazio! Nenhum anime disponivel para venda.\n");
        return;
    }

    int codigoBusca, quantidadeVenda;
    printf("Digite o codigo do anime que deseja vender: ");
    scanf("%d", &codigoBusca);

    for (int i = 0; i < totalAnimes; i++)
    {
        if (estoque[i].codigo == codigoBusca)
        {
            printf("Anime encontrado: %s\n", estoque[i].nome);
            printf("Quantidade disponivel: %d\n", estoque[i].quantidadeBluRay);
            printf("Preco de venda: %.2f\n", estoque[i].precovenda);

            printf("Digite a quantidade a ser vendida: ");
            scanf("%d", &quantidadeVenda);

            if (estoque[i].quantidadeBluRay >= quantidadeVenda)
            {
                float valorVenda = (float)quantidadeVenda * estoque[i].precovenda;
                estoque[i].quantidadeBluRay -= quantidadeVenda;
                *caixa += valorVenda;

                printf("Venda realizada com sucesso!\n");
                printf("Recibo:\n");
                printf("  Nome do Anime: %s\n", estoque[i].nome);
                printf("  Quantidade vendida: %d\n", quantidadeVenda);
                printf("  Valor total: R$ %.2f\n", valorVenda);
                printf("  Estoque restante: %d\n", estoque[i].quantidadeBluRay);
                return;
            }
            else
            {
                printf("Erro: Estoque insuficiente. Disponivel: %d\n", estoque[i].quantidadeBluRay);
                return;
            }
        }
    }

    printf("Erro: Anime com codigo %d nao encontrado.\n", codigoBusca);
}
>>>>>>> 961c6f9dabcce4be2f0148f19eff99b45dc97c3d
