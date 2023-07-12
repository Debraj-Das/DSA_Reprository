/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define el '\n'
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
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

class Solution
{
public:
    // string longestCommonPrefix(vector<string>& strs) {
    //     string ans = "" ;
    //     int n = strs.size() ;
    //     for(int i = 0; i < strs[0].size(); i++){
    //         char ch = strs[0][i] ;
    //         for(int j = 1; j < n; j++){
    //             if(strs[j][i] != ch) return ans ;
    //         }
    //         ans += ch ;
    //     }
    //     return ans ;
    // }
    string longestCommonPrefix(vector<string> &strs)
    {
        auto min_element = strs.begin();
        for (auto it = strs.begin(); it != strs.end(); it++)
        {
            if ((*it).size() < (*min_element).size())
                min_element = it;
        }
        swap(*min_element, strs[0]);
        const int n = strs.size();
        const int m = strs[0].size();
        char ch;
        for (int i = 0; i < m; i++)
        {
            ch = strs[0][i];
            for (int j = 1; j < n; j++)
            {
                if (strs[j][i] != ch)
                    return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<string> v(n);
    f(i, 0, n) cin >> v[i];
    Solution ob;
    cout << ob.longestCommonPrefix(v) << el;

    return;
}