#include <time.h>
#include <vector>
#include <iostream>

using namespace std;

void selectionSort(vector<int>& vec, time_t& tempo){
    time_t tempo_inicial;
    time(&tempo_inicial);

    for (int i = 0; i < (int) vec.size(); i++){
        int min = vec[i];
        int min_pos = i;
        
        for (int j = i+1; j < (int) vec.size(); j++){
            if (vec[j] < min){
                min = vec[j];
                min_pos = j;
            }
        }

        int temp = vec[i];
        vec[i] = min;
        vec[min_pos] = temp;
    }

    time_t tempo_final;
    time(&tempo_final);

    tempo = difftime(tempo_final, tempo_inicial);
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(vector<int>& vec){
    for(int i = 0; i < (int) vec.size(); i++) 
        for(int j = 0; j + 1 < (int) vec.size() - i; j++) 
            if(vec[j] > vec[j + 1]) swap(vec[j], vec[j + 1]);
}

void optBubbleSort(vector<int>& vec) {
    int len = (int) vec.size();

    while (len > 1) {
        int newlen = 0;
        for (int i = 1; i < len; i++){
            if (vec[i - 1] > vec[i]) {
                swap(vec[i - 1], vec[i]);
                newlen = i;
            }
        }

        len = newlen;
    }
}

void optSelectionSort(vector<int>& vec){
    for(int i = 0; i < (int) vec.size(); i++){
        int minidx = i;

        for(int j = i + 1; j < (int) vec.size(); j++){
            if(vec[j] < vec[j - 1]) swap(vec[j], vec[j - 1]);
            if(vec[j] < vec[minidx]) minidx = j;
        }

        if(minidx != i) swap(vec[i], vec[minidx]);
    }
}


void insertionSort(vector<int>& vec){
    for(int i = 0; i < (int) vec.size(); i++){   
        int index = i - 1;
        int key = vec[i];

        while(vec[i] < vec[i - 1] && index >= 0){
            vec[index + 1] = vec[index];
            index--;
        }

        vec[i + 1] = key;
    }
}