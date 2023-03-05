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
    //	cin >> t;
    while (t--)
        solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

bool compare(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }

int meet_room(vector<pair<int, int>> &arr)
{
    sort(arr.begin(), arr.end(), compare);
    int no = 0;
    multiset<int> store;
    for (auto x : arr)
    {
        while (store.size() and *store.begin() < x.first)
            store.erase(store.begin());
        store.insert(x.second);
        no = max(no, (int)store.size());
    }
    return no;
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    f(0, n) cin >> arr[i].first >> arr[i].second;
    cout << meet_room(arr) << endl;
    return;
}