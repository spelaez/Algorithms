//
//  main.cpp
//  FibonacciSum
//
//  Created by Santiago Pelaez Rua on 15/08/20.
//  Copyright © 2020 Santiago Pelaez Rua. All rights reserved.
//

#include <iostream>

//As we need the only the last digit of fibonacci, we need to calculate Fn % 10, pisano period for 10 is 60
//In other words we need to calculate Fn % 10 = F(n%60) % 10
short fibonacci_sum(long long n) {
    short size = n % 60;
    
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
    // insert code here...
    long long n;
    std::cin >> n;
    std::cout << fibonacci_sum(n);
    
    return 0;
}
