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
    // cin >> t;
    while (t--)
        solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

void solve()
{
    string s;
    cin >> s;
    vi index;
    f(0, s.size()) if (s[i] == 'x') index.push_back(i);

    // Edge case for absent of 'x' in string
    if (index.size() == 0)
    {
        cout << 0 << el;
        return;
    }
    f(0, index.size()) index[i] -= i;

    int median = index[(index.size() / 2)], ans = 0;
    f(0, index.size()) ans += abs(index[i] - median);
    cout << ans << el;
    return;
}
