#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include "ordenarBin.cpp"

using namespace std;

vector<int> readBinaryFile(string path){
    vector<int> result;
    FILE* binario = fopen(path.c_str(), "rb");
    if (!binario) return result;

    int value;
    while (fread(&value, sizeof(int), 1, binario) == 1) {
        result.push_back(value);
    }
    fclose(binario);
    return result;
}

int main(int argc, char const *argv[]){

    vector<int> vec = readBinaryFile("random_30000_numbers.bin");
    
    time_t tempo;
    
    selectionSort(vec, &tempo);
    
    cout << tempo;

    return 0;
}
