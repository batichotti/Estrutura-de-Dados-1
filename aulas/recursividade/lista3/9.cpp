#include <iostream>

using namespace std;

int C(int n, int k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    return C(n - 1, k) + C(n - 1, k - 1);
}

int main(int argc, char const *argv[]){
    int n, k;
    cout << "Digite n e k: ";
    cin >> n >> k;
    cout << "C(" << n << ", " << k << ") = " << C(n, k) << endl;
    return 0;
}
