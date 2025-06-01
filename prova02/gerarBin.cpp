#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

void createBinaryFile(vector<int> vetor){
    string path = "random_" + to_string(vetor.size()) + "_numbers.bin";
    FILE* binario = fopen(path.c_str(), "wb");
    for (int el: vetor){
        fwrite(&el, sizeof(int), 1, binario);
    }
    fclose(binario);
}

vector<int> createRandVec(int size, int range){
    srand(time(0));    
    vector<int> vec;

    for(int i = 0; i < size; i++){
        vec.push_back(rand() % (range + 1));
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

    vector<int> vec = createRandVec(vecSize, 2147483647);

    cout << "Arquivo criado." << endl;

    createBinaryFile(vec);
}