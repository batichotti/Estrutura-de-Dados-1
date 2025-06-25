#include <iostream>
#include <string>

void print_txt(std::string txt, int n){
    if (n > 0){
        std::cout << txt << std::endl;
        print_txt(txt, --n);
    }
    return;
}

void print_txt2(std::string txt, int n){
    if (n > 0){
        return print_txt(txt, --n);
    }
    std::cout << txt << std::endl;
}

int main(int argc, char const *argv[]){
    print_txt2("tottenham campeao da europa legue", 10);
    return 0;
}