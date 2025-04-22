#include "lista_encadeada.hpp"
#include <cstdio>
#include <iostream>

using namespace std;

DoubleList::DoubleList() {
    this->head = nullptr;
    this->tail = nullptr;
}

DoubleList::~DoubleList() {
    Node* node = this->head;
    while (node) {
        Node* next = node->next;
        delete node;
        node = next;
    }
}

bool DoubleList::push_front(int key) {
    Node* node = new Node{key, this->head, nullptr};
    if (!node) return false;
    this->head = node;
    if (node->next)
        node->next->prev = node;
    else
        this->tail = node;
    return true;
}

bool DoubleList::pop_front() {
    if (!this->head) return false;
    Node* node = this->head;
    this->head = node->next;
    if (!this->head) this->tail = nullptr;
    delete node;
    return true;
}

int DoubleList::get(int pos) {
    if (pos >= size() || pos < 0) return -1;
    Node* node = this->head;
    for (int i = 0; i < pos; i++) {
        node = node->next;
    }
    return node->key;
}

bool DoubleList::equals(DoubleList* other) {
    Node* a1 = this->head;
    Node* a2 = other->head;

    while (a1 && a2) {
        if (a1->key != a2->key) {
            return false;
        }
        a1 = a1->next;
        a2 = a2->next;
    }
    return a1 == nullptr && a2 == nullptr;
}

void DoubleList::print() {
    Node* node = this->head;
    cout << "|| head -> ";
    while (node) {
        cout << node->key << " <-> ";
        node = node->next;
    }
    cout << "|| <- tail" << endl;
}

int DoubleList::size() {
    int size = 0;
    Node* node = this->head;
    while (node) {
        size++;
        node = node->next;
    }
    return size;
}

bool DoubleList::empty() {
    return this->head == nullptr;
}

bool DoubleList::push_back(int key) {
    Node* new_node = new Node{key, nullptr, nullptr};
    if (this->tail){
        this->tail->next = new_node;
        new_node->prev = this->tail;
        this->tail = new_node;
        return true;
    } else {
        this->head = new_node;
        this->tail = new_node;
        return true;
    }
    return true;
}

bool DoubleList::pop_back() {
    if (!this->tail) {
        return false;
    } else if (!this->tail->prev){
        delete this->tail;
        this->tail = nullptr;
        this->head = nullptr;
        return true;
    }
    Node* node = this->tail->prev;
    delete this->tail;
    this->tail = node;
    node->next = nullptr;
    return true;
}

Node* DoubleList::find(int key) {
    Node* node = this->head;
    while (node) {
        if (node->key == key) {
            return node;
        }
        node = node->next;
    }
    return nullptr;
}

bool DoubleList::insert_after(int key, Node* pos) {
    if (!pos) return false;
    Node* node = new Node{key, pos->next, pos};
    pos->next = node;
    return true;
}

bool DoubleList::remove(int key) {
    if (!this->head) return false;

    if (this->head->key == key) {
        Node* to_delete = this->head;
        this->head = this->head->next;
        delete to_delete;
        return true;
    }

    Node* node = this->head;
    while (node->next) {
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

bool DoubleList::insert(int key, int pos) {
    if (pos > this->size() || pos < 0) return false;

    if (pos == 0) {
        return this->push_front(key);
    }

    Node* node = this->head;
    for (int i = 0; i < pos - 1; i++) {
        node = node->next;
    }

    Node* new_node = new Node{key, node->next};
    node->next = new_node;
    return true;
}

bool DoubleList::removeAt(int pos) {
    if (pos >= this->size() || pos < 0) return false;

    if (pos == 0) {
        return this->pop_front();
    }

    Node* node = this->head;
    for (int i = 0; i < pos - 1; i++) {
        node = node->next;
    }

    Node* to_delete = node->next;
    node->next = to_delete->next;
    delete to_delete;

    return true;
}

bool DoubleList::insert_sorted(int key) {
    if (!this->head || this->head->key > key) {
        return this->push_front(key);
    }

    Node* node = this->head;
    while (node->next && node->next->key < key) {
        node = node->next;
    }

    Node* new_node = new Node{key, node->next};
    node->next = new_node;
    return true;
}
