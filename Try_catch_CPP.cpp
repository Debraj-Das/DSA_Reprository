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
    //	cin >> t;
    while (t--)
        solve(); // solve the problem inside of drive function for test cases.

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

int division(int a, int b)
{
    if (b == 0)
        throw 1;
    return (a / b);
}

void solve()
{
    int a, b, c;
    cin >> a >> b;
    try
    {
        // if (b == 0)
        //     throw 1; 
        c = division(a, b);
        cout<<c<<endl;
    }
    catch (int e)
    {
        cout << "Division by Zero\n"
             << e << endl;
    }

    return;
}