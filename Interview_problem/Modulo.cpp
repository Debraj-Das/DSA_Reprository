/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define el '\n'
#define f(a, b) for (int i = a; i < b; i++)
#define fr(a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    clock_t z = clock();

    int t = 1;
    	cin >> t;
    while (t--)
        solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

int power(int x, int y, int p)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int nCrModPFermat(int n, int r, int p = 1000000007)
{
    if (n < r)
        return 0;
    r = min(r, n - r);
    if (r == 0)
        return 1;
    int up = 1, down = 1;
    for (int i = n; i > (n - r); --i)
        up = (up * i) % p;
    for (int i = 1; i <= r; i++)
        down = (down * i) % p;

    return (up * power(down, p - 2, p)) % p;
}

void solve()
{
    // p must be a prime greater than n.
    int n, r, p = 1000000007;
    cin >> n >> r;
    cout << nCrModPFermat(n, r, p) << el;
    return;
}