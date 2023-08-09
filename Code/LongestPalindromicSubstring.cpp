#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string longestPalindrome(const string &s)
    {
        if (s.length() == 1)
            return s;
        const int n = s.length();
        bool dp[n + 1][n];

        for (int i = 0, j; i <= n; i++)
            for (j = 0; j < n; j++)
                dp[i][j] = (i < 2);

        for (int i = 2, j; i <= n; i++)
            for (j = 0; i + j <= n; j++)
                dp[i][j] = (s[j] == s[i + j - 1] and dp[i - 2][j+1]);


        for (int i = n, j; i; i--)
            for (j = 0; i + j <= n; j++)
                if (dp[i][j])
                    return s.substr(j, i);
        return "";
    }
};

int main()
{
    string s = "abcba";
    Solution obj;
    cout << obj.longestPalindrome(s) << '\n';
    return 0;
}