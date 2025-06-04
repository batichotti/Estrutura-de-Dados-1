#include <iostream>
#include <forward_list>

using namespace std;

void print_rev(forward_list<int> &lst, forward_list<int>::iterator &it){
    if(it != lst.end()){
        auto next = it;
        ++next;
        print_rev(lst, next);
    } else {
        return;
    }
    cout << *it << " ";
}

int main(int argc, char const *argv[]){
    forward_list<int> lst = forward_list<int>{1, 3, 4, 5, 6};
    auto it = lst.begin();
    print_rev(lst, it);
    return 0;
}
