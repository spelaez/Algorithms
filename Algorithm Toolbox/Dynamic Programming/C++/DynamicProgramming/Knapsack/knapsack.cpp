//
//  main.cpp
//  Knapsack
//
//  Created by Santiago Pelaez Rua on 12/09/20.
//  Copyright © 2020 Santiago Pelaez Rua. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(vector<vector<int>> dp, int W, vector<int> w, int n) {
    for (int i = 0; i <= W; i++) {
        dp[i][0] = 0;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            dp[j][i] = dp[j][i-1];
            if (j >= w[i-1]) {
                dp[j][i] = max(dp[j][i], dp[j-w[i-1]][i-1] + w[i-1]);
            }
        }
    }
    
    return dp[W][n];
}

int main(int argc, const char * argv[]) {
    int W, n;
    cin >> W >> n;
    
    vector<vector <int>> dp(W+1, vector<int>(n+1));
    vector<int> bars(n);
    
    for(int i = 0; i < n; i++) {
        cin >> bars[i];
    }
    
    std::cout << knapsack(dp, W, bars, n) << endl;
    return 0;
}
