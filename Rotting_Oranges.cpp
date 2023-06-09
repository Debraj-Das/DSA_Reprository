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
    int orangesRotting(vector<vector<int>> &grid)
    {
        const int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int d[m][n];
        for (int i = 0, j; i < m; i++)
            for (j = 0; j < n; j++)
                d[i][j] = grid[i][j] % 2 ? (m * n + 1) : 0;

        for (int i = 0, j, day, size, x, y; i < m; i++)
            for (j = 0; j < n; ++j)
            {
                if (grid[i][j] < 2)
                    continue;
                for (day = 1, size = 1, q.push({i, j}); size; day++, size = q.size())
                    while (size--)
                    {
                        x = q.front().first;
                        y = q.front().second;
                        q.pop();
                        if (x > 0 and d[x - 1][y] > day)
                            q.push({x - 1, y}), d[x - 1][y] = day;
                        if (x < m - 1 and d[x + 1][y] > day)
                            q.push({x + 1, y}), d[x + 1][y] = day;
                        if (y > 0 and d[x][y - 1] > day)
                            q.push({x, y - 1}), d[x][y - 1] = day;
                        if (y < n - 1 and d[x][y + 1] > day)
                            q.push({x, y + 1}), d[x][y + 1] = day;
                    }
            }

        int ans = 0;
        for (int i = 0, j; i < m; i++)
            for (j = 0; j < n; j++)
                ans = max(ans, d[i][j]);
        return ans == m * n + 1 ? -1 : ans;
    }
};

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};

    return 0;
}
