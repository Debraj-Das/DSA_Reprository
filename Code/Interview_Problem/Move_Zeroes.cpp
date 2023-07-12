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
    void moveZeroes(vector<int> &nums)
    {
        // int n = nums.size() - 1;
        // for(int i = n ; i >=0 ; i--)
        // if(nums[i] == 0)
        // {
        //     for(int j = i ; j < n ; j++)
        //         swap(nums[j],nums[j+1]);
        //     n--;
        // }
        // return ;

        // Nice problem solution
        
        for(int j =  0, i = 0; j < nums.size(); j++){
            if(nums[j] != 0){
                swap(nums[j], nums[i]);
                i++;
            }
        }
    }
};

int32_t main()
{

    return 0;
}
