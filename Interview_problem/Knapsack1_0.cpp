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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int t = 1;
    //	cin >> t;
    while (t--)
        solve();

    return 0;
}

vector<vector<int>> dp;

int knapsack(int n, int w, int wt[], int val[])
{
    // base case
    if (n == 0 || w == 0)
        return 0;
    // memoization
    if (dp[w][n] != -1)
    {
        return dp[w][n];
    }
    // choice diagram
    if (wt[n - 1] <= w)
    {
        return dp[w][n] = max(val[n - 1] + knapsack(n - 1, w - wt[n - 1], wt, val), knapsack(n - 1, w, wt, val));
    }
    else
        return dp[w][n] = knapsack(n - 1, w, wt, val);
}

void solve()
{
    int n, w;
    cin >> n >> w;
    int wt[n], val[n];
    f(i, 0, n) cin >> wt[i];
    f(i, 0, n) cin >> val[i];
    dp.resize(w + 1, vector<int>(n + 1, -1));
    cout << knapsack(n, w, wt, val) << el;

    return;
}