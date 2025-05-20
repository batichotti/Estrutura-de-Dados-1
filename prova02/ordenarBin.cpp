#include <vector>
#include <iostream>

using namespace std;

void SelectionSort(vector<int>& vetor){
    int size = vetor.size();
    for (int i = 0; i < size; i++){
        int min = vetor.at(i);
        int min_pos = -1;
        for (int j = i; j < size; j++){
            if (vetor.at(j) < min) min = vetor[j]; min_pos = j;
        }
        vetor[min_pos] = vetor.at(i);
        vetor[i] = min;
    }
}

int main(){
    vector<int> v = {3, 4, 3, 2, 3, 1};
    SelectionSort(v);
    for (int el : v) cout << el << endl;

    return 0;
}