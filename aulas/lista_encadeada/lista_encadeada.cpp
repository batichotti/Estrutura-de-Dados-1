#include "lista_encadeada.hpp"
#include <cstdio>
#include <iostream>

using namespace std;

LinkedList::LinkedList() {
    this->head = nullptr;
    // this->tail = nullptr;
}

LinkedList::~LinkedList() {
    Node* node = this->head;
    while (node) {
        Node* next = node->next;
        delete node;
        node = next;
    }
    this->head = nullptr;
}

bool LinkedList::push_front(int key) {
    Node* node = new Node{key, nullptr};
    if (!node) return false;

    node->next = this->head;
    this->head = node;
    return true;
}

bool LinkedList::pop_front() {
    if (!this->head) return false;
    Node* node = this->head;

    this->head = node->next;
    delete(node);
    return true;
}

int LinkedList::get(int pos) {
    if (pos > size()) return -1;
    Node* node = this->head;
    for (int i = 0; i < pos; i++){
        node = node->next;
    }
    return node->key;
}

bool LinkedList::equals(LinkedList* other){
    Node* a1 = this->head;
    Node* a2 = other->head;
    
    while (a1 && a2){
        if (a1->key == a2->key){
            a1 = a1->next;
            a2 = a2->next;
        } else {
            return false;
        }
    }
    return true;
}

void LinkedList::print() {
    Node* node = this->head;
    while(node){
        cout << node->key << "->";
        node = node->next;
    }
    cout << endl;
}

int LinkedList::size() {
    int size = 0;
    Node* node = this->head;
    while (node){
        size++;
        node = node->next;
    }
    return size;
}

bool LinkedList::empty() {
    if(!this->head) return true;
    return false;
}

void LinkedList::push_back(int key) {
    if (!this->head) return;
    Node* node = this->head;
    Node* new_node = new Node{key, nullptr};

    while (node && node->next) {
        node = node->next;
    }
    node->next = new_node;
}

bool LinkedList::pop_back() {
    if (!this->head) return false;
    Node* node = this->head;

    while (node && node->next) {
        node = node->next;
    }
    delete node->next;
    node->next = nullptr;
    return true;
}

Node* LinkedList::find(int key) {
    Node* node = this->head;
    while (node) {
        if (node->key == key) {
            return node;
        }
        node = node->next;
    }
    return nullptr;
}

bool LinkedList::insert_after(int key, Node* pos) {
    Node* node = new Node{key, pos->next};
    pos->next = node;
    return true;
}

bool LinkedList::remove(int key) {
    Node* node = this->head;

    if (node && node->key == key) {
        this->head = node->next;
        delete node;
        return true;
    }

    while (node && node->next) {
        if (node->next->key == key) {
            Node* to_delete = node->next;
            node->next = node->next->next;
            delete to_delete;
            return true;
        }
        node = node->next;
    }

    return false;
}

bool LinkedList::insert(int key, int pos) {
    if (pos > this->size() || pos < 0) return false;

    if (pos == 0) return this->push_front(key);

    Node* node = this->head;

    for (int i = 0; i < pos-1; i++) node = node->next;

    Node* novo = new Node{key, node->next};
    node->next = novo;
    return true;
}

bool LinkedList::removeAt(int pos) {
    if (pos > this->size() || pos < 0) return false;
    
    Node* node = this->head;
    for (int i= 0; i < pos-1;i++){
        node = node->next;
    }
    Node* to_delete = node->next;
    node->next = to_delete->next;
    delete to_delete;

    return true;
}

bool LinkedList::insert_sorted(int key) {
    if (!this->head || this->head->key > key) {
        Node* new_node = new Node{key, this->head};
        this->head = new_node;
        return true;
    }

    Node* node = this->head;
    while (node->next && node->next->key < key) {
        node = node->next;
    }

    Node* new_node = new Node{key, node->next};
    node->next = new_node;
    return true;
}
