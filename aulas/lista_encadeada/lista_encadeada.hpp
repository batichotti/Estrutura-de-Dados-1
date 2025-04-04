#pragma once
class Node {
    public:
        int key;
        Node* next;
};

    class LinkedList { // Primeiro elemento da árvore
        private:
        Node* head;
        Node* tail;
    public:
        LinkedList(); // Método Construtor
        ~LinkedList(); // Método Destrutor
        bool push_front(int key); // Coloca no começo
        bool pop_front(); // Destrói o primeiro
        int get(int pos); // Obtém no enésimo nó
        void print(); // Imprime todos os valores
        int size(); // Obtém o tamanho da lista
        bool empty(); // Está vazia?
        void push_back(int key); // Coloca no final
        bool pop_back(); // Destrói o final
        Node* find(int key); // Enconra o vetor
        bool insert_after(int key, Node* pos); // Insere imediantamente após Node
        bool remove_after(Node* pos); // Remove imediatamente após Node
        bool insert(int key, int pos); // Insere na posição
        bool removeAt(int pos); // Remove na posição
        bool remove(int key); // Remove a primeira aparição do valor
        bool insert_sorted(int key); // Insere ordenado
};