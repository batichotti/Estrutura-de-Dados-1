#include <vector>
#include <iostream>
using namespace std;

vector<int> mem = {0, 1};
int fib(int n) {
    if (n < mem.size()) return mem[n];
    
    int fn = fib(n - 1) + fib(n - 2);
    mem.push_back(fn);
    return fn;
}

int main(int argc, char const *argv[]){
    cout << fib(8);
    return 0;
}
