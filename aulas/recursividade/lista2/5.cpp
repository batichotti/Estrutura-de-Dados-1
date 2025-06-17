#include <iostream>
#include <vector>

using namespace std;
bool find(vector<int>& vec, int n, int elem){
    if (vec[n] == elem) return true;
    else if (n < 0) return false;
    else find(vec, n-1, elem);
}

int main(int argc, char const *argv[]){
    vector<int> v = {1, 3, 5, 7, 9};
    int elemento = 51;
    if (find(v, v.size() - 1, elemento)) {
        cout << elemento << " encontrado no vetor." << endl;
    } else {
        cout << elemento << " nao encontrado no vetor." << endl;
    }
    return 0;
}
