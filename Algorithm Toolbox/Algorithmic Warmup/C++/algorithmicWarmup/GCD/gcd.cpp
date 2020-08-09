//
//  main.cpp
//  GCD
//
//  Created by Santiago Pelaez Rua on 9/08/20.
//  Copyright © 2020 Santiago Pelaez Rua. All rights reserved.
//

#include <iostream>

int gcd(int a, int b) {
    int remainder = -1;
    
    while (remainder != 0) {
        remainder = a % b;
        
        a = b;
        b = remainder;
    }
    
    return a;
}

int main(int argc, const char * argv[]) {
    int a, b;
    std::cin >> a >> b;
    
    std::cout << gcd(a, b) << std::endl;
    return 0;
}
