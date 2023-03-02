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

int profit_max(int profit[], int days[], int n, int day_max)
{
    map<int, int, greater<int>> store;
    for (int i = 0; i < n; i++)
        store[profit[i]] = days[i];
    int deal[day_max] = {0}, j;
    for (auto i : store)
    {
        for (j = (i.second - 1); j >= 0; --j)
            if (deal[j] == 0)
            {
                deal[j] = i.first;
                break;
            }
    }
    //* If you want to day profit then comment the below lines
    // for (j = 0; j < day_max; ++j)
    //     cout << deal[j] << ' ';
    // cout << endl;

    int sum;
    for (j = 0, sum = 0; j < day_max; ++j)
        sum += deal[j];
    return sum;
}

void solve()
{
    int n;
    cin >> n;
    int profit[n], days[n], day_max = 0, i;
    for (i = 0; i < n; ++i)
        cin >> profit[i];
    for (i = 0; i < n; ++i)
    {
        cin >> days[i];
        if (days[i] > day_max)
            day_max = days[i];
    }
    cout <<"Max profit: "<< profit_max(profit, days, n, day_max) << endl;

    return;
}
