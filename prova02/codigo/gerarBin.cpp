#include <iostream>
#include <vector>
#include <random>
#include <limits>

using namespace std;

void createBinaryFile(const vector<int>& vetor){
    string path = "random_" + to_string(vetor.size()) + "_numbers.bin";
    FILE* binario = fopen(path.c_str(), "wb");
    for (int el: vetor){
        fwrite(&el, sizeof(int), 1, binario);
    }
    fclose(binario);
}

vector<int> createRandVec(int size, int range){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, range);

    vector<int> vec;
    vec.reserve(size);

    for(int i = 0; i < size; i++){
        vec.push_back(dist(gen));
    }

    return vec;
}

int main(int argc, char* argv[]) {
    int vecSize = 20000;
    if (argc > 1) {
        vecSize = atoi(argv[1]);
        if (vecSize <= 0) {
            cerr << "Tamanho invalido. Usando 20000." << endl;
            vecSize = 20000;
        }
    }

    vector<int> vec = createRandVec(vecSize, numeric_limits<int>::max());

    cout << "Arquivo criado." << endl;

    createBinaryFile(vec);
}