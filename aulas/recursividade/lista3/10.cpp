#include <iostream>
using namespace std;

bool palindromo(string str, int left, int right) {
    if (left >= right) return true;
    return (str[left] != str[right]) ? false : palindromo(str, left + 1, right - 1);
}

bool palindromo_hardcore(string str, int left, int right) {
    return (left >= right) ? true : (str[left] != str[right] ? false : palindromo_hardcore(str, left + 1, right - 1));
}

int main() {
    string s;
    cin >> s;

    if (palindromo_hardcore(s, 0, s.size() - 1))
        cout << "SIM" << endl;
    else
        cout << "NAO" << endl;

    return 0;
}
