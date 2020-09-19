//
//  main.cpp
//  BracketsInCode
//
//  Created by Santiago Pelaez Rua on 18/09/20.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct Bracket {
    Bracket(char type, int position):
    type(type),
    position(position)
    {}
    
    bool Match(char c) {
        if (type == '(' && c == ')') {
            return true;
        }
        
        if (type == '[' && c == ']') {
            return true;
        }
        
        if (type == '{' && c == '}') {
            return true;
        }
        
        return false;
    }
    
    
    int position;
    char type;
};

string bracketsInCode(string text) {
    stack<Bracket> s;
    
    for(int i = 0; i < text.size(); i++) {
        char next = text[i];
        
        if(next == '(' || next == '[' || next == '{') {
            s.push(Bracket(next, i));
        } else if(next == ')' || next == ']' || next == '}'){
            if(s.empty()) {
                return to_string(i + 1);
            }
            
            Bracket b = s.top();
            s.pop();
            
            if(b.Match(next)) {
                continue;
            } else {
                return to_string(i + 1);
            }
        }
    }
    
    if (s.empty()) {
        return "Success";
    } else {
        return to_string(s.top().position + 1);
    }
}


int main(int argc, const char * argv[]) {
    string text;
    getline(cin, text);

    cout << bracketsInCode(text);
    return 0;
}
