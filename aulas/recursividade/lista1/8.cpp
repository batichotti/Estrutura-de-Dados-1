#include <iostream>
#include <vector>

using namespace std;

void remove_all(vector<int>& vec){
    if (vec.size() > 0){
        vec.pop_back();
        remove_all(vec);
    }
    return;
}

int main(int argc, char const *argv[]){
    vector<int> vec = vector<int>{1, 2, 3, 4, 5};
    remove_all(vec);
    cout << vec.size() << endl;
    return 0;
}
