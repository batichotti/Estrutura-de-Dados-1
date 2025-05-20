#include <iostream>

using namespace std;

int fat(int n){
    if(n <= 1){
        return n;
    } else {
        return fat(n-1)*n;
    }
}

int main(){
    cout << fat(5);
    return 0;
}