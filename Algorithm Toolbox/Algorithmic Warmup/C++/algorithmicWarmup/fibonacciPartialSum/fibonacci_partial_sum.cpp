//
//  main.cpp
//  fibonacciPartialSum
//
//  Created by Santiago Pelaez Rua on 15/08/20.
//  Copyright © 2020 Santiago Pelaez Rua. All rights reserved.
//

#include <iostream>
#include <algorithm>

short fibonacci_sum(long long n) {
    short size = n % 60;
    
    if (n == -1) {
        return 0;
    }
    
    if (size <= 1) {
        return size;
    }
    
    short numbers[size + 1];
    numbers[0] = 0;
    numbers[1] = 1;
    
    short solution = 1;
    
    for (long long i = 2; i < size + 1; i++) {
        numbers[i] = (numbers[i - 1] + numbers[i - 2]) % 10;
        solution += numbers[i];
        solution %= 10;
    }
    
    return solution;
}

int main(int argc, const char * argv[]) {
    long long n, m;
    std::cin >> m >> n;
    
    short fn = fibonacci_sum(n);
    short fm1 = fibonacci_sum(m-1);
    
    short solution = (fn - fm1);
    if (solution < 0) {
        solution += 10;
        solution = solution % 10;
    }
    
    std::cout << solution;
    return 0;
}
