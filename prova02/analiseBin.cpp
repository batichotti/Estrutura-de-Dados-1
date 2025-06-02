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
    if (argc < 2) {
        cerr << "Uso: " << argv[0] << " <quantidade>\n";
        return 1;
    }

    vector<int> vec = readBinaryFile("random_" + string(argv[1]) + "_numbers.bin");
    if (vec.empty()) {
        cerr << "Erro ao ler o arquivo binário ou arquivo vazio.\n";
        return 1;
    }
    
    float tempo_ss = selectionSort(vec);
    
    cout << "Selection Sort: " << tempo_ss << endl;
    
    float tempo_sso = selectionSortOpt(vec);
    
    cout << "Selection Sort Otimizado: " << tempo_sso << endl;
    
    float tempo_bs = bubbleSort(vec);
    
    cout << "Bubble Sort: " << tempo_bs << endl;
    
    float tempo_bso = bubbleSortOpt(vec);
    
    cout << "Bubble Sort Otimizado: " << tempo_ss << endl;
    
    float tempo_is = insertionSort(vec);
    
    cout << "Insertion Sort: " << tempo_is << endl;

    float tempo_bs;
    float tempo_bb;

    return 0;
}
