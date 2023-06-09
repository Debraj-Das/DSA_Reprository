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
        if (grid.empty())
            return 0;
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!visited[i][j] and grid[i][j] == '1')
                {
                    dfs(grid, visited, i, j);
                    ans++;
                }
        return ans;
    }
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int i, int j)
    {
        if (i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size() or grid[i][j] == '0' or visited[i][j])
            return;
        visited[i][j] = true;
        dfs(grid, visited, i - 1, j);
        dfs(grid, visited, i + 1, j);
        dfs(grid, visited, i, j - 1);
        dfs(grid, visited, i, j + 1);
        return;
    }
};

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    return 0;
}
