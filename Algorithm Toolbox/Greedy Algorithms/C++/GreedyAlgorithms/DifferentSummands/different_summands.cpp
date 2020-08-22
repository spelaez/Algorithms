//
//  main.cpp
//  different_summands
//
//  Created by Santiago Pelaez Rua on 22/08/20.
//  Copyright © 2020 Santiago Pelaez Rua. All rights reserved.
//

#include <iostream>
#include <vector>

using std::vector;
using std::min;

void different_summands(int n) {
    int remaining = n;
    
    vector<int> k;
    
    int i = 1;
    
    //push incremental steps
    while(remaining > 0) {
        int toGive = min(i, remaining);
        
        k.push_back(toGive);
        remaining -= toGive;
        i++;
    }
    
    //check if last 2 items are equal or last is less
    if (k.size() >= 2) {
        if (k[k.size() - 1] == k[k.size() - 2] || k[k.size() - 1] < k[k.size() - 2]) {
            k[k.size() - 2] += k[k.size() - 1];
            k.pop_back();
        }
    }
    
    std::cout << k.size() << std::endl;
    for (int i = 0; i < k.size(); i++) {
        std::cout << k[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, const char * argv[]) {
    int n;
    std::cin >> n;
    
    different_summands(n);
}
