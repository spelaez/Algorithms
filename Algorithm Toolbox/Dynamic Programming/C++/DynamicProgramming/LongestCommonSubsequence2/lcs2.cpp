//
//  main.cpp
//  LongestCommonSubsequence2
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

vector<int> lcs(vector<int> &s1, vector<int> &s2) {
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
            
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = min(deletion, min(addition, match));
            } else {
                dp[i][j] = min(deletion, addition);
            }
        }
    }
    int matches = 0;
    int i = n;
    int j = m;
    vector<int> seq;
    
    while (i != 0 && j != 0) {
        if (i > 0 && dp[i][j] == dp[i-1][j] + 1) {
            i--;
        } else if (j > 0 && dp[i][j] == dp[i][j-1] + 1) {
            j--;
        } else if (dp[i][j] == dp[i-1][j-1]){
            i--;
            j--;
            seq.push_back(s1[i]);
            matches++;
        } else {
            i--;
            j--;
        }
    }
    reverse(seq.begin(), seq.end());
    
    return seq;
}

int main(int argc, const char * argv[]) {
    int n, m;
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
    
    vector<int> s3 = lcs(s1, s2);
    cout << s3.size() << endl;
    return 0;
}
