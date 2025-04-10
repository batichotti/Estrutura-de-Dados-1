#include "lista_encadeada.hpp"
#include <iostream>

using namespace std;

int main() {
    LinkedList list;

    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    list.push_front(40);
    list.push_front(50);
    list.push_front(60);

    list.print();

    cout << "Size of the list: " << list.size() << endl;

    cout << "Is the list empty? " << (list.empty() ? "Yes" : "No") << endl;

    cout << "Popping front element..." << endl;
    list.pop_front();
    list.print();

    cout << "Inserting 70 at the front..." << endl;
    list.push_front(70);
    list.print();

    cout << "Finding element 30..." << endl;
    Node* found = list.find(30);
    if (found) {
        cout << "Element 30 found. Inserting 35 after it..." << endl;
        list.insert_after(35, found);
        list.print();
    } else {
        cout << "Element 30 not found." << endl;
    }

    cout << "Getting element at position 2..." << endl;
    int value = list.get(2);
    if (value != -1) {
        cout << "Element at position 2: " << value << endl;
    } else {
        cout << "Invalid position." << endl;
    }

    list.remove(30);
    list.print();
    list.removeAt(3);
    list.print();
    list.push_back(80);
    list.print();
    list.insert_sorted(79);
    list.print();

    return 0;
}