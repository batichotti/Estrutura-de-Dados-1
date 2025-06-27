#include <iostream>
#include <list>
using namespace std;

bool palindrome(list<int>& lst, list<int>::iterator first, list<int>::iterator last) {
    if (first == last) return true;
    if (*first != *last) return false;
    return palindrome(lst, next(first), prev(last));
}

int main() {
    list<int> lst = {9, 1, 1, 1, 1, 17};
    if (palindrome(lst, lst.begin(), prev(lst.end()))) {
        cout << "SIM palíndromo" << endl;
    } else {
        cout << "NAO palíndromo" << endl;
    }
    return 0;
}
