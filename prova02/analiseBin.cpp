#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include "ordenarBin.cpp"
#include "buscaBin.cpp"

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

    unsigned long long int trocas = 0;
    
    long double tempo_ss = selectionSort(vec, trocas);
    cout << left;
    cout.width(28); cout << "Selection Sort:"; 
    cout.width(15); cout << tempo_ss; 
    cout << "| Trocas: " << trocas << endl;

    vec = readBinaryFile("random_" + string(argv[1]) + "_numbers.bin"); trocas = 0;

    long double tempo_sso = selectionSortOpt(vec, trocas);

    cout.width(28); cout << "Selection Sort Otimizado:"; 
    cout.width(15); cout << tempo_sso; 
    cout << "| Trocas: " << trocas << endl;

    vec = readBinaryFile("random_" + string(argv[1]) + "_numbers.bin"); trocas = 0;

    double tempo_bs = bubbleSort(vec, trocas);

    cout.width(28); cout << "Bubble Sort:"; 
    cout.width(15); cout << tempo_bs; 
    cout << "| Trocas: " << trocas << endl;

    vec = readBinaryFile("random_" + string(argv[1]) + "_numbers.bin"); trocas = 0;

    long double tempo_bso = bubbleSortOpt(vec, trocas);

    cout.width(28); cout << "Bubble Sort Otimizado:"; 
    cout.width(15); cout << tempo_bso; 
    cout << "| Trocas: " << trocas << endl;

    vec = readBinaryFile("random_" + string(argv[1]) + "_numbers.bin"); trocas = 0;

    long double tempo_is = insertionSort(vec, trocas);

    cout.width(28); cout << "Insertion Sort:"; 
    cout.width(15); cout << tempo_is; 
    cout << "| Deslocamentos: " << trocas << endl;
    
    vec = readBinaryFile("random_" + string(argv[1]) + "_numbers.bin"); trocas = 0;

    long double tempo_busc_s;
    long double tempo_busc_b;
    
    buscaSeq(vec, 20, tempo_busc_s);
    buscaBin(vec, 20, tempo_busc_b);

    cout << "Sequencial Search: " << tempo_busc_s << endl;
    
    cout << "Binary Search: " << tempo_busc_b << endl;
    
    return 0;
}
