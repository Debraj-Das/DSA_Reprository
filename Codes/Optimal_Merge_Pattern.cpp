/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std;
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
        solve(); // solve the problem inside of drive function for test cases.

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

int optimal_merge_pattern(int arr[], int n)
{
    multiset<int> store;
    for (int i = 0; i < n; i++)
        store.insert(arr[i]);
    auto it = store.begin();
    int a, b, sum = 0;
    while (store.size() > 1)
    {
        it = store.begin();
        a = *it;
        ++it;
        b = *it;
        store.erase(a);
        store.erase(b);
        store.insert(a + b);
        
        sum += (a + b);
    }
    return sum;
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout << optimal_merge_pattern(arr, n) << endl;

    return;
}