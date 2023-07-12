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
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        int res = 0;
        for(int i = 0 , t , j; i < n ; i++)
        {
            t = 0;
            if(informTime[i] != 0) continue;
            for(j = manager[i] ; j != -1 ; j = manager[j])
                t += informTime[j];
            if(t > res) res = t;
        }
        return res;
    }
    // int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    // {
    //     vector<vector<int>> adj(n); 
    //     for (int i = 0; i < n; i++)
    //     {
    //         if (manager[i] != -1)
    //             adj[manager[i]].push_back(i);
    //     }
    //     return DFS(adj, headID, informTime);
    // }
    // int DFS(vector<vector<int>> &adj, int s, vector<int> &informTime)
    // {
    //     int res = 0;
    //     for (auto i = adj[s].begin(); i != adj[s].end(); i++)
    //         res = max(res, DFS(adj, *i, informTime));
    //     return res + informTime[s];
    // }
};

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    return 0;
}
