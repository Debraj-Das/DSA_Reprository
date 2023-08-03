#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        const int n = nums.size();
        for(int i = 0 , j , k , sum ; i < n ; i++)
        {
            sum = -nums[i];
            j = i + 1; k = n - 1;
            while(j < k)
            {
                if(nums[j] + nums[k] == sum)
                {
                    result.push_back({nums[i], nums[j], nums[k]});
                    while(j < k && nums[j] == nums[j + 1]) j++;
                    while(j < k && nums[k] == nums[k - 1]) k--;
                    j++; k--;
                }
                else if(nums[j] + nums[k] < sum) j++;
                else k--;
            }
            while(i + 1 < n && nums[i] == nums[i + 1]) i++;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> result = s.threeSum(nums);
    for (auto i : result) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}