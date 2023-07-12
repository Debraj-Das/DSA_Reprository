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
        int i, j, day = -1;

        for (i = 0, j; i < m; i++)
            for (j = 0; j < n; j++)
                if (grid[i][j] == 2)
                    q.push({i, j}), grid[i][j] = 0;

        for (int size ; size = q.size(); day++)
            while (size--)
            {
                i = q.front().first;
                j = q.front().second;
                q.pop();
                if (i > 0 and grid[i - 1][j])
                    q.push({i - 1, j}), grid[i - 1][j] = 0;
                if (i < m - 1 and grid[i + 1][j])
                    q.push({i + 1, j}), grid[i + 1][j] = 0;
                if (j > 0 and grid[i][j - 1])
                    q.push({i, j - 1}), grid[i][j - 1] = 0;
                if (j < n - 1 and grid[i][j + 1])
                    q.push({i, j + 1}), grid[i][j + 1] = 0;
            }

        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                if (grid[i][j])
                    return -1;
        return day;
    }
};

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    Solution obj;
    cout << obj.orangesRotting(grid) << '\n';

    return 0;
}
