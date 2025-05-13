#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

vector<int> vet_to_vector(int* v, int n){
    vector<int> vetor;
    for (int i = 0; i < n; i++){
        vetor.push_back(v[i]);
    }
    return vetor;
}

list<int> vet_to_flist(int* v, int n){
    list<int> lista;
    for (int i = 0; i < n; i++){
        lista.push_back(v[i]);
    }
    return lista;
}

stack<int> vet_to_stack(int* v, int n){
    stack<int> pilha;
    for (int i = 0; i < n; i++){
        pilha.push(v[i]);
    }
    return pilha;
}

void print_stack(stack<int> st){
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}

vector<int> list_concat(list<int>& list1,list<int>& list2){
    vector<int> vec;
    for(int el : list1) vec.push_back(el);
    for(int el : list2) vec.push_back(el);
    return vec;
}

bool check_brackets(string expression){
    stack<char> pilha;
    for (char c : expression){
        if (c == '(' || c == '[' || c == '{'){
            pilha.push(c);
        } else if (!pilha.empty()){
            if (c == ')' && pilha.top() != '('){
                return false;
            }
            else if (c == ']' && pilha.top() != '['){
                return false;
            }
            else if (c == '}' && pilha.top() != '{'){
                return false;
            }
        } else {
            return false;
        }
    }
    return true;
}

int main(){
    int n = 4;
    int array[n];
    for (int i = 0; i < n; i++) array[i] = i+1;

    cout << "Vector:\n";
    vector<int> new_vector = vet_to_vector(array, n);
    for(int e : new_vector) cout << e << " ";
    
    cout << "\nList:\n";
    list<int> new_list = vet_to_flist(array, n);
    for(int e : new_list) cout << e << " ";
    
    cout << "\nStack:\n";
    stack<int> new_stack = vet_to_stack(array, n);
    print_stack(new_stack);
    
    cout << "\nConcat:\n";
    list<int> f1 = {1,2,3,4};
    list<int> f2 = {5,6};
    vector<int> vec = list_concat(f1, f2);
    for(int e : vec) cout << e << " ";

    cout << "\nCheck Brackets:\n";
    cout << check_brackets("(1+1)-[2+{4*4}]");
    return 0;
}
