//
//  main.cpp
//  PartitioningSouvenirs
//
//  Created by Santiago Pelaez Rua on 13/09/20.
//  Copyright © 2020 Santiago Pelaez Rua. All rights reserved.
//

#include <iostream>
#include <vector>
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

int partition3(int w, vector<int> v) {
    int n = v.size();
    vector<vector<int>> dp(w+1, vector<int>(n+1));
    
    int x = knapsack(dp, w, v, n);
    
    if(x == w) {
        vector<vector<int>> dp2(w*2+1, vector<int>(n+1));
        int y = knapsack(dp2, w*2, v, n);
        
        if(y == 2*w) {
            vector<vector<int>> dp3(w*3+1, vector<int>(n+1));
            int z = knapsack(dp3, w*3, v, n);
            
            if (z == 3*w) {
                return 1;
            }
        }
    }

    return 0;
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    if (n < 3) {
        cout << 0;
        return 0;
    }
    
    vector<int> v(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    
    if (sum % 3 != 0) {
        cout << 0;
        return 0;
    }
    
    int w = sum / 3;
    
    cout << partition3(w, v) << endl;
    return 0;
}
