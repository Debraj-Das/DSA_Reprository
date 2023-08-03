#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int n = nums.size();
        if(n < 4)
        {
            for(int i = 0; i < n; i++)
            {
                if(nums[i] == target)
                    return i;
            }
            return -1;
        }
        int ind = indexFirst(nums);
        int l , r , mid ;
        if(ind == 0) l = 0 , r = n - 1;
        else if(target >= nums[0]) l = 0 , r = ind - 1;
        else l = ind , r = n - 1;

        while(l <= r)
        {
            mid = (l + r) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
    int indexFirst(vector<int> &nums)
    {
        const int n = nums.size();
        if(nums[0] < nums[n - 1])
            return 0;
        else if(nums[n- 1] < nums[n-2])
        return n-1 ;

        int l = 1 , r = n - 2 , index;
        while(l<=r)
        {
            index = (l + r) / 2;
            if(nums[index] > nums[index + 1])
                return index + 1;
            else if(nums[index] < nums[index - 1])
                return index;
            else if(nums[index] > nums[0])
                l = index + 1;
            else
                r = index - 1;
        }
        return index ;
    }
};