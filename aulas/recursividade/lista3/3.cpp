#include <iostream>
using namespace std;

void permute(string &str, int pos, int swap_pos) {
    if (pos == str.size() - 1) {
        cout << str << endl;
        return;
    }
    if (swap_pos >= str.size()) {
        return;
    }
    swap(str[pos], str[swap_pos]);
    permute(str, pos + 1, pos + 1);
    swap(str[pos], str[swap_pos]);
    permute(str, pos, swap_pos + 1);
}

void permutar(string& str, int ini);

void troca(string& str, int ini, int i = 0){
    swap(str[ini], str[i]); // troca o atual
    permutar(str, ini+1); // permuta
    swap(str[ini], str[i]); // backtracking
    if (i > str.size() - 1) return;
    troca(str, ini, i+1);
}

void permutar(string& str, int ini = 0){
    if (ini == str.size() - 1){
        cout << str << endl;
        return;
    }
    troca(str, ini);
}

int main(int argc, char const *argv[]){
    string s;
    cin >> s;
    permutar(s, 0);
    return 0;
}
