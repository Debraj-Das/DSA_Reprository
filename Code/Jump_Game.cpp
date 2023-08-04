#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(const vector<int>& nums) {
        const int n = nums.size();
        for(int i = 0 , maxReach = 0; i < n; i++){
            if(maxReach < i) return false;
            maxReach = max(maxReach, i + nums[i]);
        }
        return true;
    }
};