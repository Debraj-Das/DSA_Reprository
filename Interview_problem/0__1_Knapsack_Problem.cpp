//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
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
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int N) 
    { 
       // Your code here
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
                    temp[j] = max(dp[j], dp[j - wt[i - 1]] + val[i - 1]);
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
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends