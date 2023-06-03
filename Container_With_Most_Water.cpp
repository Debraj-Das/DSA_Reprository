#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int area = 0;
        for (int i = 0, j = height.size() - 1; i < j; (height[i] < height[j]) ? i++ : j--)
            area = max(area, min(height[i], height[j]) * (j - i));
        return area;
    }
};

int main()
{
    return 0;
}