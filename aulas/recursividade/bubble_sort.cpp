#include <algorithm>

void bubble(int arr[], int n){
    if (n <= 1) return; // caso base
    for (int i = 0; i < n; i++){
        if(arr[i] > arr[i + 1]){
            std::swap(arr[i], arr[i + 1]);
        }
        bubble(arr, n-1);
    }
}
