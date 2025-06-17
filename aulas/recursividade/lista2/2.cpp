#include <list>
#include <iostream>
using namespace std;

int product(list<int>& lst, list<int>::iterator it){
    if(it == lst.end()) return 1;
    return (*it) * product(lst, next(it));
}

int main(int argc, char const *argv[]){
    list<int> lst = {2, 3, 4};
    int result = product(lst, lst.begin());
    cout << "Produto: " << result << endl;
    return 0;
}
