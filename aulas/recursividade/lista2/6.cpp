#include <iostream>
#include <vector>

using namespace std;
int count(vector<int>& vec, int n, int elem){
    if (n == 0) return (elem == vec[n])?1:0;
    else {
        int prev = count(vec, n-1, elem);
        return ((elem == vec[n])?1:0) + prev;    
    }
}

int main(int argc, char const *argv[]){
    vector<int> v = {1, 2, 3, 2, 4, 2, 5};
    int elem = 2;
    int n = v.size() - 1;
    cout << "O elemento " << elem << " aparece " << count(v, n, elem) << " vezes no vetor." << endl;
    return 0;
}
