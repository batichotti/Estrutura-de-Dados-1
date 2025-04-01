#include <iostream>
#include <algorithm>
#include "lista_sequencial.hpp"

using namespace std; //a.k.a.: from xyz import *

ListSeq::ListSeq(int _capacity){
    data = new int[_capacity];
    capacity = _capacity;
};

void ListSeq::destroy(){
    delete[] data;
};

void  ListSeq::resize(){
    int* _data = new int[++capacity];
    for(int i = 0; i < size;i++){
        _data[i] = data[i];
    }
    delete[] data;
    data = _data;    
};

void ListSeq::add(int elem){
    if (size < capacity){
        data[size++] = elem;
    }
};    

void ListSeq::remove(){
    if(!isEmpty()){
        size--;
    }
};

void ListSeq::removeAt(int pos) {
    if (pos < size) {
        for (int i = pos; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    }
};

bool ListSeq::isEmpty(){
    return (size == 0);
};

bool ListSeq::isFull(){
    return (size == capacity);
};

void ListSeq::print(){
    for (int i=0; i<size; i++){
        cout << data[i] << " ";
    }
    cout << endl;
};

int ListSeq::find(int elem){
    for (int i = 0; i < size; i++){
        if(elem == data[i]){
            return i;
        }
    }
};

int ListSeq::get(int pos){
    return data[pos];
};

void ListSeq::insert(int elem, int pos){};

void ListSeq::addSorted(int elem){};
