#include <iostream>
#include <vector>

using namespace std;

int min(vector<int>& vec, int n){
    if (n <= 0) {
        return vec[0];
    } else {
        int prevMin = min(vec, n - 1);
        return (vec[n] < prevMin) ? vec[n] : prevMin;
    }
}

int main(int argc, char const *argv[]){
    vector<int> v = {5, 2, 8, 1, 9};
    int menor = min(v, v.size() - 1);
    cout << "O menor elemento é: " << menor << endl;
    return 0;
}
