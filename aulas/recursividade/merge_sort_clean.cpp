#include <vector>
using namespace std;

void merge(vector<int>& v, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if (v[i] <= v[j]) temp.push_back(v[i++]);
        else temp.push_back(v[j++]);
    }
    while (i <= mid) temp.push_back(v[i++]);
    while (j <= right) temp.push_back(v[j++]);
    for (int k = 0; k < temp.size(); k++) { // Corrigido: k < temp.size()
        v[left + k] = temp[k];
    }
}

void merge_sort(vector<int>& v, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(v, left, mid);
        merge_sort(v, mid + 1, right);
        merge(v, left, mid, right);
    }
}
