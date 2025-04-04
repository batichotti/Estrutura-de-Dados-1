#include "lista_encadeada.hpp"
#include <cstdio>

LinkedList::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
}

LinkedList::~LinkedList() {

}

bool LinkedList::push_front(int key) {
    Node* node = new Node{key, nullptr};
    if (!node) return false;

    node->next = this->head;
    this->head = node->next;
    return true;
}

bool LinkedList::pop_front() {

}

int LinkedList::get(int pos) {

}

void LinkedList::print() {

}

int LinkedList::size() {

}

bool LinkedList::empty() {

}

void LinkedList::push_back(int key) {

}

bool LinkedList::pop_back() {

}

Node* LinkedList::find(int key) {

}

bool LinkedList::insert(int key, int pos) {

}

bool LinkedList::remove(int key) {

}

bool LinkedList::removeAt(int pos) {

}

bool LinkedList::insert_sorted(int key) {

}
