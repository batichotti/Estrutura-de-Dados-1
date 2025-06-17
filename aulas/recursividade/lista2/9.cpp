#include <iostream>

using namespace std;
bool palindrome(string& str, int first, int last){
    if (first >= last) return true;
    if (str[first] != str[last]) return false;
    return palindrome(str, first + 1, last - 1);
}

int main(int argc, char const *argv[]){
    string str;
    cout << "Digite uma palavra: ";
    cin >> str;
    if (palindrome(str, 0, str.size() - 1)) {
        cout << "Eh palindromo!" << endl;
    } else {
        cout << "Nao eh palindromo!" << endl;
    }
    return 0;
}
