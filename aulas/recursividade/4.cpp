#include <iostream>
#include <vector>

void print_vec(std::vector<int>& vec, int idx){
    if(idx < vec.size()){
        std::cout << vec[idx] << " ";
        print_vec(vec, ++idx);
    }
    else std::cout << std::endl;
    return;
}

int main(int argc, char const *argv[]){
    std::vector<int> vec = std::vector<int>{1, 2, 3, 4};
    print_vec(vec, 0);
    return 0;
}
