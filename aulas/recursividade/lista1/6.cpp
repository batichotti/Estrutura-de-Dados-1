#include <iostream>
#include <list>

void print_list(std::list<int>& lst, std::list<int>::iterator& it){
    if (it == lst.end()) return;
    std::cout << *it << std::endl;
    print_list(lst, ++it);
}

int main(int argc, char const *argv[]){
    std::list<int> lista = std::list<int>{2, 5, 7, 2};
    auto it = lista.begin();
    print_list(lista, it);
    return 0;
}
