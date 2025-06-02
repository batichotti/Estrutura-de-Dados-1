#include <vector>
#include <iostream>
#include <chrono>

using namespace std;

bool isSorted(vector<int>& vec){
    for(int i = 1; i < (int) vec.size(); i++) if(vec[i - 1] > vec[i]) return false;
    return true;
}

int buscaSeq(vector<int>& vec, int elem, double& time){
    auto tempo_inicial = chrono::high_resolution_clock::now();

    for(int i = 0; i < (int) vec.size(); i++){
        if(vec[i] == elem){
            auto tempo_final = chrono::high_resolution_clock::now();
        
            chrono::duration<double> duracao = tempo_final - tempo_inicial;
            time = duracao.count();
            return i;
        }
    }
    
    auto tempo_final = chrono::high_resolution_clock::now();

    chrono::duration<double> duracao = tempo_final - tempo_inicial;
    time = duracao.count();

    return -1;
}

int buscaBin(vector<int>& vec, int elem, double& time){
    if(!isSorted(vec)) return -1;

    auto tempo_inicial = chrono::high_resolution_clock::now();

    int left = 0, right = (int) vec.size() - 1;

    while(left <= right){
        int mid = left + (right - left) / 2;

        if(vec[mid] == elem){
            auto tempo_final = chrono::high_resolution_clock::now();
        
            chrono::duration<double> duracao = tempo_final - tempo_inicial;
            time = duracao.count();
            return mid;
        }
        else if(vec[mid] < elem) left = mid + 1;
        else right = mid - 1;
    }

    auto tempo_final = chrono::high_resolution_clock::now();

    chrono::duration<double> duracao = tempo_final - tempo_inicial;
    time = duracao.count();

    return -1;
}

/*int main(){
    vector<int> vec = {1, 2, 3, 4, 5, 8, 12, 50, 52, 70, 100, 123, 153, 423, 586, 999};
    
    cout << endl;
    cout << "Seq: " << vec[buscaSeq(vec, 52)] << " " << "Idx: " << buscaSeq(vec, 52) << endl;
    cout << endl;
    cout << "Bin: " << vec[buscaBin(vec, 52)] << " " << "Idx: " << buscaBin(vec, 52) << endl;
    cout << endl;
    
    return 0;
}*/