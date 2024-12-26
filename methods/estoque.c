#include <stdio.h>
#include <string.h>
#include "estoque.h"

// aqui vai as funcoes
void cadastrarAnime(struct Anime estoque[], int *totalAnimes)
{
    if (*totalAnimes >= 100)
    {
        printf("Erro: Estoque cheio. Não eh possivel cadastrar mais animes.\n");
        return;
    }

    struct Anime novoAnime;
    printf("Digite o nome do anime: ");
    getchar(); // Limpa o buffer do teclado
    fgets(novoAnime.nome, 100, stdin);
    novoAnime.nome[strcspn(novoAnime.nome, "\n")] = '\0'; // Remove o caractere de nova linha

    printf("Digite a quantidade inicial de Blu-rays: ");
    scanf("%d", &novoAnime.quantidadeBluRay);

    printf("digite o preco de compra: ");
    scanf("%f", &novoAnime.precocompra);

    printf("digite o preco de venda: ");
    scanf("%f", &novoAnime.precovenda);

    // Gera o código automaticamente
    novoAnime.codigo = *totalAnimes + 1;

    // Adiciona o novo anime ao estoque
    estoque[*totalAnimes] = novoAnime;

    // Incrementa o contador de animes cadastrados
    (*totalAnimes)++;

    printf("Anime cadastrado com sucesso! Codigo: %d\n", novoAnime.codigo);
}

int consultarAnime(struct Anime estoque[], int totalAnimes)
{
    if (totalAnimes == 0)
    {
        printf("O estoque esta vazio!\n");
        return 1; // Estoque vazio
    }

    int opcao;
    printf("Deseja buscar por:\n");
    printf("1. Codigo\n");
    printf("2. Nome\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    if (opcao == 1)
    {
        int codigoBusca;
        printf("Digite o codigo do anime: ");
        scanf("%d", &codigoBusca);

        for (int i = 0; i < totalAnimes; i++)
        {
            if (estoque[i].codigo == codigoBusca)
            {
                printf("\nAnime encontrado:\n");
                printf("Codigo: %d\n", estoque[i].codigo);
                printf("Nome: %s\n", estoque[i].nome);
                printf("Quantidade de Blu-rays: %d\n", estoque[i].quantidadeBluRay);
                printf("Preco de compra: %.2f\n", estoque[i].precocompra);
                printf("Preco de venda: %.2f\n", estoque[i].precovenda);
                return 0; // Sucesso: anime encontrado
            }
        }
        printf("Nenhum anime encontrado com o codigo %d.\n", codigoBusca);
        return 0;
    }
    else if (opcao == 2)
    {
        char nomeBusca[100];
        printf("Digite o nome do anime: ");
        scanf(" %[^\n]s", nomeBusca); // Lê a string com espaços

        for (int i = 0; i < totalAnimes; i++)
        {
            if (strcmp(estoque[i].nome, nomeBusca) == 0)
            {
                printf("\nAnime encontrado:\n");
                printf("Codigo: %d\n", estoque[i].codigo);
                printf("Nome: %s\n", estoque[i].nome);
                printf("Quantidade de Blu-rays: %d\n", estoque[i].quantidadeBluRay);
                printf("Preco de compra: %.2f\n", estoque[i].precocompra);
                printf("Preco de venda: %.2f\n", estoque[i].precovenda);
                return 0; // Sucesso: anime encontrado
            }
        }
        printf("Nenhum anime encontrado com o nome '%s'.\n", nomeBusca);
        return 0;
    }
    else
    {
        printf("Opção invalida.\n");
        return 0;
    }
}

void editarAnime(struct Anime estoque[], int totalAnimes)
{
    if (totalAnimes == 0)
    {
        printf("O estoque esta vazio! Nada para editar.\n");
        return;
    }

    int codigoBusca;
    printf("Digite o codigo do anime que deseja editar: ");
    scanf("%d", &codigoBusca);

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
            printf("Deseja editar o nome do anime? (s/n): ");
            scanf(" %c", &opcao);

            if (opcao == 's' || opcao == 'S')
            {
                printf("Digite o novo nome do anime: ");
                scanf(" %[^\n]s", estoque[i].nome); // Lê a string com espaços
                printf("Nome atualizado com sucesso!\n");
            }

            printf("Deseja editar a quantidade de Blu-rays? (s/n): ");
            scanf(" %c", &opcao);

            if (opcao == 's' || opcao == 'S')
            {
                printf("Digite a nova quantidade de Blu-rays: ");
                scanf("%d", &estoque[i].quantidadeBluRay);
                printf("Quantidade de Blu-rays atualizada com sucesso!\n");
            }

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
        }
    }

    printf("Nenhum anime encontrado com o codigo %d.\n", codigoBusca);
}
void atualizarEstoque(struct Anime estoque[], int totalAnimes, int codigo, int quantidade, int entrada)
{
    for (int i = 0; i < totalAnimes; i++)//percorre o estoque procurando o anime
    {
        if (estoque[i].codigo == codigo) //se for encontrado,continua, se nao, mostra uma mensagem de erro
        {
            if (entrada==1)
            {
                estoque[i].quantidadeBluRay += quantidade;
                printf("Adicionadas %d unidades ao estoque do anime '%s'. Novo total: %d Blu-rays.\n",
                       quantidade, estoque[i].nome, estoque[i].quantidadeBluRay);
            }
            else//se for diferente de 1,subtrai do estoque pq é a saída
            {
                if (estoque[i].quantidadeBluRay >= quantidade)//verifica se tem o suficiente
                {
                    estoque[i].quantidadeBluRay -= quantidade;//se sim,tira do estoque
                    printf("Removidas %d unidades do estoque do anime '%s'. Novo total: %d Blu-rays.\n",
                           quantidade, estoque[i].nome, estoque[i].quantidadeBluRay);
                }
                else//se nao,mensagem de erro
                {
                    printf("Erro: Estoque insuficiente para o anime '%s'. Disponivel: %d Blu-rays.\n",
                           estoque[i].nome, estoque[i].quantidadeBluRay);
                }
            }
            return; // Anime encontrado e estoque atualizado
        }
    }
    printf("Erro: Anime com codigo %d nao encontrado no estoque.\n", codigo);
}
void removerAnime(struct Anime estoque[], int *totalAnimes) {
    if (*totalAnimes == 0) {
        printf("O estoque esta vazio!\n");
        return;
    }

    int opcao;
    printf("Deseja buscar para remover por:\n");
    printf("1. Codigo\n");
    printf("2. Nome\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        int codigoBusca;
        printf("Digite o codigo do anime: ");
        scanf("%d", &codigoBusca);

        for (int i = 0; i < *totalAnimes; i++) {
            if (estoque[i].codigo == codigoBusca) {
                printf("Removendo o anime '%s' com codigo %d...\n", estoque[i].nome, estoque[i].codigo);
                // Reorganiza o array para remover o elemento
                for (int j = i; j < *totalAnimes - 1; j++) {
                    estoque[j] = estoque[j + 1];
                }
                (*totalAnimes)--;
                printf("Anime removido com sucesso!\n");
                return;
            }
        }
        printf("Nenhum anime encontrado com o codigo %d.\n", codigoBusca);
    } else if (opcao == 2) {
        char nomeBusca[100];
        printf("Digite o nome do anime: ");
        scanf(" %[^\n]s", nomeBusca);  // Lê a string com espaços

        for (int i = 0; i < *totalAnimes; i++) {
            if (strcmp(estoque[i].nome, nomeBusca) == 0) {
                printf("Removendo o anime '%s' com código %d...\n", estoque[i].nome, estoque[i].codigo);
                // Reorganiza o array para remover o elemento
                for (int j = i; j < *totalAnimes - 1; j++) {
                    estoque[j] = estoque[j + 1];
                }
                (*totalAnimes)--;
                printf("Anime removido com sucesso!\n");
                return;
            }
        }
        printf("Nenhum anime encontrado com o nome '%s'.\n", nomeBusca);
    } else {
        printf("Opçao invalida.\n");
    }
}
void gerarRelatorio(struct Anime estoque[], int totalAnimes) {
    if (totalAnimes == 0) {
        printf("O estoque esta vazio!\n");
        return;
    }

    printf("\nRelatorio de Estoque:\n");
    printf("----------------------\n");
    for (int i = 0; i < totalAnimes; i++) {
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

