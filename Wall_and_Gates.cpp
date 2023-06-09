#include <bits/stdc++.h>
using namespace std;

#define INF 2147483647

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
    void wallsAndGates(vector<vector<int>> &rooms)
    {
        const int m = rooms.size(), n = rooms[0].size();
        queue<pair<int, int>> q;
        int i, j, dist = 1;

        for (i = 0, j; i < m; i++)
            for (j = 0; j < n; j++)
                if (rooms[i][j] == 0)
                    q.push({i, j});

        for (int size; size = q.size(); dist++)
            while (size--)
            {
                i = q.front().first;
                j = q.front().second;
                q.pop();
                if (i > 0 and rooms[i - 1][j] > dist)
                    q.push({i - 1, j}), rooms[i - 1][j] = dist;
                if (i < m - 1 and rooms[i + 1][j] > dist)
                    q.push({i + 1, j}), rooms[i + 1][j] = dist;
                if (j > 0 and rooms[i][j - 1] > dist)
                    q.push({i, j - 1}), rooms[i][j - 1] = dist;
                if (j < n - 1 and rooms[i][j + 1] > dist)
                    q.push({i, j + 1}), rooms[i][j + 1] = dist;
            }
        return;
    }
};

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    vector<vector<int>> rooms = {{INF, -1, 0, INF},
                                 {INF, INF, INF, -1}, 
                                 {INF, -1, INF, -1}, 
                                 {0, -1, INF, INF}};
    Solution obj;
    obj.wallsAndGates(rooms);
    for (auto &i : rooms)
    {
        for (auto &j : i)
            cout << j << ' ';
        cout << '\n';
    }

    return 0;
}
