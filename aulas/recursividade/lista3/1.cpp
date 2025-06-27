#include <iostream>
using namespace std;

float power(int base, int exp){
    if (exp == 0) return 1;
    if (exp == 1) return base;
    if (exp < 0) return 1/(power(base, -exp));
    return (exp%2)?(base * power(base, (int) exp/2) * power(base, (int) exp/2)):(power(base, (int) exp/2) * power(base, (int) exp/2)); 
}

int main(int argc, char const *argv[]){
    int base, exp;
    cout << "Digite a base: ";
    cin >> base;
    cout << "Digite o expoente: ";
    cin >> exp;
    cout << "Resultado: " << power(base, exp) << endl;
    return 0;
}
