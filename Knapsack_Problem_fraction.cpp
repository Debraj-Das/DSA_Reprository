/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

/*
* This problem is Knapsack problem, Where we use Greedy method to slove it
*   and Procesure is to find the maximum profit per weight

    This type of method their are objective function(which you want to optimized) and
    Some contraint. So depend on Containts and objective, We Create a selection method
    to filter the option for every step. By this We get the optimized Solution.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long double

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

ll Maximized_profit(int profit[], int weight[], int n, int max_weight)
{
    map<ll, int, greater<double>> store;
    ll temp;
    for (int i = 0; i < n; ++i)
    {
        temp = ((ll)profit[i]) / weight[i];
        store[temp] += weight[i];
    }
    // There the temp act like a max profit variable
    temp = 0;
    for (auto i : store)
    {
        if (max_weight > i.second)
        {
            temp += ((i.first) * (i.second));
            max_weight -= i.second;
        }
        else
        {
            temp += (max_weight) * (i.first);
            break;
        }
    }
    return temp;
}

void solve()
{
    int n, max_weigh;
    cin >> n >> max_weigh;
    int profit[n], weight[n];
    for (int i = 0; i < n; ++i)
        cin >> profit[i];
    for (int i = 0; i < n; ++i)
        cin >> weight[i];
    cout << Maximized_profit(profit, weight, n, max_weigh) << endl;

    return;
}
