//
//  main.cpp
//  StackWithMax
//
//  Created by Santiago Pelaez Rua on 20/09/20.
//

#include <iostream>
#include <stack>
#include <string>

using namespace std;

template <typename T>
class StackMax {
public:
    void process(const string command) {
        if(command == "push") {
            int v;
            cin >> v;
            push(v);
        } else if (command == "pop") {
            pop();
        } else if (command == "max") {
            cout << getMax() << endl;
        }
    }
    
    int getMax() {
        return maxes.top();
    }
    
    void push(int v) {
        s.push(v);
        
        if(maxes.empty() || (maxes.top() <= v))
            maxes.push(v);
    }
    
    void pop() {
        if(s.top() == maxes.top()) {
            maxes.pop();
        }
        
        s.pop();
    }
    
private:
    stack<T> s;
    stack<T> maxes;
};

int main(int argc, const char * argv[]) {
    StackMax<int> s;
    int count;
    cin >> count;
    
    for(int i = 0; i < count; i++) {
        string op;
        cin >> op;
        s.process(op);
    }
    
    return 0;
}
