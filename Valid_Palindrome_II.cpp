#include <bits/stdc++.h>
using namespace std;

auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution
{
public:
    bool validPalindrome(const string &s)
    {
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            if (s[l] != s[r])
                return isPalindrome(s, l + 1, r) or isPalindrome(s, l, r - 1);
            l++;
            r--;
        }
        return true;
    }
    bool isPalindrome(const string &s, int l, int r)
    {
        while (l < r)
        {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    string s;
    cin >> s;
    Solution ob;
    cout << ob.validPalindrome(s) << endl;

    return 0;
}
// aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga