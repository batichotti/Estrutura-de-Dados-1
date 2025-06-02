#include <vector>
#include <iostream>
#include <chrono>

using namespace std;

float selectionSort(vector<int>& vec, int& trocas){
    auto tempo_inicial = chrono::high_resolution_clock::now();

    for (int i = 0; i < (int) vec.size(); i++){
        int min = vec[i];
        int min_pos = i;
        
        for (int j = i+1; j < (int) vec.size(); j++){
            if (vec[j] < min){
                min = vec[j];
                min_pos = j;
            }
        }

        swap(vec[i], vec[min_pos]); trocas++;
    }

    auto tempo_final = chrono::high_resolution_clock::now();

    chrono::duration<float> duracao = tempo_final - tempo_inicial;
    return duracao.count();
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

float bubbleSort(vector<int>& vec, int& trocas){
    auto tempo_inicial = chrono::high_resolution_clock::now();
    
    for(int i = 0; i < (int) vec.size(); i++) 
        for(int j = 0; j + 1 < (int) vec.size() - i; j++) 
            if(vec[j] > vec[j + 1]){swap(vec[j], vec[j + 1]); trocas++;}
    
    auto tempo_final = chrono::high_resolution_clock::now();

    chrono::duration<float> duracao = tempo_final - tempo_inicial;
    return duracao.count();
}

float bubbleSortOpt(vector<int>& vec, int& trocas) {
    auto tempo_inicial = chrono::high_resolution_clock::now();

    int len = (int) vec.size();
    
    while (len > 1) {
        int newlen = 0;
        for (int i = 1; i < len; i++){
            if (vec[i - 1] > vec[i]) {
                swap(vec[i - 1], vec[i]); trocas++;
                newlen = i;
            }
        }
        
        len = newlen;
    }
    auto tempo_final = chrono::high_resolution_clock::now();

    chrono::duration<float> duracao = tempo_final - tempo_inicial;
    return duracao.count();
}

// float selectionSortOpt(vector<int>& vec){
    // auto tempo_inicial = chrono::high_resolution_clock::now();
    //     for(int i = 0; i < (int) vec.size(); i++){
        //         int minidx = i;
        
        //         for(int j = i + 1; j < (int) vec.size(); j++){
            //             if(vec[j] < vec[j - 1]) swap(vec[j], vec[j - 1]);
            //             if(vec[j] < vec[minidx]) minidx = j;
            //         }
            
            //         if(minidx != i) swap(vec[i], vec[minidx]);
            //     }
            
            // auto tempo_final = chrono::high_resolution_clock::now();
        
            // chrono::duration<float> duracao = tempo_final - tempo_inicial;
            // return duracao.count();
// }

float selectionSortOpt(vector<int>& vec, int& trocas) {
    auto start = chrono::high_resolution_clock::now();
    
    for (int i = 0; i < vec.size() - 1; i++) {
        int minPos = i;
        
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[j] < vec[minPos]) minPos = j;
        }
        
        if (minPos != i){swap(vec[i], vec[minPos]); trocas++;}
    }

    auto end = chrono::high_resolution_clock::now();
    return chrono::duration<float>(end - start).count();
}

float insertionSort(vector<int>& vec, int& trocas){
    auto tempo_inicial = chrono::high_resolution_clock::now();

    for(int i = 1; i < (int) vec.size(); i++){   
        int index = i - 1;
        int key = vec[i];
        
        while(index >= 0 && vec[index] > key){
            vec[index + 1] = vec[index]; trocas++;
            index--;
        }
        
        vec[index + 1] = key; trocas++;
    }

    auto tempo_final = chrono::high_resolution_clock::now();

    chrono::duration<float> duracao = tempo_final - tempo_inicial;
    return duracao.count();
}