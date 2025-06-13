#include <iostream>
using namespace std;

void hanoi(int n, char ori, char dest, char aux){
    if (n == 1){
        cout << "mover 1 disco de " << ori << " para " << dest << endl;
        return;
    }
    hanoi(n-1, ori, aux, dest);
    cout << "mover disco " << n << " de " << ori << " para " << dest << endl;
    hanoi(n-1, aux, dest, ori);
}

int main(int argc, char const *argv[]){
    int n = 3;
    hanoi(n, 'A', 'C', 'B');

    return 0;
}
