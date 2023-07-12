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

void largest_permutation(int arr[], int n, int k)
{
    vi sort_arr(arr, arr + n); // Copy the array to Vector
    sort(sort_arr.begin(), sort_arr.end(), greater<int>());
    for (int i = 0; i < n and k; ++i)
    {
        if (sort_arr[i] != arr[i])
        {
            auto it = find(arr + i, arr + n, sort_arr[i]);
            swap(*it, arr[i]);
            --k ;
        }
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    f(0, n) cin >> arr[i];
    largest_permutation(arr, n, k);
    f(0, n) cout << arr[i] << ' ';
    cout << el;

    return;
}