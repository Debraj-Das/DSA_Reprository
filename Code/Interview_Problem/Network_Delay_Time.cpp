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
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        k--;
        for (auto &time : times)
            time[0]--, time[1]--;
        vector<vector<pair<int, int>>> graph(n);
        for (auto &time : times)
            graph[time[0]].push_back({time[1], time[2]});
        vector<int> dist(n, INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        pair<int, int> p;
        int d, node, next, nextD;
        while (!pq.empty())
        {
            p = pq.top();
            d = p.first;
            node = p.second;
            pq.pop();
            if (dist[node] < d)
                continue;
            for (auto &NO : graph[node])
            {
                next = NO.first;
                nextD = NO.second;
                if (dist[next] > dist[node] + nextD)
                {
                    dist[next] = dist[node] + nextD;
                    pq.push({dist[next], next});
                }
            }
        }
        int ans = *max_element(dist.begin(), dist.end());
        return ans == INT_MAX ? -1 : ans;
    }
};

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    return 0;
}
