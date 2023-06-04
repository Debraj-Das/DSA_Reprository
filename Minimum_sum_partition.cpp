//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

#define f(i, a, b) for (int i = a; i < b; i++)

class Solution
{

public:
    int minDifference(int arr[], int n)
    {
        // Calculate sum of all elements
        int sum = 0;
        f(i, 0, n)
            sum += arr[i];

        return (sum - 2 * subset_sum_problem(arr, n, sum / 2));
    }

    int subset_sum_problem(int a[], int n, int sum)
    {
        bool dp[n + 1][sum + 1];

        // intiallizing the dp array
        f(i, 0, n + 1) dp[i][0] = true;
        f(i, 1, sum + 1) dp[0][i] = false;

        // Itearative Logics
        f(i, 1, n + 1) f(j, 1, sum + 1)
            dp[i][j] = (a[i - 1] <= j) ? (dp[i - 1][j - a[i - 1]] or dp[i - 1][j]) : dp[i - 1][j];

        // Printing the result
        for(int i = sum; i >= 0; i--)
            if(dp[n][i])
                return i;
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
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.minDifference(a, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends