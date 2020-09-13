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

vector<vector<int>> knapsack(vector<vector<int>> dp, int W, vector<int> w, int n) {
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
    
    return dp;
}

vector<int> reconstruct(vector<vector<int>> dp, vector<int> w) {
    vector<bool> taken(w.size(), false);
    
    int i = dp.size() - 1, j = dp[0].size() - 1;
    
    while(i > 0 && j > 0) {
        if (dp[i][j] == dp[i][j-1]) {
            //Item j-1 not taken
            j = j - 1;
        } else if (dp[i][j] == dp[i-w[j-1]][j-1] + w[j-1]) {
            //Item j-1 is taken
            taken[j-1] = true;
            i = i - w[j-1];
            j = j - 1;
        }
    }
    
    for(int i = taken.size() - 1; i >= 0; i--) {
        if(taken[i]) {
            w.erase(w.begin()+i);
        }
    }
    
    return w;
}

int partition3(int w, vector<int> v) {
    int n = v.size();
    vector<vector<int>> dp(w+1, vector<int>(n+1));
    
    dp = knapsack(dp, w, v, v.size());
    
    if(dp[w][n] == w) {
        // 1 partition possible
        v = reconstruct(dp, v);
        n = v.size();
        
        vector<vector<int>> dp2(w+1, vector<int>(n+1));
        
        dp2 = knapsack(dp2, w, v, v.size());
        if(dp2[w][n] == w) {
            return 1;
        }
    } else {
        return 0;
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
