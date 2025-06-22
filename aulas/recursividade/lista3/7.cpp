#include <iostream>

using namespace std;

int soma_digitos(int n){
    return (n > 0)?(n % 10 + soma_digitos(n/10)):(n);
}

int main(int argc, char const *argv[]){
    int numero;
    cout << "Digite um numero: ";
    cin >> numero;
    cout << "Soma dos digitos: " << soma_digitos(numero) << endl;
    return 0;
}
