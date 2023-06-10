#include <bits/stdc++.h>
using namespace std;

auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

bool topologic_sorting(int v, vector<pair<int, int>> p)
{
    vector<vector<int>> graph(v);
    for (auto i : p)
        graph[i.second].push_back(i.first);
    vector<int> in_degree(v, 0);
    for (auto i : graph)
        for (auto j : i)
            in_degree[j]++;
    queue<int> q;
    for (int i = 0; i < v; i++)
        if (in_degree[i] == 0)
            q.push(i);
    int cnt = 0 , u ;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (auto i : graph[u])
        {
            in_degree[i]--;
            if (in_degree[i] == 0)
                q.push(i);
        }
        cnt++;
    }
    return cnt == v;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    return 0;
}
