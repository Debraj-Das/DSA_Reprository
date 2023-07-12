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

int rod_cutting(int len, int lenth[], int price[], int n)
{
    if (len == 0 || n == 0)
        return 0;
    int dp[len + 1];
    dp[0] = 0;
    for (int i = 1, j , mx ; i <= len; i++)
    {
        for (j = 0, mx = INT_MIN; j < n; j++)
            if (lenth[j] <= i)
                mx = max(mx, price[j] + dp[i - lenth[j]]);
        dp[i] = mx;
    }
    return dp[len];
}

void solve()
{
    int n, len;
    cin >> n >> len;
    int lenth[n], price[n];
    f(i, 0, n) cin >> lenth[i];
    f(i, 0, n) cin >> price[i];
    cout << rod_cutting(len, lenth, price, n) << el;
    return;
}