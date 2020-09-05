//
//  main.cpp
//  PrimitiveCalculator
//
//  Created by Santiago Pelaez Rua on 4/09/20.
//  Copyright © 2020 Santiago Pelaez Rua. All rights reserved.
//

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

void minOperations(int n, int t[]){
    if (n <= 1) {
        return;
    }
    
    for(int i = 2; i <= n ;i++) {
        t[i] = t[i-1] + 1;
        if (i % 2 == 0) t[i] = min(t[i], t[i/2] + 1);
        if (i % 3 == 0) t[i] = min(t[i], t[i/3] + 1);
    }
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    
    int t[n+1];
    fill(t, t+n+1, 0);
    
    minOperations(n, t);
    cout << t[n] << endl;
    
    vector<int> v;
    v.push_back(n);
    
    while (n > 1) {
        if(n % 3 == 0 && t[n/3] + 1 == t[n]) {
            n = n/3;
        } else if (n % 2 == 0 && t[n/2] + 1 == t[n]) {
            n = n/2;
        } else {
            n = n - 1;
        }
        
        v.push_back(n);
    }
    
    reverse(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
    return 0;
}
