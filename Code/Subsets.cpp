#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(const vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        utilize(nums, 0, v, ans);
        return ans;
    }
    void utilize(const vector<int> &nums, int i , vector<int> &v , vector<vector<int>> &ans)
    {
        if(i == nums.size())
        {
            ans.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        utilize(nums, i + 1, v, ans);
        v.pop_back();
        utilize(nums, i + 1, v, ans);
        return ;
    }
};