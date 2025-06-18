#include <iostream>
#include <list>
using namespace std;

bool palindrome(list<int>& lst, list<int>::iterator first, list<int>::iterator last){
    if (*first != *last) return false;
    if (first == last) return true;
    palindrome(lst, next(first), prev(last));
}

int main(int argc, char const *argv[]){
    list<int> lst = {1, 2, 3, 2, 1};
    if (palindrome(lst, lst.begin(), prev(lst.end()))) {
        cout << "E palindromo" << endl;
    } else {
        cout << "Nao e palindromo" << endl;
    }
    return 0;
}
