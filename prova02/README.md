# Prova 2 — Algoritmos e Estrutura de Dados 1
**Curso:** Ciência da Computação — UTFPR Campo Mourão  
**Alunos:** Arthur Vinicius Machado e Mateus Batichotti Silva

## Descrição Geral

Este projeto consiste na implementação, análise e comparação de algoritmos clássicos de ordenação e busca em vetores, utilizando arquivos binários para armazenamento dos dados. O objetivo é avaliar o desempenho (tempo e número de operações) dos algoritmos em diferentes cenários, conforme proposto na Prova 2 da disciplina de Algoritmos e Estrutura de Dados 1.

## Estrutura dos Arquivos

- **gerarBin.cpp**: Gera um arquivo binário com números inteiros aleatórios.
- **gerarOrdenado.cpp**: Gera um arquivo binário com números inteiros ordenados crescentemente.
- **ordenarBin.cpp**: Implementa os algoritmos de ordenação (Selection Sort, Selection Sort Otimizado, Bubble Sort, Bubble Sort Otimizado, Insertion Sort).
- **buscaBin.cpp**: Implementa as buscas sequencial e binária, com contagem de comparações.
- **cronometro.cpp**: Classe utilitária para medir e exibir o tempo de execução dos algoritmos.
- **analiseBin.cpp**: Realiza a análise comparativa dos algoritmos de ordenação, exibindo tempo e número de trocas/deslocamentos.
- **analiseBuscaBin.cpp**: Realiza a análise dos algoritmos de busca após ordenação, exibindo tempo e número de comparações.

## Como Utilizar

### 1. Gerar Arquivos de Dados

- **Aleatório:**  
    ```bash
    ./gerarBin <tamanho>
    ```
    Gera `random_<tamanho>_numbers.bin` com inteiros aleatórios.

- **Ordenado:**  
    ```bash
    ./gerarOrdenado
    ```
    Gera `vetor_ordenado.bin` com inteiros de 0 a 1.000.000.

> **Observação:** Os arquivos `random_10001_numbers.bin` e `random_1000001_numbers.bin` é gerado já ordenado.

### 2. Análise dos Algoritmos de Ordenação

```bash
./analiseBin <tamanho>
```
- Lê o arquivo `random_<tamanho>_numbers.bin` e executa todos os algoritmos de ordenação, exibindo tempo e número de trocas/deslocamentos.

### 3. Análise dos Algoritmos de Busca

```bash
./analiseBuscaBin <tamanho>
```
- Ordena o vetor com Insertion Sort e executa buscas sequencial e binária para um valor fixo, exibindo posição encontrada, tempo e número de comparações.

## Algoritmos Implementados

### Ordenação
- **Selection Sort**
- **Selection Sort Otimizado**
- **Bubble Sort**
- **Bubble Sort Otimizado**
- **Insertion Sort**

### Busca
- **Busca Sequencial**
- **Busca Binária** (apenas em vetores ordenados)

## Métricas Avaliadas

- **Tempo de execução:** Medido em microssegundos, milissegundos e segundos.
- **Número de trocas/deslocamentos:** Para ordenação.
- **Número de comparações:** Para buscas.

## Observações Técnicas

- Todos os algoritmos operam sobre vetores de inteiros lidos de arquivos binários.
- O diretório padrão para leitura dos arquivos de dados é `../dados/`.
- O valor buscado em `analiseBuscaBin.cpp` é fixo para fins de comparação.

## Compilação

Utilize um compilador C++ moderno (C++11 ou superior). Exemplo com g++:

```bash
g++ -std=c++11 -O2 -o gerarBin gerarBin.cpp
g++ -std=c++11 -O2 -o gerarOrdenado gerarOrdenado.cpp
g++ -std=c++11 -O2 -o analiseBin analiseBin.cpp
g++ -std=c++11 -O2 -o analiseBuscaBin analiseBuscaBin.cpp
```

## Créditos

Trabalho desenvolvido por **Mateus Batichotti Silva** e **Arthur Vinicius Machado** para a disciplina de Algoritmos e Estrutura de Dados 1 — UTFPR Campo Mourão, ministrada por Rodrigo Hubner.
