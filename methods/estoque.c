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

