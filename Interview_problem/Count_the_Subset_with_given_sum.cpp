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

#define mod 1000000007

int perfectSum(int a[], int n, int sum)
{

    // Initializing the matrix
    int tab[n + 1][sum + 1];
    // Initializing the first value of matrix
    tab[0][0] = 1;
    for (int i = 1; i <= sum; i++)
        tab[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            // if the value is greater than the sum
            if (a[i - 1] > j)
                tab[i][j] = tab[i - 1][j];
            else
            {
                tab[i][j] = (tab[i - 1][j] + tab[i - 1][j - a[i - 1]]) % mod;
            }
        }
    }

    f(i, 0, n + 1) cout << tab[i][0] << " ";
    cout << el;

    return tab[n][sum];
}

void solve()
{
    int n, sum;
    cin >> n >> sum;
    int a[n];
    f(i, 0, n) cin >> a[i];

    int dp[n + 1][sum + 1];

    dp[0][0] = 1;
    f(i, 1, sum + 1) dp[0][i] = 0;

    f(i, 1, n + 1) f(j, 0, sum + 1)
    {
        if (a[i - 1] <= j)
            dp[i][j] = (dp[i - 1][j - a[i - 1]] + dp[i - 1][j]) % mod;

        else
            dp[i][j] = dp[i - 1][j];
    }
    cout << dp[n][sum] << el;

    cout << perfectSum(a, n, sum) << el;
    return;
}
