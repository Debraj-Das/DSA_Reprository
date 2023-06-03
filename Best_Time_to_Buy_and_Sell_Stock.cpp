#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // nice solution O(n , 1)
        int min_price = INT_MAX;
        int max_profit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < min_price)
                min_price = prices[i];
            else 
                max_profit = max(max_profit, prices[i] - min_price);
        }
        return max_profit;
    }
    // int maxProfit(vector<int> &prices)
    // {
    //     // find greatest stack
    //     stack<int> s;
    //     for (int i = prices.size() - 1; i >= 0; i--)
    //     {
    //         if (s.empty() or (prices[i] >= s.top()))
    //         {
    //             cout<<prices[i]<<endl;
    //             s.push(prices[i]);
    //         }
    //     }
    //     cout << s.size() << endl;
    //     // find greatest difference
    //     int max_diff = 0;
    //     for (int i = 0; i < prices.size() - 1; i++)
    //     {
    //         if (prices[i] == s.top())
    //             s.pop();
    //         max_diff = max(max_diff, s.top() - prices[i]);
    //     }
    //     return max_diff;
    // }
};

int main()
{
    vector<int> v = {3, 3};
    Solution s;
    cout << s.maxProfit(v) << endl;

    return 0;
}