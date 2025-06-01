#include <iostream>
#include <vector>

void print_even(std::vector<int>& vec, int idx){
    if(idx < vec.size()){
        if (!(vec[idx] & 1)) std::cout << vec[idx] << " ";
        print_even(vec, ++idx);
    }
    else std::cout << std::endl;
    return;
}

int main(int argc, char const *argv[]){
    std::vector<int> vec = std::vector<int>{1, 2, 3, 4};
    print_even(vec, 0);
    return 0;
}
