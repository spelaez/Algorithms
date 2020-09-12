//
//  main.cpp
//  LongestCommonSubsequence3
//
//  Created by Santiago Pelaez Rua on 7/09/20.
//  Copyright © 2020 Santiago Pelaez Rua. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using std::string;
using std::min;
using namespace std;

int lcs(vector<int> &s1, vector<int> &s2, vector<int> &s3) {
    int n = s1.size(), m = s2.size(), l = s3.size();
    int dp[n+1][m+1][l+1];
    dp[0][0][0] = 0;
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++)
        dp[i][j][0] = 0;
    }
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= l; j++)
        dp[i][0][j] = 0;
    }
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= l; j++)
        dp[0][i][j] = 0;
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int k = 1; k <= l; k++) {
                int match = dp[i-1][j-1][k-1];
                int other1 = dp[i-1][j][k];
                int other2 = dp[i][j-1][k];
                int other3 = dp[i][j][k-1];
                
                int other = max(other1, max(other2, other3));
                
                if (s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]) {
                    dp[i][j][k] = match + 1;
                } else {
                    dp[i][j][k] = other;
                }
            }
        }
    }
    
    return dp[n][m][l];
}

int main(int argc, const char * argv[]) {
    int n, m, l;
    cin >> n;
    
    vector<int> s1(n);
    for (int i = 0; i < n; i++){
        cin >> s1[i];
    }
    
    cin >> m;
    vector<int> s2(m);
    for (int j = 0; j < m; j++) {
        cin >> s2[j];
    }
    
    cin >> l;
    vector<int> s3(l);
    for(int i = 0; i < l; i++){
        cin >> s3[i];
    }
    
    cout << lcs(s1, s2, s3) << endl;
}
