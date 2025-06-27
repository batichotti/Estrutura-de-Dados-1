#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> vec, int i = 0){
    if(i >= vec.size()) return;
    cout << vec[i];
    print_vector(vec, i+1);
}

void subconjuntos(vector<int> conjunto, vector<int> subconjunto, int n = 0){
    if ( n >= conjunto.size() ){
        cout << "{ ";
        print_vector(subconjunto);
        cout << " }" << endl;
        return;
    }

    subconjuntos(conjunto, subconjunto, n+1);
    subconjunto.push_back(conjunto[n]);
    subconjuntos(conjunto, subconjunto, n+1);
}

int main(int argc, char const *argv[]){
    vector<int> v = {1, 2, 3};
    vector<int> v2;
    subconjuntos(v, v2);
    return 0;
}
