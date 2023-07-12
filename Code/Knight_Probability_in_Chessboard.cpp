#include <bits/stdc++.h>
using namespace std;

auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution
{
public:
    double knightProbability(int n, int k, int row, int column)
    {
        int dp[n][n], temp[n][n];
        memset(dp, 0, sizeof(dp));
        memset(temp, 0, sizeof(temp));

        dp[row][column] = 1;
        int dx[] = {1, 1, 2, 2, -1, -1, -2, -2}, i;
        int dy[] = {2, -2, 1, -1, 2, -2, 1, -1}, j;

        for (int step = 0, d, x, y; step < k; step++)
        {
            for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                if(dp[i][j])
                    for (d = 0; d < 8; d++)
                    {
                        x = i + dx[d];
                        y = j + dy[d];
                        if (x >= 0 && x < n && y >= 0 && y < n)
                            temp[x][y] += dp[i][j] / 8.0;
                    }
            for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                    dp[i][j] = temp[i][j], temp[i][j] = 0;
        }

        double ans = 0;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                ans += dp[i][j];

        return ans;
    }
};

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    return 0;
}
