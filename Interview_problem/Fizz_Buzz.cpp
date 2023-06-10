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
    vector<string> fizzBuzz(int n)
    {
        vector<string> ans(n);
        for (int i = 1; i <= n; i++)
        {
            if (i % 15 == 0)
                ans[i - 1] = "FizzBuzz";
            else if (i % 5 == 0)
                ans[i - 1] = "Buzz";
            else if (i % 3 == 0)
                ans[i - 1] = "Fizz";
            else
                ans[i - 1] = to_string(i);
        }
        return ans;
    }
};

int32_t main()
{

    return 0;
}
