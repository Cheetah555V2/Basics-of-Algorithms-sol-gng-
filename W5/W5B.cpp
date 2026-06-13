#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    char arr[100000];

public:
    Stack(){
        top = -1;
    }

    void push(char x){
        top++;
        arr[top] = x;
    }

    int pop(){
        top--;
        return arr[top + 1];
    }

    bool isEmpty(){
        return (top < 0);
    }
};

int main(){
    Stack s;
    
    string text;
    cin >> text;

    for(char i : text){
        if (i == '(' || i == '[' || i == '{'){
            s.push(i);
        }
        else{
            if (s.isEmpty()){
                cout << "no";
                return 0;
            }
            char last = s.pop();
            if ((last == '(' && i != ')') ||
                (last == '[' && i != ']') ||
                (last == '{' && i != '}')){
                    cout << "no";
                    return 0;
                }
        }
    }
    
    if (s.isEmpty()){
        cout << "yes";
    }
    else{
        cout << "no";
    }

    return 0;
}