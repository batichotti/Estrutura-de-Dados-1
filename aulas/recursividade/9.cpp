#include <iostream>
#include <stack>

using namespace std;

void print_stack(stack<int>& stk){
    if(stk.size() > 0){
        int top = stk.top();
        stk.pop();
        print_stack(stk);
        cout << top << " ";
    } else return;
}

int main(int argc, char const *argv[]){
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);

    print_stack(stk);
    return 0;
}
