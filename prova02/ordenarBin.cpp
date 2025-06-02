#include <time.h>
#include <vector>
#include <iostream>

using namespace std;

int selectionSort(vector<int>& vec){
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

    return difftime(tempo_final, tempo_inicial);
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int bubbleSort(vector<int>& vec){
    time_t tempo_inicial;
    time(&tempo_inicial);

    for(int i = 0; i < (int) vec.size(); i++) 
    for(int j = 0; j + 1 < (int) vec.size() - i; j++) 
    if(vec[j] > vec[j + 1]) swap(vec[j], vec[j + 1]);
    time_t tempo_final;
    time(&tempo_final);

    return difftime(tempo_final, tempo_inicial);
}

int bubbleSortOpt(vector<int>& vec) {
    time_t tempo_inicial;
    time(&tempo_inicial);

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
    time_t tempo_final;
    time(&tempo_final);

    return difftime(tempo_final, tempo_inicial);
}

// int selectionSortOpt(vector<int>& vec){
//     time_t tempo_inicial;
//     time(&tempo_inicial);

//     for(int i = 0; i < (int) vec.size(); i++){
//         int minidx = i;
        
//         for(int j = i + 1; j < (int) vec.size(); j++){
//             if(vec[j] < vec[j - 1]) swap(vec[j], vec[j - 1]);
//             if(vec[j] < vec[minidx]) minidx = j;
//         }
        
//         if(minidx != i) swap(vec[i], vec[minidx]);
//     }
//     time_t tempo_final;
//     time(&tempo_final);

//     return difftime(tempo_final, tempo_inicial);
// }

int selectionSortOpt(vector<int>& vec){
    time_t tempo_inicial;
    time(&tempo_inicial);

    int frst = 0;
    int lst = (int) vec.size() - 1;

    while(frst < lst){
        int minIdx = frst;
        int maxIdx = frst;

        for(int i = frst + 1; i <= lst; ++i){
            if(vec[i] < vec[minIdx]) minIdx = i;
            if(vec[i] > vec[maxIdx]) maxIdx = i;
        }

        swap(vec[frst], vec[minIdx]);
        if(maxIdx == frst) maxIdx = minIdx;

        swap(vec[lst], vec[maxIdx]);

        ++frst;
        --lst;
    }
    time_t tempo_final;
    time(&tempo_final);

    return difftime(tempo_final, tempo_inicial);
}

int insertionSort(vector<int>& vec){
    time_t tempo_inicial;
    time(&tempo_inicial);

    for(int i = 1; i < (int) vec.size(); i++){   
        int index = i - 1;
        int key = vec[i];
        
        while(index >= 0 && vec[index] > key){
            vec[index + 1] = vec[index];
            index--;
        }
        
        vec[index + 1] = key;
    }
    
    time_t tempo_final;
    time(&tempo_final);

    return difftime(tempo_final, tempo_inicial);
}