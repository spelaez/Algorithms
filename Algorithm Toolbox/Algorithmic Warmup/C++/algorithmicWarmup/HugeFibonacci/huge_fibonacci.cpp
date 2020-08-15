//
//  main.cpp
//  HugeFibonacci
//
//  Created by Santiago Pelaez Rua on 15/08/20.
//  Copyright © 2020 Santiago Pelaez Rua. All rights reserved.
//

#include <iostream>
long long fibonacci_fast_modulo(long long n, long long m) {
    if (n <= 1) {
        return n;
    }
    
    long long numbers[n + 1];
    numbers[0] = 0;
    numbers[1] = 1;
    
    for (int i = 2; i < n + 1; ++i) {
        numbers[i] = (numbers[i - 1] + numbers[i - 2]) % m;
    }

    return numbers[n];
}

long long pisanoPeriod(long long m) {
    if (m == 2) {
        return 3;
    }
    
    long long remainders[m * m];
    remainders[0] = 1;
    remainders[1] = 1;
    
    bool periodFound = false;
    long long periodCount = 3;
    long long i = 2;
    
    while (!periodFound && i < (m * m)) {
        remainders[i] = (remainders[i - 1] + remainders[i - 2]) % m;
        
        periodCount++;
        if (i >= 3) {
            if (remainders[i] == 1 && remainders[i - 1] == 0) {
                //period found
                periodFound = true;
            }
        }
        
        ++i;
    }

    return periodFound ? periodCount - 2 : periodCount;
}

long long hugeFibonacci(long long n, long long m) {
    long long period = pisanoPeriod(m);
    
    long long remainder = n % period;
    
    return fibonacci_fast_modulo(remainder, m);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    long long n, m;
    std::cin >> n >> m;
    std::cout << hugeFibonacci(n, m) << std::endl;
    
    return 0;
}
