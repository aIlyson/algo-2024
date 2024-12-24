#include <stdio.h>
#include <string.h>
#include "estoque.h"

// aqui vai as funcoes
void cadastrarAnime(struct Anime estoque[], int *totalAnimes) {
    if (*totalAnimes >= 100) {
        printf("Erro: Estoque cheio. Não é possível cadastrar mais animes.\n");
        return;
    }

    struct Anime novoAnime;
    printf("Digite o nome do anime: ");
    getchar(); // Limpa o buffer do teclado
    fgets(novoAnime.nome, 100, stdin);
    novoAnime.nome[strcspn(novoAnime.nome, "\n")] = '\0'; // Remove o caractere de nova linha

    printf("Digite a quantidade inicial de Blu-rays: ");
    scanf("%d", &novoAnime.quantidadeBluRay);

    // Gera o código automaticamente
    novoAnime.codigo = *totalAnimes + 1;

    // Adiciona o novo anime ao estoque
    estoque[*totalAnimes] = novoAnime;

    // Incrementa o contador de animes cadastrados
    (*totalAnimes)++;

    printf("Anime cadastrado com sucesso! Codigo: %d\n", novoAnime.codigo);
}


void consultarAnime(struct Anime estoque[], int totalAnimes)
{
    if (totalAnimes == 0)
    {
        printf("O estoque está vazio!\n");
        return;
    }

    int opcao;
    printf("Deseja buscar por:\n");
    printf("1. Codigo\n");
    printf("2. Nome\n");
    printf("Escolha uma opção: ");
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
                return;
            }
        }
        printf("Nenhum anime encontrado com o codigo %d.\n", codigoBusca);
    }
    else if (opcao == 2)
    {
        char nomeBusca[100];
        printf("Digite o nome do anime: ");
        scanf(" %[^\n]s", nomeBusca);  // Lê a string com espaços

        for (int i = 0; i < totalAnimes; i++)
        {
            if (strcmp(estoque[i].nome, nomeBusca) == 0)
            {
                printf("\nAnime encontrado:\n");
                printf("Codigo: %d\n", estoque[i].codigo);
                printf("Nome: %s\n", estoque[i].nome);
                printf("Quantidade de Blu-rays: %d\n", estoque[i].quantidadeBluRay);
                return;
            }
        }
        printf("Nenhum anime encontrado com o nome '%s'.\n", nomeBusca);
    }
    else
    {
        printf("Opção inválida.\n");
    }
}
