#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include "ordenarBin.cpp"
#include "buscaBin.cpp"

using namespace std;

const string DADOS_DIR = "../dados/";

vector<int> readBinaryFile(const string& path) {
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

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        cerr << "Uso: " << argv[0] << " <quantidade>\n";
        return 1;
    }

    string filepath = DADOS_DIR + "random_" + string(argv[1]) + "_numbers.bin";

    vector<int> vec = readBinaryFile(filepath);
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

    vec = readBinaryFile(filepath); trocas = 0;
    long double tempo_sso = selectionSortOpt(vec, trocas);
    cout.width(28); cout << "Selection Sort Otimizado:"; 
    cout.width(15); cout << tempo_sso; 
    cout << "| Trocas: " << trocas << endl;

    vec = readBinaryFile(filepath); trocas = 0;
    double tempo_bs = bubbleSort(vec, trocas);
    cout.width(28); cout << "Bubble Sort:"; 
    cout.width(15); cout << tempo_bs; 
    cout << "| Trocas: " << trocas << endl;

    vec = readBinaryFile(filepath); trocas = 0;
    long double tempo_bso = bubbleSortOpt(vec, trocas);
    cout.width(28); cout << "Bubble Sort Otimizado:"; 
    cout.width(15); cout << tempo_bso; 
    cout << "| Trocas: " << trocas << endl;

    vec = readBinaryFile(filepath); trocas = 0;
    long double tempo_is = insertionSort(vec, trocas);
    cout.width(28); cout << "Insertion Sort:"; 
    cout.width(15); cout << tempo_is; 
    cout << "| Deslocamentos: " << trocas << endl;

    // double tempo_busc_s, tempo_busc_b;
    // unsigned long long int comp_busc_s = 0, comp_busc_b = 0;
    // buscaSeq(vec, 297000, tempo_busc_s, comp_busc_s);
    // buscaBin(vec, 297000, tempo_busc_b, comp_busc_b);
    // cout.width(28); cout << "Busca Sequencial:"; 
    // cout.width(15); cout << tempo_busc_s; 
    // cout << "| Comparações: " << comp_busc_s << endl;
    // cout.width(28); cout << "Busca Binária:"; 
    // cout.width(15); cout << tempo_busc_b; 
    // cout << "| Comparações: " << comp_busc_b << endl;

    return 0;
}
