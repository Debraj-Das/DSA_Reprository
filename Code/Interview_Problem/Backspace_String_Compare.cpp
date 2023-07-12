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
    bool backspaceCompare(const string &s,const string &t)
    {
        for( int i = s.size() - 1 , j = t.size() - 1 , a , b ; i >= 0 or j >= 0 ; i-- , j--)
        {
            for( a = 0 ; i >= 0 and (a or s[i] == '#') ; i--) a += (s[i] == '#') ? 1 : -1;
            for( b = 0 ; j >= 0 and (b or t[j] == '#') ; j--) b += (t[j] == '#') ? 1 : -1;
            if(i >= 0 and j >= 0 and s[i] != t[j]) return false;
            if((i >= 0) != (j >= 0)) return false;
        }
        return true;
    }
};

int32_t main()
{
    string s  = "ab#cd";
    string t = "ar#cd";
    Solution obj;
    cout << obj.backspaceCompare(s,t) << endl;
    return 0;
}
