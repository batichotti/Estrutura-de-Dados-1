#include <stack>
#include <iostream>

using namespace std;

void push_to(stack<int>& stk1, stack<int>& stk2){
    if (stk1.size() < 1) return;
    stk2.push(stk1.top());
    stk1.pop();
    push_to(stk1, stk2);
}

int main(int argc, char const *argv[]){
    
    stack<int> stk1, stk2;
    stk1.push(1);
    stk1.push(2);
    stk1.push(3);
    stk1.push(4);

    push_to(stk1, stk2);

    return 0;
}
