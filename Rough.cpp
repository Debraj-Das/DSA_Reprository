// This code create by GitHub code generator

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
#endif

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}

void rever_string(string &s)
{
    f(0, s.size() / 2)
        swap(s[i], s[s.size() - i - 1]);
    return ;
}

void solve()
{
    string s ;
    cin >> s ;
    cout<< s<<el ; 
    rever_string(s) ;
    cout<< s<<el ;
    cout<< s.length()<<el ; 
    return;
}
