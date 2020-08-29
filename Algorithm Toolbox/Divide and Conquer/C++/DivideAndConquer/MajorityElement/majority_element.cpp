//
//  main.cpp
//  MajorityElement
//
//  Created by Santiago Pelaez Rua on 29/08/20.
//  Copyright © 2020 Santiago Pelaez Rua. All rights reserved.
//

#include <iostream>
#include <algorithm>

using std::max;

int countInRange(int a[], int k, int l, int r) {
    int times = 0;
    
    for (int i = l; i <= r; i++) {
        if (a[i] == k) {
            times++;
        }
    }
    
    return times;
}

int majorityElement(int a[], int l, int r) {
    if (l == r) {
        return a[l];
    }
    
    int m = l + (r-l)/2;
    
    int b = majorityElement(a, l, m);
    int c = majorityElement(a, m + 1, r);
    
    if (b == c) {
        return b;
    }
    
    int countB = countInRange(a, b, l, r);
    int countC = countInRange(a, c, l, r);
    
    
    return countB > countC ? b : c;
}

int majorityElement(int a[], int n) {
    int candidate = majorityElement(a, 0, n - 1);
    
    int count = countInRange(a, candidate, 0, n - 1);
    
    return count > n/2 ? 1 : 0;
}

int main(int argc, const char * argv[]) {
    int n;
    std::cin >> n;
    
    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::cout << majorityElement(a, n) << std::endl;
    return 0;
}
