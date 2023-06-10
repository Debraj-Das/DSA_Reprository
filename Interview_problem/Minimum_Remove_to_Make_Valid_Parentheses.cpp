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

    //* complexity O(n , n)
    // string minRemoveToMakeValid(string &s)
    // {
    //     stack<int> st;
    //     for (int i = 0; i < s.size(); i++)
    //     {
    //         if (s[i] == '(')
    //             st.push(i);
    //         else if (s[i] == ')')
    //         {
    //             if (!st.empty())
    //                 st.pop();
    //             else
    //                 s[i] = '*';
    //         }
    //     }
    //     while(!st.empty())
    //     {
    //         s[st.top()] = '*';
    //         st.pop();
    //     }

    //     // remove all * from string time complexity O(n) and space complexity O(1)
    //     s.erase(remove(s.begin(), s.end(), '*'), s.end());

    //     return s;
    // }

    //* complexity O(n , 1)
    string minRemoveToMakeValid(string &s)
    {
        int no_of_brucket, i;
        for (i = 0, no_of_brucket = 0; s[i]; ++i)
            if (s[i] == '(')
                ++no_of_brucket;
            else if (s[i] == ')')
                no_of_brucket ? --no_of_brucket : s[i] = '*';

        if (no_of_brucket)
            for (i = s.size() - 1, no_of_brucket = 0; i >= 0; --i)
                if (s[i] == ')')
                    ++no_of_brucket;
                else if (s[i] == '(')
                    no_of_brucket ? --no_of_brucket : s[i] = '*';

        // remove all * from string time complexity O(n) and space complexity O(1)
        s.erase(remove(s.begin(), s.end(), '*'), s.end());

        return s;
    }
};

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    return 0;
}
