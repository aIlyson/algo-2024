# Projeto Algoritmos
==========================

**Resumo**
--------
Este é um projeto de gerenciamento de estoque de animes. Ele foi desenvolvido utilizando C e é composto por um menu principal que permite gerenciar o estoque de animes, consultar relatórios e sair do programa.

**Funcionalidades**
-----------------
* Gerenciamento de estoque de animes
* Consulta de relatórios do estoque
* Menu principal para navegação

**Requisitos**
-------------
* Compilador C
  - Para sistemas Windows, é recomendado o uso do [MinGW](https://sourceforge.net/projects/mingw/).
  - Para Linux ou macOS, você pode utilizar o GCC que já vem pré-instalado ou pode ser instalado com o `sudo apt install gcc` (Linux) ou `brew install gcc` (macOS).
* Uma IDE para desenvolvimento em C (Visual Studio recomendado).
  - Para utilizar o Visual Studio, baixe e instale a versão [Visual Studio Community](https://visualstudio.microsoft.com/pt-br/vs/community/).
* Sistema operacional compatível com C (Windows, Linux ou macOS).

**Instalação**
-------------
1. Clone o repositório:
   ```bash
   git clone https://github.com/aIlyson/algo-2024.git
   ```
2. Acesse a pasta do projeto:
   ```bash
   cd algo-2024
   ```
3. Compile o programa:
   - Se estiver usando o MinGW:
     ```bash
     gcc main.c methods/estoque.c -o algo-2024
     ```
   - Se estiver usando o Visual Studio, basta abrir o projeto no Visual Studio e compilar diretamente na IDE.
4. Execute o programa:
   - No MinGW ou Linux/macOS:
     ```bash
     ./algo-2024
     ```

**Página Methods**
-----------------
A pasta `methods` contém as funções que são utilizadas pelo programa para gerenciar o estoque de animes. Ela é composta por dois arquivos:

* `estoque.h`: cabeçalho que define a estrutura de dados para os animes.
* `estoque.c`: arquivo que contém as funções para gerenciar o estoque de animes.

**Estrutura do Projeto**
----------------------
* `main.c`: arquivo principal do programa.
* `methods/`: pasta que contém as funções para gerenciar o estoque de animes.
* `README.md`: este arquivo.

**Autores**
---------
* [Alysson](https://github.com/aIlyson)
* [Kleber](https://github.com/Kleber232)