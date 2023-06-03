#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        int sum = n, pre = n - 1;
        for (int i = 2; 2 * i <= n; i++)
        {
            pre = (pre * (n - 2 * i + 1) * (n - 2 * i + 2)) / (i * (n - i + 1));
            sum += pre;
        }
        return sum;
    }
};

int main()
{
    Solution s;
    cout << s.climbStairs(4) << endl;
    return 0;
}