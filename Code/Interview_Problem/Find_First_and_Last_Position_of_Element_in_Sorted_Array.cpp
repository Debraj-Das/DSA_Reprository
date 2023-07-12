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
    vector<int> searchRange(vector<int> &nums, int target)
    {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        if (it == nums.end() || *it != target)
            return {-1, -1};
        auto it2 = upper_bound(nums.begin(), nums.end(), target);
        vector<int> ans = {it - nums.begin(), it2 - nums.begin() - 1};
        return ans;
    }
};

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    return 0;
}
