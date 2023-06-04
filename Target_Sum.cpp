//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++
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
    int findTargetSumWays(vector<int> &A, int target)
    {
        // Your code here
        int sum = 0;
        for (int i = 0; i < A.size(); i++)
            sum += A[i];
        if ((sum + target) % 2)
            return 0;
        else
        {
            sum = (sum + target) / 2;
            return perfectSum(A, sum);
        }
    }
    int perfectSum(vector<int> &a, int sum)
    {
        const int n = a.size();
        // Initializing the matrix
        int tab[sum + 1];
        // Initializing the first value of matrix
        tab[0] = 1;
        for (int i = 1; i <= sum; i++)
            tab[i] = 0;

        int temp[sum + 1];

        for (int i = 1, j; i <= n; i++)
        {
            for (j = 0; j <= sum; j++)
            {
                // if the value is greater than the sum
                if (a[i - 1] > j)
                    temp[j] = tab[j];
                else
                {
                    temp[j] = tab[j] + tab[j - a[i - 1]];
                }
            }
            for (j = 0; j <= sum; j++)
                tab[j] = temp[j];
        }

        return tab[sum];
    }
};

//{ Driver Code Starts.

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int N;

        cin >> N;
        vector<int> arr(N);

        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout << ob.findTargetSumWays(arr, target);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends