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
    int numIslands(vector<vector<char>> &grid)
    {
        const int r = grid.size(), c = grid[0].size();
        int ans = 0;
        queue<pair<int, int>> q;
        
        for (int i = 0, j, x, y; i < r; ++i)
            for (j = 0; j < c; ++j)
                if (grid[i][j] == '1')
                {
                    q.push({i, j});
                    grid[i][j] = '0';
                    ans++;

                    while (!q.empty())
                    {
                        x = q.front().first, y = q.front().second;
                        q.pop();
                        if (x - 1 >= 0 and grid[x - 1][y] == '1')
                            q.push({x - 1, y}), grid[x - 1][y] = '0';
                        if (x + 1 < r and grid[x + 1][y] == '1')
                            q.push({x + 1, y}), grid[x + 1][y] = '0';
                        if (y - 1 >= 0 and grid[x][y - 1] == '1')
                            q.push({x, y - 1}), grid[x][y - 1] = '0';
                        if (y + 1 < c and grid[x][y + 1] == '1')
                            q.push({x, y + 1}), grid[x][y + 1] = '0';
                    }
                }

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
