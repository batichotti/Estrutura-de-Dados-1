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


int main(int argc, char const *argv[]){
    string s;
    cin >> s;
    permute(s, 0, 0);
    return 0;
}
