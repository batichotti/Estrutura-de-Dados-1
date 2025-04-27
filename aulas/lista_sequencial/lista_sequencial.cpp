#include <iostream>
#include <algorithm>
#include "lista_sequencial.hpp"

using namespace std;

ListSeq::ListSeq(int _capacity){
    data = new int[_capacity];
    capacity = _capacity;
}

void ListSeq::destroy(){
    delete[] data;
}

void  ListSeq::resize(){
    int* _data = new int[++capacity];
    for(int i = 0; i < size; i++){
        _data[i] = data[i];
    }
    delete[] data;
    data = _data;    
}

void ListSeq::add(int elem){
    if (size < capacity){
        data[size++] = elem;
    }
}

void ListSeq::remove(){
    if(!isEmpty()){
        size--;
    }
}

void ListSeq::removeAt(int pos) {
    if (pos < size) {
        for (int i = pos; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    } else if (pos == this->size){
        this->remove();
    }
}

bool ListSeq::isEmpty(){
    return (size == 0);
}

bool ListSeq::isFull(){
    return (size == capacity);
}

void ListSeq::print(){
    for (int i=0; i<size; i++){
        cout << data[i] << " ";
    }
    cout << endl;
}

int ListSeq::find(int elem){
    for (int i = 0; i < size; i++){
        if(elem == data[i]){
            return i;
        }
    }
    return -1;
}

int ListSeq::get(int pos){
    return data[pos];
}

void ListSeq::insert(int elem, int pos){
    if (pos <= size-1) {
        if (isFull()) {
            resize();
        }
        for (int i = size; i > pos; i--) {
            data[i] = data[i - 1];
        }
        data[pos] = elem;
        size++;
    }
}

void ListSeq::addSorted(int elem){
    if (isFull()) {
        resize();
    }
    for (int i = 0; i < size-1; i++){
        if (elem < data[i]){
            insert(elem, i);
            return;
        }
    }
    add(elem);
}

int ListSeq::list_get_available(){
    return (this->capacity-this->size);
}

void ListSeq::list_clear(){
    int tamanho = this->size;
    for (int i = 0; i < tamanho; i++){
        this->remove();
    }
}

void ListSeq::list_remove_last(int n){
    for (int i = 0; i < n; i++){
        this->remove();
    }
}

void ListSeq::list_print_reverse(){
    for (int i = this->size-1; i >= 0; i--){
        cout << this->data[i] << " ";
    }
}

int ListSeq::list_is_sorted(){
    int tamanho = this->size-1;
    for (int i = 0; i < tamanho; i++){
        if (this->data[i] > this->data[i+1]){
            return 0;
        }
    }
    return 1;
}