#include <bits/stdc++.h>
using namespace std;

auto init = [](){
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
        int n = nums.size();
        vector<int> ans(2, -1);
        int l = 0, r = n - 1 , mid;
        // find first occurence
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (nums[mid] == target)
            {
                if(ans[0] == -1)
                    ans[1] = mid;
                ans[0] = mid;
                r = mid - 1;
            }
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        // find last occurence
        l = ans[1], r = n - 1;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (nums[mid] == target)
            {
                ans[1] = mid;
                l = mid + 1;
            }
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return ans;
    }
};


int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
#endif

    return 0;
}
