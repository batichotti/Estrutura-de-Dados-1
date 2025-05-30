#include <iostream>

void count_50(int n){
    if (n <= 50){
        std::cout << n << std::endl;
        count_50(++n);
    }
    return;
}

void count(int num){
    if (num > 0) {
        count_50(0);
        count(--num);
    }
    return;
}

int main(int argc, char const *argv[]){
    count(1);
    return 0;
}
