#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int i = 0, j = nums.size() - 1, k = 0;
        while (k <= j)
            switch (nums[k])
            {
            case 2:
                swap(nums[j], nums[k]), j--;
                break;
            case 0:
                swap(nums[i], nums[k]), i++;
            default:
                k++;
            }
        return;
    }
};