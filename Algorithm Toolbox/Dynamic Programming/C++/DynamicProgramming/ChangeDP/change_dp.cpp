//
//  main.cpp
//  ChangeDP
//
//  Created by Santiago Pelaez Rua on 4/09/20.
//  Copyright © 2020 Santiago Pelaez Rua. All rights reserved.
//

#include <iostream>
#include <limits>
using namespace std;

int *t;

int coins[3] = {1, 3, 4};

int minimumCoinsFor(int m) {
    t[0] = 0;
    
    for(int i = 1; i <= m; i++) {
        t[i] = numeric_limits<int>::max();
        for(int j = 0; j < 3; j++) {
            int coin = coins[j];
            
            if(i >= coin) {
                int minCoins = t[i - coin] + 1;
                if (minCoins < t[i]) {
                    t[i] = minCoins;
                }
            }
        }
    }
    
    return t[m];
}

int main(int argc, const char * argv[]) {
    int m;
    
    cin >> m;
    t = new int[m+1];
    
    cout << minimumCoinsFor(m);
    return 0;
}
