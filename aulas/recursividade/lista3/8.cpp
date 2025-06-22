#include <iostream>

using namespace std;

string inverte_string(string str, int left, int right){
    if(left < right){
        swap(str[left], str[right]);
        return inverte_string(str, left+1, right-1);
    } else return str;
}

int main(int argc, char const *argv[]){
    string s;
    cin >> s;
    cout << inverte_string(s, 0, s.size() - 1) << endl;
    return 0;
}
