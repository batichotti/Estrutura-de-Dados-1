#include <iostream>
#include <algorithm>

using namespace std; //a.k.a.: from xyz import *


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
    bool resize();

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
    bool add(int elem);

    // remove elemento do final
    bool remove();

    // insere elemento na posição especificada
    void insert(int elem, int pos);

    // remove elemento na posição especificada
    bool removeAt(int pos);

    // insere elemento em ordem crescente
    bool addSorted(int elem);

};
