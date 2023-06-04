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

void solve()
{
    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    f(i, 0, n)
    {
        cin >> a[i];
        sum += a[i];
    }

    if (sum & 1)
    {
        cout << false << el;
        return;
    }
    else 
        sum /= 2;

    bool dp[n + 1][sum + 1];

    // intiallizing the dp array
    f(i, 0, n + 1) dp[i][0] = true;
    f(i, 1, sum + 1) dp[0][i] = false;

    // Itearative Logics
    f(i, 1, n + 1) f(j, 1, sum + 1)
        dp[i][j] = (a[i - 1] <= j) ? (dp[i - 1][j - a[i - 1]] or dp[i - 1][j]) : dp[i - 1][j];

    // Printing the result
    cout << dp[n][sum] << el;

    return;
}

class Solution
{
public:
    int equalPartition(int n, int a[])
    {
        // code here
        int sum = 0;
        for (int i = 0; i < n; ++i)
            sum += a[i];

        if (sum & 1)
            return false;

        bool dp[n + 1][sum + 1];

        // intiallizing the dp array
        f(i, 0, n + 1) dp[i][0] = true;
        f(i, 1, sum + 1) dp[0][i] = false;

        // Itearative Logics
        f(i, 1, n + 1) f(j, 1, sum + 1)
            dp[i][j] = (a[i - 1] <= j) ? (dp[i - 1][j - a[i - 1]] or dp[i - 1][j]) : dp[i - 1][j];

        return dp[n][sum];
    }
};