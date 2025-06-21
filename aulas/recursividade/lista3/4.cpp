#include <iostream>

using namespace std;

void print_array(int arr[], int n, int comeco = 0){
    if(n <= comeco) return;
    cout << arr[comeco];
    print_array(arr, n, comeco+1);
}

void subconjuntos(int arr[], int n, int pos, int pos_swap){
    if (pos == n-1){
        print_array(arr, n);
        cout << endl;
        return;
    }
    if (pos_swap >= n) return;
    swap(arr[pos], arr[pos_swap]);
    subconjuntos(arr, n, pos+1, pos_swap+1);
    swap(arr[pos], arr[pos_swap]);
    subconjuntos(arr, n, pos, pos_swap+1);
}

int main(int argc, char const *argv[]){
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    subconjuntos(arr, n, 0, 0);
    return 0;
}
