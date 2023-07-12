#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        if (n == 0)
            return;
        else if (m == 0)
        {
            for (int i = 0; i < n; i++)
                nums1[i] = nums2[i];
            return;
        }
        else
        {
            for (int i = m - 1, j = m + n - 1; i >= 0; i--, j--)
            {
                nums1[j] = nums1[i];
                nums1[i] = 0;
            }
            int i, j, k;
            for (i = n, j = 0, k = 0; i < m + n and j < n; k++)
            {
                if (nums1[i] < nums2[j])
                    nums1[k] = nums1[i++];
                else
                    nums1[k] = nums2[j++];
            }
            while (j < n)
                nums1[k++] = nums2[j++];
            return;
        }
    }
};

int main()
{

    // [4,0,0,0,0,0]
    // 1
    // [1,2,3,5,6]
    // 5
    Solution s;
    vector<int> nums1 = {4, 0, 0, 0, 0, 0}, nums2 = {1, 2, 3, 5, 6};
    s.merge(nums1, 1, nums2, 5);
    for (auto i : nums1)
        cout << i << " ";
    return 0;
}