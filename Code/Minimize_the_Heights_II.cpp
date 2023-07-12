
//* links --> https://www.geeksforgeeks.org/minimize-the-maximum-difference-between-the-heights/
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int getMinDiff(int arr[], int n, int k)
    {
        //* I did not understand of the solution and it has another solution T(n) and S(1)
        // GFG Solution time complexity O(nlogn) and space complextiy O(1)
        sort(arr, arr + n);
        // Maximum possible height difference
        int ans = arr[n - 1] - arr[0];

        int tempmin, tempmax;
        tempmin = arr[0];
        tempmax = arr[n - 1];

        for (int i = 1; i < n; i++)
        {

            // If on subtracting k we got
            // negative then continue
            if (arr[i] - k < 0)
                continue;

            // Minimum element when we
            // add k to whole array
            tempmin = min(arr[0] + k, arr[i] - k);

            // Maximum element when we
            // subtract k from whole array
            tempmax = max(arr[i - 1] + k, arr[n - 1] - k);

            ans = min(ans, tempmax - tempmin);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends