#include <iostream>
using namespace std;

int mdc(int a, int b){
    return (b==0)?(a):(mdc(b, a%b));
}

int main(int argc, char const *argv[]){
    int a, b;
    cout << "Digite dois numeros: ";
    cin >> a >> b;
    cout << "MDC(" << a << ", " << b << ") = " << mdc(a, b) << endl;
    return 0;
}
