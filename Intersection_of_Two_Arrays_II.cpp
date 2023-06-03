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
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        //* Using unordered_map
        // unordered_map<int, int> m;
        // vector<int> ans;
        // for (auto i : nums1)
        //     m[i]++;
        // for (auto i : nums2)
        // {
        //     if (m[i] > 0)
        //     {
        //         ans.push_back(i);
        //         m[i]--;
        //     }
        // }
        // return ans;

        //* My solution
        // const int m = nums1.size(), n = nums2.size();
        // if(m == 0 || n == 0)
        //     return {};
        // vector<int> ans;
        // int arr[1001] = {0};
        // for(int i = 0 ; i < m ; i++)
        //     arr[nums1[i]]++;
        // for(int i = 0 ; i < n ; i++)
        //     if(arr[nums2[i]] > 0)
        //     {
        //         ans.push_back(nums2[i]);
        //         arr[nums2[i]]--;
        //     }
        // return ans;

        //* Nice solution using sorting
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        int i = 0, j = 0;

        while (i < nums1.size() && j < nums2.size())
        {

            if (nums1[i] == nums2[j])
            {
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j])
                i++;

            else
                j++;
        }

        return ans;
    }
};

int32_t main()
{

    return 0;
}
