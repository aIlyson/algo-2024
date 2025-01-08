# Projeto Algoritmos

Professor: Alan Rafael Ferreira dos Santos

Autores: [Alysson Michel](https://github.com/aIlyson) e [Kleber Moura](https://github.com/Kleber232).

---

## Resumo

Este é um projeto de gerenciamento de estoque de animes. Ele foi desenvolvido utilizando C e é composto por um menu principal que permite gerenciar o estoque de animes, consultar relatórios, acessar o menu financeiro e sair do programa.

## Funcionalidades

- [x] Navegação entre menus principais e secundários
- [x] Gerenciar estoque de animes (adicionar, consultar, editar, atualizar e remover animes)
- [x] Gerar relatórios do estoque e financeiro
- [x] Realizar vendas de animes
- [x] Consultar caixa

### Features

- [x] Listas em tabelas
- [ ] GUI colorida

## Requisitos

- MinGW (para sistemas Windows) ou GCC (para sistemas Linux/macOS)
- IDE para desenvolvimento em C (como Visual Studio Community)
- Sistema operacional compatível: Windows, Linux ou macOS
- GitHub account (for GitHub OAuth)
- Leia o guia do programa

## Instalação

Se você não tem o Git instalado, pode baixar o repositório de forma manual:

1. Acesse o repositório no GitHub: [https://github.com/aIlyson/algo-2024](https://github.com/aIlyson/algo-2024).
2. Clique no botão **Code** e depois em **Download ZIP** para baixar o arquivo compactado.
3. Extraia o arquivo em uma pasta de sua escolha.

Após isso, siga as instruções abaixo para compilar e rodar o projeto.

1. Acesse a pasta do projeto:
   ```bash
   cd algo-2024
   ```
2. Compile o programa:
   - Se estiver usando o MinGW:
     ```bash
     gcc main.c methods/estoque.c methods/financeiros.c -o output/algo-2024
     ```
   - Se estiver usando o Visual Studio, basta abrir o projeto no Visual Studio e compilar diretamente na IDE.
3. Execute o programa:
   - No MinGW ou Linux/macOS:
     ```bash
     ./output/algo-2024
     ```

## Makefile

Se preferir, pode usar o Makefile para facilitar a compilação. Para isso, basta rodar o comando:

```bash
make
```

Para sistemas Windows utilizando o MinGW:

```bash
mingw32-make
```

Isso irá compilar o programa automaticamente, utilizando as opções definidas no Makefile.

## ☕ Estrutura do Projeto

```
src/
    .idea/                 # Arquivos de configuração do IDE
    .vscode/               # Arquivos de configuração do VS Code
    build/                 # Pasta de saída para binários
    methods/               # Implementação de funcionalidades específicas
        build/             # Arquivos gerados durante a compilação
            estoque.o      # Objeto compilado de estoque.c
            financeiro.o   # Objeto compilado de financeiro.c
            estoque.exe    # Executável gerado no Windows
        estoque.h          # Cabeçalho do módulo de estoque
        estoque.c          # Funções do menu de estoque
        financeiro.h       # Cabeçalho do financeiro
        financeiro.c       # Funções do menu financeiro
    output/                # Saída principal do executável
        main.o             # Arquivo objeto principal
        algo-2024          # Executável principal (gerado pelo Makefile)
    main.c                 # Arquivo principal do programa
    Makefile               # Automação do processo de compilação
    README.md              # Documento do projeto
```

---

## Arquitetura

Existem diversos padrões de projeto, como MVC (Model-View-Controller), Clean Architecture e Monolítica.

- **O padrão usado nesse projeto é modular**, separando as funcionalidades principais em módulos independentes para facilitar a manutenção e a reutilização do código.

---

### Camadas do Projeto

- **Interface (main.c):** Responsável por receber as interações do usuário e exibir os resultados.
- **Lógica de Negócio (methods/):** Contém a implementação das funcionalidades principais, como o gerenciamento de estoque e financeiro.
- **Automação (Makefile):** Facilita o processo de compilação e geração do executável.

---

## Página Build

A pasta `build` é onde o código fonte compilado será armazenado. O conteúdo gerado pela compilação será salvo aqui, separando o código fonte original dos binários gerados.

- **Exemplo de arquivos na pasta build:**
  - `estoque.o`: Objeto compilado do módulo de estoque.
  - `financeiro.o`: Objeto compilado do módulo financeiro.
  - `estoque.exe`: Executável gerado para sistemas Windows.

---

## Página Methods

A pasta `methods` contém as funções que são utilizadas pelo programa para gerenciar o estoque de animes e o menu financeiro. Ela é composta pelos seguintes arquivos:

- **`estoque.h`:**  
  Cabeçalho que define a estrutura de dados para os animes e as assinaturas das funções relacionadas ao estoque.

- **`estoque.c`:**  
  Arquivo que contém a implementação das funções para gerenciar o estoque de animes, como adicionar, editar ou remover.

- **`financeiro.h`:**  
  Cabeçalho que define as funções relacionadas ao menu financeiro, incluindo estruturas para representar operações financeiras.

- **`financeiro.c`:**  
  Arquivo que contém a implementação das funções para gerenciar as informações financeiras, como calcular receitas e despesas.
