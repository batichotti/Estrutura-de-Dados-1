#include <vector>
#include <iostream>

using namespace std;

void selectionSort(vector<int>& vec){
    for (int i = 0; i < (int) vec.size(); i++){
        int min = vec[i];
        int min_pos = -1;
        
        for (int j = i+1; j < (int) vec.size(); j++){
            if (vec[j] < min){
                min = vec[j];
                min_pos = j;
            }
        }

        int temp = vec[i];
        vec[i] = min;
        vec[min_pos] = temp;
    }
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(vector<int>& vec){
    for(int i = 0; i < (int) vec.size(); i++) 
        for(int j = 0; j + 1 < (int) vec.size() - i; j++) 
            if(vec[j] > vec[j + 1]) swap(vec[j], vec[j + 1]);
}

int main(){
    vector<int> selS = {3, 4, 5, 2, 3, 1};
    selectionSort(selS);

    cout << endl;
    for (int el : selS) cout << el << " ";
    cout << endl; cout << endl;

    vector<int> bubS = {3, 4, 5, 2, 3, 1};
    bubbleSort(bubS);
    
    for (int el : bubS) cout << el << " ";
    cout << endl; cout << endl;

    return 0;
}