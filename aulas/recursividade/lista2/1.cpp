#include <vector>
#include <iostream>

using namespace std;

int sum(vector<int>& v, int n){
    if (n > 1){
        int i = v[n-1];
        int s = sum(v, n-1);
        if(!((n-1)%2)) return i + s;
        else return s;
    } else return v[0];
}

int main(int argc, char const *argv[]){
    vector<int> v = {1, 2, 3, 4};
    cout << sum(v, 4);
    return 0;
}
