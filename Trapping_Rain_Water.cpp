#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size(), M, i , ans = 0 , Max;
        for (i = 1, M = 0; i < n; i++)
            if (height[i] > height[M])
                M = i;
        for (i = 1, Max = height[0]; i < M; i++)
        {
            Max = max(Max, height[i]);
            ans += Max - height[i];
        }
        for (i = n - 2, Max = height[n-1]; i > M; i--)
        {
            Max = max(Max, height[i]);
            ans += Max - height[i];
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << sol.trap(height) << endl;
    return 0;
}