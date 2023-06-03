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
    int firstUniqChar(string s)
    {
        int arr[26] = {0};
        for (auto i : s)
            arr[i - 'a']++;
        for (int i = 0; s[i]; i++)
            if (arr[s[i] - 'a'] == 1)
                return i;
        return -1;
    }
};

int32_t main()
{

    return 0;
}
