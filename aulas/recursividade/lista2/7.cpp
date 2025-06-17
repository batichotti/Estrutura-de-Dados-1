#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& vec, int a, int b){
    int temp = vec[a];
    vec[a] = vec[b];
    vec[b] = temp;
}

void reverse(vector<int>& vec, int first, int last){
    if(first >= last) return;
    swap(vec, first, last);
    reverse(vec, first+1, last-1);
}

int main(int argc, char const *argv[]){
    vector<int> v = {1, 2, 3, 4, 5};
    reverse(v, 0, v.size() - 1);
    for(int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
