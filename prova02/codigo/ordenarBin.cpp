#include <vector>
#include <iostream>
#include <chrono>
#include "cronometro.cpp"

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

long double selectionSort(vector<int>& vec, unsigned long long int& trocas){
    Cronometro cronometro("Selection Sort: ");
    auto tempo_inicial = chrono::high_resolution_clock::now();

    for (int i = 0; i < (int) vec.size() - 1; i++){
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

    chrono::duration<long double> duracao = tempo_final - tempo_inicial;
    return duracao.count();
}

long double bubbleSort(vector<int>& vec, unsigned long long  int& trocas){
    Cronometro cronometro("Bubble Sort: ");
    auto tempo_inicial = chrono::high_resolution_clock::now();
    
    for(int i = 0; i < (int) vec.size(); i++) 
        for(int j = 0; j + 1 < (int) vec.size() - i; j++) 
            if(vec[j] > vec[j + 1]){swap(vec[j], vec[j + 1]); trocas++;}
    
    auto tempo_final = chrono::high_resolution_clock::now();

    chrono::duration<long double> duracao = tempo_final - tempo_inicial;
    return duracao.count();
}

long double bubbleSortOpt(vector<int>& vec, unsigned long long int& trocas) {
    Cronometro cronometro("Bubble Sort Opt: ");
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

    chrono::duration<long double> duracao = tempo_final - tempo_inicial;
    return duracao.count();
}

long double selectionSortOpt(vector<int>& vec, unsigned long long int& trocas) {
    Cronometro cronometro("Selection Sort Opt: ");
    auto start = chrono::high_resolution_clock::now();
    
    for (int i = 0; i < vec.size() - 1; i++) {
        int minPos = i;
        
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[j] < vec[minPos]) minPos = j;
        }
        
        if (minPos != i){swap(vec[i], vec[minPos]); trocas++;}
    }

    auto end = chrono::high_resolution_clock::now();
    return chrono::duration<long double>(end - start).count();
}

long double insertionSort(vector<int>& vec, unsigned long long int& trocas){
    Cronometro cronometro("Insertion Sort: ");
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

    chrono::duration<long double> duracao = tempo_final - tempo_inicial;
    return duracao.count();
}