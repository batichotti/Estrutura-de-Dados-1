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
    long double tempo_is = insertionSort(vec, trocas);

    cout.width(28); cout << "Insertion Sort:"; 
    cout.width(15); cout << tempo_is; 
    cout << "| Deslocamentos: " << trocas << endl;

    long double tempo_busc_s;
    unsigned long long int comp_busc_s = 0;
    long double tempo_busc_b;
    unsigned long long int comp_busc_b = 0;

    int random = 2147154760;

    int pos_bs = buscaSeq(vec, random, comp_busc_s);
    int pos_bb = buscaBin(vec, random, comp_busc_b);

    cout << "Busca Sequencial: posicao " << pos_bs 
         << " Pegou -> " << (pos_bs >= 0 ? to_string(vec[pos_bs]) : "N/A") 
         << " Deveria ter pego -> " << random << endl;

    cout << "Busca Binaria: posicao " << pos_bb 
         << " Pegou -> " << (pos_bb >= 0 ? to_string(vec[pos_bb]) : "N/A") 
         << " Deveria ter pego -> " << random << endl;

    cout.width(28); cout << "Busca Sequencial";
    cout << " Comparacoes: " << comp_busc_s << endl;

    cout.width(28); cout << "Busca Binaria";
    cout << " Comparacoes: " << comp_busc_b << endl;

    return 0;
}
