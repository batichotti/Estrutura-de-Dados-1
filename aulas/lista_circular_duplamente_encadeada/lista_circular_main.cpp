#include "lista_circular.hpp"
#include <iostream>

using namespace std;

int main() {
    CircleList list;

    list.push_front(9);
    list.push_front(7);
    list.push_front(3);

    list.print();

    list.insert(8, 2);
    list.print();

    return 0;
}