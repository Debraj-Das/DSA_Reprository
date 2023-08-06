#include <bits/stdc++.h>

using namespace std;

int uniquePaths(int m, int n) {
    int dp[m][n];
    for(int i=0;i<m;i++){
        dp[i][0] = 1;
    }
    for(int i=0;i<n;i++){
        dp[0][i] = 1;
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];

}

class Solution {
public:
    int uniquePaths(const int &m,const int &n) {
        long long ans = 1;
        const int &a = min(m-1,n-1);
        for(int i=0;i<a;i++){
            ans *= (m+n-2-i);
            ans /= (i+1);
        }
        return ans;
    }
};