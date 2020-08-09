//
//  main.cpp
//  FibonacciLastDigit
//
//  Created by Santiago Pelaez Rua on 9/08/20.
//  Copyright © 2020 Santiago Pelaez Rua. All rights reserved.
//

#include <iostream>

int fibonacciLastDigit(int n) {
    if (n <= 1) {
        return n;
    }
    
    int numbers[n + 1];
    numbers[0] = 0;
    numbers[1] = 1;
    
    for (int i = 2; i < n + 1; i++) {
        numbers[i] = (numbers[i - 1] + numbers[i - 2]) % 10;
    }
    
    return numbers[n];
}

int main(int argc, const char * argv[]) {
    int n = 0;
    std::cin >> n;
    
    std::cout << fibonacciLastDigit(n) << '\n';
    return 0;
}

