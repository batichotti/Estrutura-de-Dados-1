#include <vector>
#include <iostream>

using namespace std;

void SelectionSort(vector<int>& vetor){
    int size = vetor.size();
    for (int i = 0; i < size; i++){
        int min = vetor[i];
        int min_pos = -1;
        for (int j = i+1; j < size; j++){
            if (vetor.at(j) < min) min = vetor[j]; min_pos = j;
        }
        int temp = vetor[i];
        vetor[i] = min;
        vetor[min_pos] = temp;
    }
}

int main(){
    vector<int> v = {3, 4, 3, 2, 3, 1};
    SelectionSort(v);
    for (int el : v) cout << el << endl;

    return 0;
}