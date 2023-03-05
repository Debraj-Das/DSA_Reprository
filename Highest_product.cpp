/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

/*
/  Find the maximum product of 3 element in array 
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
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

int product_of_3_element(int arr[], int n)
{
    sort(arr, arr + n);
    int first = arr[0] * arr[1] * arr[n - 1];
    int last = arr[n - 1] * arr[n - 2] * arr[n - 3];
    return max(first, last);
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i; i < n; ++i)
        cin >> arr[i];
    cout<<product_of_3_element(arr, n)<<endl;

    return;
}