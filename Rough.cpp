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
    vector<vector<int>> a(n, vector<int>(n)), b(n, vector<int>(n)), c(n, vector<int>(n));
    f(i, 0, n) f(j, 0, n) cin >> a[i][j];
    f(i, 0, n) f(j, 0, n) cin >> b[i][j];

    // multiply a and b and store in c (matrix multiplication)
    f(i, 0, n)
    {
        f(j, 0, n)
        {
            // initialize c[i][j] to 0
            c[i][j] = 0;
            // calculate c[i][j]
            f(k, 0, n) c[i][j] += a[i][k] * b[k][j];
            // print c[i][j]
            cout << c[i][j] << " ";
        }
        // print new line for new row
        cout << el;
    }

    return;
}

