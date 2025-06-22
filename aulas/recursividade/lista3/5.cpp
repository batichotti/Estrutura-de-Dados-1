#include <iostream>
using namespace std;

int busca_binaria(int arr[], int left, int right, int elem) {
    if (left > right) return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == elem)
        return mid;
    else if (arr[mid] > elem)
        return busca_binaria(arr, left, mid - 1, elem);
    else
        return busca_binaria(arr, mid + 1, right, elem);
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    int elem = 7;

    int idx = busca_binaria(arr, 0, n - 1, elem);

    if (idx != -1)
        cout << "Elemento encontrado na posicao: " << idx << endl;
    else
        cout << "Elemento nao encontrado." << endl;

    return 0;
}
