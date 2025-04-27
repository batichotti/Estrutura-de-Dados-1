#include "lista_encadeada.hpp"
#include <iostream>

using namespace std;

int main() {
    DoubleList list;

    list.push_front(9);
    list.push_front(7);
    list.push_front(3);
    
    list.insert(8, 2);
    list.push_back(8);
    list.pop_back();
    list.remove(7);
    list.insert_sorted(5);

    list.print();
    list.print_reverse();
    return 0;
}