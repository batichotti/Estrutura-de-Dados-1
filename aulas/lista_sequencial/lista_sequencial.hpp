#pragma once

class ListSeq {
    public:
    int size = 0; // número de posições ocupadas
    int capacity; // capacidade da lista (tamanho do vetor)
    int* data; // endereço do vetor na heap
    
    // Operações de Criação e Acesso
    // construtor que cria a instância da lista
    ListSeq(int _capacity);

    // Libera a memória alocada para o vetor
    void destroy();

    // realoca vetor
    void resize();

    // imprime conteúdo da lista
    void print();

    // retorna posição do elemento ou -1
    int find(int elem);

    // obtém o elemento na posição passada
    int get(int pos);

    // lista vazia? Método auxiliar
    bool isEmpty();

    // lista cheia? Método auxiliar
    bool isFull();

    // Operações de Modificação
    // insere elemento no final
    void add(int elem);

    // remove elemento do final
    void remove();

    // insere elemento na posição especificada
    void insert(int elem, int pos);

    // remove elemento na posição especificada
    void removeAt(int pos);

    // insere elemento em ordem crescente
    void addSorted(int elem);

    // retorna a quantidade de posições livres restantes;
    int list_get_available();

    // remove todos os elementos da lista.
    void list_clear();

    // remove os últimos N elementos da lista ou o mais próximo disso
    void list_remove_last(int n);

    // imprime a lista de forma reversa
    void list_print_reverse();

    // verifica se a lista está ordenada
    int list_is_sorted();

    // cria uma cópia da lista
    ListSeq* list_copy();
};
