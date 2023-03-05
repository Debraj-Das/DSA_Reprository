/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

/*
/ Find the maximum no of Disjoint interval in Given interval ?
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

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

int disjoint_element(vector<pair<int, int>> &arr)
{
    sort(arr.begin(), arr.end(), compare);
    int no = 1;
    pair<int, int> a = *arr.begin();
    for (auto x : arr)
    {
        if (x.second < a.second)
            a = x;
        else if (x.first > a.second)
        {
            a = x;
            ++no;
        }
    }
    return no;
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    f(0, n) cin >> arr[i].first >> arr[i].second;
    cout <<disjoint_element(arr) << endl;
    return;
}
