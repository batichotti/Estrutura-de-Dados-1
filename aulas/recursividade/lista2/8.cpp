#include <iostream>
#include <list>

using namespace std;

void swap(list<int>& lst, list<int>::iterator a, list<int>::iterator b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(list<int>& lst, list<int>::iterator first, list<int>::iterator last){
    if (first == last || first == prev(last)) return;
    --last;
    swap(lst, first, last);
    reverse(lst, next(first), last);
}

int main(int argc, char const *argv[]){
    list<int> lst = {1, 2, 3, 4, 5};
    if (!lst.empty()) {
        auto first = lst.begin();
        auto last = lst.end();
        reverse(lst, first, last);
    }
    for(auto it = lst.begin(); it != lst.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
