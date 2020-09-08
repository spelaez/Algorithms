//
//  main.cpp
//  EditDistance
//
//  Created by Santiago Pelaez Rua on 5/09/20.
//  Copyright © 2020 Santiago Pelaez Rua. All rights reserved.
//

#include <iostream>
#include <string>
using std::string;
using std::min;
using namespace std;

int editDistance(const string &s1, const string &s2) {
    int n = s1.size(), m = s2.size();
    int dp[n+1][m+1];
    dp[0][0] = 0;
    
    for(int i = 1; i <= n; i++) {
        dp[i][0] = i;
    }
    for(int j = 1; j <= m; j++) {
        dp[0][j] = j;
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int deletion = dp[i-1][j] + 1;
            int addition = dp[i][j-1] + 1;
            int match = dp[i-1][j-1];
            int mismatch = dp[i-1][j-1] + 1;
            
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = min(deletion, min(addition, match));
            } else {
                dp[i][j] = min(deletion, min(addition, mismatch));
            }
        }
    }
    
    return dp[n][m];
}

int main(int argc, const char * argv[]) {
    string s1, s2;
    cin >> s1 >> s2;
    
    cout << editDistance(s1, s2) << endl;
    return 0;
}
