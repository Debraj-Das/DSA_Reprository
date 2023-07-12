//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#define mod 1000000007
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
    int countPartitions(int n, int d, vector<int> &arr)
    {
        // Code here
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];

        if ((sum + d) % 2)
            return 0;
        else
            sum = (sum + d) / 2;

        return perfectSum(arr, n, sum);
    }

    int perfectSum(vector<int> &a, int n, int sum)
    {

        // Initializing the matrix
        int tab[sum + 1];
        // Initializing the first value of matrix
        tab[0] = 1;
        for (int i = 1; i <= sum; i++)
            tab[i] = 0;
        
        int temp[sum+1] ;

        for (int i = 1 , j; i <= n; i++)
        {
            for (j = 0; j <= sum; j++)
            {
                // if the value is greater than the sum
                if (a[i - 1] > j)
                    temp[j] = tab[j];
                else
                {
                    temp[j] = (tab[j] + tab[j - a[i - 1]]) % mod;
                }
            }
            for(j=0;j<=sum;j++) tab[j] = temp[j];
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
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            arr.push_back(x);
        }
        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends

// 888441282