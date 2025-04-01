#include <iostream>
#include <algorithm>
#include "lista_sequencial.hpp"

using namespace std; //a.k.a.: from xyz import *

ListSeq::ListSeq(int _capacity){
    data = new int[_capacity];
    capacity = _capacity;
};

void ListSeq::destroy(){

};

bool ListSeq::resize(){
    int* _data = new int[++capacity];
    for(int i = 0; i < size;i++){
        _data[i] = data[i];
    }
    delete[] data;
    data = _data;
    return true;
};

bool ListSeq::add(int elem){
    if (size < capacity){
        data[size++] = elem;
        return true;
    } else {
        return false;
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
