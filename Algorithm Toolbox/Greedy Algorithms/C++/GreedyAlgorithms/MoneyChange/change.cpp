//
//  main.cpp
//  GreedyAlgorithms
//
//  Created by Santiago Pelaez Rua on 17/08/20.
//  Copyright © 2020 Santiago Pelaez Rua. All rights reserved.
//

#include <iostream>
#include <vector>

int change(int amount) {
    std::vector<short> coins = {10, 5, 1};
    int minimumCoins = 0;
    
    //first move
    for (short i = 0; i < coins.size(); ++i) {
        short coin = coins[i];
        
        if (amount >= coin) {
            minimumCoins += (amount / coin);
            amount = (amount % coin);
        }
    }
    
    return minimumCoins;
}

int main(int argc, const char * argv[]) {
    int n;
    std::cin >> n;
    
    std::cout << change(n) << std::endl;
    return 0;
}
