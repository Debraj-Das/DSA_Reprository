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

void solve()
{
    string a, b;
    cin >> a >> b;
    int n = a.size() + 1, m = b.size() + 1;
    int matrix[m][n];
    cout << "Matrix : " << el;
    for (int i = 0, j, ele_min; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            if (i == 0)
                matrix[i][j] = j;
            else if (j == 0)
                matrix[i][j] = i;
            else if (a[j - 1] == b[i - 1])
                matrix[i][j] = matrix[i - 1][j - 1];
            else
            {
                ele_min = min(matrix[i - 1][j], matrix[i][j - 1]);
                ele_min = min(ele_min, matrix[i - 1][j - 1]);
                matrix[i][j] = 1 + ele_min;
            }
            cout << matrix[i][j] << ' ';
        }
        cout << el;
    }
    cout << "NO of operation : " << matrix[m - 1][n - 1] << el;
    return;
}