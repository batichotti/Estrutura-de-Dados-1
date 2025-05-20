#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<int> createRandVec(int size, int range){
    srand(time(0));    
    vector<int> vec;

    for(int i = 0; i < size; i++){
        vec.push_back(rand() % (range + 1));
    }

    return vec;
}

int main(){
    vector<int> vec = createRandVec(10, 100);

    cout << endl;
    for(int e : vec) cout << e << " ";
    cout << endl; cout << endl;
}