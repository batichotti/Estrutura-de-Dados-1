#pragma once
class Node {
    public:
        int key;
        Node* next;
        Node* prev;
};

class DoubleList { // Lista Duplamente Encadeada
    private:
        Node* head; // Primeiro elemento da árvore
        Node* tail; // Último elemento da árvore
    public:
        DoubleList(); // Método Construtor
        ~DoubleList(); // Método Destrutor
        bool push_front(int key); // Coloca no começo
        bool pop_front(); // Destrói o primeiro
        void print(); // Imprime todos os valores
        int size(); // Obtém o tamanho da lista
        bool empty(); // Está vazia?
        bool push_back(int key); // Coloca no final
        bool pop_back(); // Destrói o final
        int get(int pos); // Obtém no enésimo nó
        Node* find(int key); // Encontra o vetor
        bool insert_after(int key, Node* pos); // Insere imediantamente após Node
        bool remove_after(Node* pos); // Remove imediatamente após Node
        bool insert(int key, int pos); // Insere na posição
        bool removeAt(int pos); // Remove na posição
        bool remove(int key); // Remove a primeira aparição do valor
        bool insert_sorted(int key); // Insere ordenado
        bool equals(DoubleList* other); // Compara duas listas
};