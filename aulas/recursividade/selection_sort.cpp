#include <algorithm>

int findMin(int arr[], int start, int end){
    int minI = start;
    for (int i = start+1; i <= end; i++){
           if (arr[i] < arr[minI]){
            minI = i;
           }
    }
    return minI;
}

void selection(int arr[], int start, int n){
    if (start >= n-1) return; // caso base
    int minI = findMin(arr, start, n-1);
    std::swap(arr[start], arr[minI]);
    selection(arr, start + 1, n);
}