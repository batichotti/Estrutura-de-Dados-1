#include "lista_circular.hpp"
#include <cstdio>
#include <iostream>

using namespace std;

CircleList::CircleList() {
    this->head = nullptr;
    this->tail = nullptr;
}

CircleList::~CircleList() {
    if (!this->head) return;

    Node* node = this->head;
    do {
        Node* next = node->next;
        delete node;
        node = next;
    } while (node != this->head);

    this->head = nullptr;
    this->tail = nullptr;
}

bool CircleList::push_front(int key) {
    Node* node = new Node{key, nullptr};
    if (!node) return false;

    if (!this->head) {
        this->head = node;
        this->tail = node;
        node->next = node;
    } else {
        node->next = this->head;
        this->head = node;
        this->tail->next = this->head;
    }
    return true;
}

bool CircleList::pop_front() {
    if (!this->head) return false;

    Node* node = this->head;
    if (this->head == this->tail) {
        this->head = nullptr;
        this->tail = nullptr;
    } else {
        this->head = node->next;
        this->tail->next = this->head;
    }
    delete node;
    return true;
}

int CircleList::get(int pos) {
    if (pos >= size() || pos < 0) return -1;

    Node* node = this->head;
    for (int i = 0; i < pos; i++) {
        node = node->next;
    }
    return node->key;
}

bool CircleList::equals(CircleList* other) {
    if (this->size() != other->size()) return false;

    Node* a1 = this->head;
    Node* a2 = other->head;

    do {
        if (a1->key != a2->key) {
            return false;
        }
        a1 = a1->next;
        a2 = a2->next;
    } while (a1 != this->head && a2 != other->head);

    return true;
}

void CircleList::print() {
    if (!this->head) {
        cout << "List is empty" << endl;
        return;
    }

    Node* node = this->head;
    cout << " head -> ";
    do {
        cout << node->key << " -> ";
        node = node->next;
    } while (node != this->head);
    cout << " <- tail" << endl;
}

int CircleList::size() {
    if (!this->head) return 0;

    int size = 0;
    Node* node = this->head;
    do {
        size++;
        node = node->next;
    } while (node != this->head);
    return size;
}

bool CircleList::empty() {
    return this->head == nullptr;
}

bool CircleList::push_back(int key) {
    Node* node = new Node{key, nullptr};
    if (!node) return false;

    if (!this->head) {
        this->head = node;
        this->tail = node;
        node->next = node;
    } else {
        this->tail->next = node;
        node->next = this->head;
        this->tail = node;
    }
    return true;
}

bool CircleList::pop_back() {
    if (!this->tail) return false;

    if (this->head == this->tail) {
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
        return true;
    }

    Node* node = this->head;
    while (node->next != this->tail) {
        node = node->next;
    }

    node->next = this->head;
    delete this->tail;
    this->tail = node;

    return true;
}

Node* CircleList::find(int key) {
    if (!this->head) return nullptr;

    Node* node = this->head;
    do {
        if (node->key == key) {
            return node;
        }
        node = node->next;
    } while (node != this->head);

    return nullptr;
}

bool CircleList::insert_after(int key, Node* pos) {
    if (!pos) return false;

    Node* node = new Node{key, pos->next};
    pos->next = node;

    if (pos == this->tail) {
        this->tail = node;
    }
    return true;
}

bool CircleList::remove(int key) {
    if (!this->head) return false;

    if (this->head->key == key) {
        return pop_front();
    }

    Node* prev = this->head;
    Node* node = this->head->next;

    while (node != this->head) {
        if (node->key == key) {
            prev->next = node->next;
            if (node == this->tail) {
                this->tail = prev;
            }
            delete node;
            return true;
        }
        prev = node;
        node = node->next;
    }

    return false;
}

bool CircleList::insert(int key, int pos) {
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

    if (node == this->tail) {
        this->tail = new_node;
    }

    return true;
}

bool CircleList::removeAt(int pos) {
    if (pos >= this->size() || pos < 0) return false;

    if (pos == 0) {
        return this->pop_front();
    }

    Node* prev = this->head;
    Node* node = this->head->next;

    for (int i = 1; i < pos; i++) {
        prev = node;
        node = node->next;
    }

    prev->next = node->next;
    if (node == this->tail) {
        this->tail = prev;
    }
    delete node;

    return true;
}

bool CircleList::insert_sorted(int key) {
    if (!this->head || this->head->key >= key) {
        return this->push_front(key);
    }

    Node* node = this->head;
    while (node->next != this->head && node->next->key < key) {
        node = node->next;
    }

    Node* new_node = new Node{key, node->next};
    node->next = new_node;

    if (node == this->tail) {
        this->tail = new_node;
    }
    return true;
}
