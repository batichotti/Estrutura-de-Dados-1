#include <iostream>
#include <list>

using namespace std;
int min(list<int>& lst, list<int>::iterator it){
    if(it == lst.end()) return *it;
    else {
        int prev = min(lst, next(it));
        return (prev > *it) ? *it : prev;
    }
}

int main(int argc, char const *argv[]){
    list<int> lst = {5, 2, 8, 1, 9};
    if (!lst.empty()) {
        cout << "Menor elemento: " << min(lst, lst.begin()) << endl;
    } else {
        cout << "Lista vazia." << endl;
    }
    return 0;
}
