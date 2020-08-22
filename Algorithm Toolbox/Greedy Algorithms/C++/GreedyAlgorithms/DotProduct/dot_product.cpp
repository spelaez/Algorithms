//
//  main.cpp
//  DotProduct
//
//  Created by Santiago Pelaez Rua on 22/08/20.
//  Copyright © 2020 Santiago Pelaez Rua. All rights reserved.
//

#include <iostream>
#include <algorithm>

using std::sort;

//n ads
//each ad has pay per click
//each ad has an expected # of clicks per day
//distribute the ads among the slots to maximize the total reveneu
//reveneu = clicks * pay per click


//a1, a2, ..., an (profit per click of the ith ad)
//b1, b2, ..., bn (average number of click per day of the ith slot)
//partition them into n pairs (ai, bj) such that the sum of their products is maximized

long long dotProduct(int n, long long a[], long long b[]) {
    
    sort(a, a+n);
    sort(b, b+n);
    
    long long result = 0;
    
    for (int i = 0; i < n; i++) {
        result += (a[i] * b[i]);
    }
    
    return result;
}


int main(int argc, const char * argv[]) {
    int n;
    std::cin >> n;
    
    long long a[n], b[n];
    
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    
    std::cout << dotProduct(n, a, b) << std::endl;
    return 0;
}
