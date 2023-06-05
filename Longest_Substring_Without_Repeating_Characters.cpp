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
    int lengthOfLongestSubstring(const string &s)
    {
        int ans = 0;
        int unq[128] = {-1};
        for (int i = 0, j = 0; s[j]; ++j)
        {
            if (unq[s[j]] > i)
                i = unq[s[j]];
            else if (ans < (j - i + 1))
                ans = (j - i + 1);
            unq[s[j]] = j + 1;
        }
        return ans;
    }
    // int lengthOfLongestSubstring(const string &s)
    // {
    //     int ans = 0;
    //     bitset<128> unq(0);
    //     for (int i = 0, j = 0; s[j]; ++j)
    //     {
    //         while (unq[s[j]])
    //         {
    //             unq[s[i]] = 0;
    //             ++i;
    //         }
    //         unq[s[j]] = 1;
    //         if (ans < (j - i + 1))
    //             ans = (j - i + 1);
    //     }
    //     return ans;
    // }
};

int32_t main()
{
    string s = "abcabcbb";
    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << endl;

    return 0;
}
