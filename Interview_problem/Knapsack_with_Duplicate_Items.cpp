//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define f(i, a, b) for (int i = a; i < b; i++)
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
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        int dp[W + 1];
        f(i, 0, W + 1) dp[i] = 0;
        int temp[W + 1];
        f(i, 1, N+1)
        {
            f(j, 0, W + 1)
            {
                if (wt[i-1] > j)
                    temp[j] = dp[j];
                else
                    temp[j] = max(dp[j], temp[j - wt[i - 1]] + val[i - 1]);
            }
            f(j, 0, W + 1) dp[j] = temp[j];
        }

        return dp[W];
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
        int N, W;
        cin >> N >> W;
        int val[N], wt[N];
        for (int i = 0; i < N; i++)
            cin >> val[i];
        for (int i = 0; i < N; i++)
            cin >> wt[i];

        Solution ob;
        cout << ob.knapSack(N, W, val, wt) << endl;
    }
    return 0;
}
// } Driver Code Ends