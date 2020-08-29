//
//  main.cpp
//  BinarySearch
//
//  Created by Santiago Pelaez Rua on 29/08/20.
//  Copyright © 2020 Santiago Pelaez Rua. All rights reserved.
//

#include <iostream>

int binarySearch(int a[], int k, int l, int r) {
    while (l <= r) {
        int middle = (l + ((r-l)/2));
        
        if (a[middle] == k) {
            return middle;
        } else if (k > a[middle]) {
            l = middle + 1;
        } else {
            r = middle - 1;
        }
    }
    
    return -1;
}

int binarySearch(int a[], int n, int k) {
    return binarySearch(a, k, 0, n - 1);
}


int main(int argc, const char * argv[]) {
    int n;
    std::cin >> n;
    
    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    int k;
    std::cin >> k;
    for (int i = 0; i < k; i++) {
        int ki;
        std::cin >> ki;
        
        std::cout << binarySearch(a, n, ki) << " ";
    }
    
    std::cout << std::endl;
    return 0;
}
