#include <iostream>

void count(int n, int max){
    if (n <= max){
        std::cout << n << std::endl;
        count(++n, max);
    }
    return;
}

void count_max(int num, int max){
    if (num > 0) {
        count(0, max);
        count_max(--num, max);
    }
    return;
}

int main(int argc, char const *argv[]){
    count_max(2, 4);
    return 0;
}
