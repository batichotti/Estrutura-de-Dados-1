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
        } 
        if ((c == ')' || c == ']' || c == '}') && pilha.empty()){
            return false;
        }

        if (c == ')'){
            if (pilha.top() == '(') pilha.pop();
            else return false;
        }
        else if (c == ']'){
            if (pilha.top() == '[') pilha.pop();
            else return false;
        }
        else if (c == '}'){
            if (pilha.top() == '{') pilha.pop();
            else return false;
        }
    }
    
    return pilha.empty();
}

vector<string> vectorize_expression(string expression) {
    vector<string> vetor;
    queue<char> fila;

    for (char el : expression){
        if(el == ' '){
            string final;
            while(!fila.empty()){
                final.push_back(fila.front());
                fila.pop();
            }
            vetor.push_back(final);
        } else {
            fila.push(el);
        }
    }
    if (!fila.empty()){
        string final;
        while(!fila.empty()){
            final.push_back(fila.front());
            fila.pop();
        }
        vetor.push_back(final);
    }
    return vetor;
}

float calc_posfix(string expression){
    vector<string> vector_to_rpn = vectorize_expression(expression);
    stack<float> pilha;
    float a, b;
    for (string el : vector_to_rpn){
        if (isdigit(el.at(0))) {
            int num = stoi(el);
            pilha.push(num);
        }
        else if(pilha.size() < 2) throw invalid_argument("Invalid operators");
        else if(el.compare("+") == 0){
            a = pilha.top();
            pilha.pop();
            b = pilha.top();
            pilha.pop();
            pilha.push(b+a);
        }
        else if(el.compare("-") == 0){
            a = pilha.top();
            pilha.pop();
            b = pilha.top();
            pilha.pop();
            pilha.push(b-a);
        }
        else if(el.compare("*") == 0){
            a = pilha.top();
            pilha.pop();
            b = pilha.top();
            pilha.pop();
            pilha.push(b*a);
        }
        else if(el.compare("/") == 0){
            a = pilha.top();
            pilha.pop();
            b = pilha.top();
            pilha.pop();
            pilha.push(b/a);
        }
        else throw invalid_argument("Invalid operators");
    }
    return pilha.top();
}

bool check_posfix(string expression){
    vector<string> vector_to_rpn = vectorize_expression(expression);
    stack<float> pilha;
    for (string el : vector_to_rpn){
        if (isdigit(el.at(0))) pilha.push(stoi(el));
        else if(el.compare("+") == 0 || el.compare("-") == 0 || el.compare("*") == 0 || el.compare("/") == 0){
            pilha.pop();
        }
        else throw invalid_argument("Invalid operators");
    }
    return pilha.size() == 1;
}

void calc(stack<float>& operandos, stack<char>& operadores){
    float b = operandos.top();
    operandos.pop();
    float a = operandos.top();
    operandos.pop();
    char op = operadores.top();
    operadores.pop();
    switch(op) {
        case '+': operandos.push(a + b); break;
        case '-': operandos.push(a - b); break;
        case '*': operandos.push(a * b); break;
        case '/': operandos.push(a / b); break;
    }
}

float calc_infix(string expression){
    vector<string> vector = vectorize_expression(expression);
    stack<float> operandos;
    stack<char> operadores;

    for (string el : vector){
        if (isdigit(el.at(0))){
            operandos.push(stoi(el));
        }
        
        if (el.compare("(") == 0){
            operadores.push(el.at(0));
        }

        if (el.compare("/") == 0 || el.compare("*") == 0 || el.compare("-") == 0 || el.compare("+") == 0) {
            operadores.push(el.at(0));
        }

        if (el.compare(")") == 0) {
            calc(operandos, operadores);
            operadores.pop();
        }
    }
    
    return operandos.top();
}

string posfix_to_infix(string expression){
    vector<string> vector = vectorize_expression(expression);
    stack<string> pilha;

    for (const string& el : vector) {
        if (isdigit(el[0])) {
            pilha.push(el);
        } else if (el == "+" || el == "-" || el == "*" || el == "/") {
            if (pilha.size() < 2) throw invalid_argument("Invalid postfix");
            string b = pilha.top();
            pilha.pop();
            string a = pilha.top();
            pilha.pop();
            string expr = "( " + a + " " + el + " " + b + " )";
            pilha.push(expr);
        }
    }

    if (pilha.size() != 1) throw invalid_argument("Invalid postfix");
    return pilha.top();
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

    cout << "\nReverse Polish:\n";
    for (string s : vectorize_expression("24 32 + 2 / 41 5 * +")){
        cout << s << " ";
    }

    cout << "\nSolving the Reverse Polish:\n";
    cout << calc_posfix("24 32 + 2 / 41 5 * +");

    cout << "\nChecking the Reverse Polish:\n";
    cout << check_posfix("24 32 + 2 / 41 5 * +");
    
    cout << "\nSolving the Infix:\n";
    cout << calc_infix("( ( ( 6 + 9 ) / 3 ) * ( 6 - 4 ) )");

    cout << "\nPosfix to Infix:\n";
    cout << posfix_to_infix("6 9 + 3 / 6 4 - *");
    return 0;
}
