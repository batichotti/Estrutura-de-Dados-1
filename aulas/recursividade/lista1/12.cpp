#include <list>
#include <iostream>

using namespace std;

void copy(list<int>& list1, list<int>::iterator it, list<int>& list2) {
    if (it == list1.end()) return;
    list2.push_back(*it);
    copy(list1, ++it, list2);
}

int main(int argc, char const *argv[]) {
    list<int> l1 = {1, 2, 3, 4, 5};
    list<int> l2;

    auto iterator = l1.begin();

    copy(l1, iterator, l2);

    for (int val : l2) {
        cout << val << " ";
    }
    return 0;
}
