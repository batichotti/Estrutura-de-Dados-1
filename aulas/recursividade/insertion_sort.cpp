void insertion(int arr[], int n){
    if(n <= 1) return; // caso base
    insertion(arr, n-1); // resolve na volta

    int last = arr[n-1];
    int j = n-2;
    while (j >= 0 && arr[j] > last){
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}