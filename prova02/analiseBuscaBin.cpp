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
    long double tempo_is = insertionSort(vec, trocas);

    cout.width(28); cout << "Insertion Sort:"; 
    cout.width(15); cout << tempo_is; 
    cout << "| Deslocamentos: " << trocas << endl;
    
    long double tempo_busc_s;
    unsigned long long int comp_busc_s = 0;
    long double tempo_busc_b;
    unsigned long long int comp_busc_b = 0;
    
    buscaSeq(vec, 750001, tempo_busc_s, comp_busc_s);
    buscaBin(vec, 750001, tempo_busc_b, comp_busc_b);

    cout.width(28); cout << "Busca Sequencial:"; 
    cout.width(15); cout << tempo_busc_s; 
    cout << "| Comparacoes: " << comp_busc_s << endl;

    cout.width(28); cout << "Busca Binária:"; 
    cout.width(15); cout << tempo_busc_b; 
    cout << "| Comparacoes: " << comp_busc_b << endl;
    return 0;
}
