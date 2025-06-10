#include <vector>
#include <iostream>

using namespace std;

void copy(vector<int>& vec1, int idx, vector<int>& vec2){
    if (idx >= vec1.size()) return;
    vec2.push_back(vec1[idx]);
    copy(vec1, ++idx, vec2);
}

int main(int argc, char const *argv[]){
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2;

    copy(v1, 0, v2);

    for (int el : v2) cout << el << " ";
    return 0;
}
