#include <iostream>

void count_50(int n){
    if (n <= 50){
        std::cout << n << " ";
        count_50(++n);
    }
    else std::cout << std::endl;
    return;
}

void count(int num){
    if (num > 0) {
        count_50(0);
        count(--num);
        std::cout << std::endl;
    }
    return;
}

int main(int argc, char const *argv[]){
    count(1);
    return 0;
}
