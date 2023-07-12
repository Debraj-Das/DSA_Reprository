/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define el '\n'
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //	cin >> t;
    while (t--)
        solve();

    return 0;
}

void DFS(int node, vector<int> adj[], bool vis[])
{
    vis[node] = true;
    cout << node << " ";
    for (auto it : adj[node])
        if (!vis[it])
            DFS(it, adj, vis);
}

void solve()
{
    int v;
    cin >> v;
    vector<int> adj[v];
    int e;
    cin >> e;
    f(i, 0, e)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    bool vis[v] = {false};
    int comp = 0;
    f(i, 0, v) if (!vis[i])
    {
        comp++;
        DFS(i, adj, vis);
        cout << el;
    }
    cout << "Total Connected Components: " << comp << el;

    return;
}