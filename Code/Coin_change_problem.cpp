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

int coin_change(int mon, int coin[], int n)
{
    int dp[mon + 1] = {0};
    dp[0] = 1;
    sort(coin, coin + n);
    for (int i = 0, j; i <= mon; i++)
        for (j = 0; j < n/2; j++)
            if (coin[j] > i)
                break;
            else
                dp[i] += dp[i - coin[j]];
    return dp[mon];
}

void solve()
{
    int n, x;
    cin >> n >> x;
    int a[n];
    f(i, 0, n) cin >> a[i];
    cout << coin_change(x, a, n) << el;
    return;
}