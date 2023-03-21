//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution
{
public:
    int minJumps(int arr[], int n)
    {
        // Your code here
        if (n == 0)
            return 0;
        int step = 1;
        for (int i = 0, j, index; (i + arr[i]) < n-1; ++step)
        {
            if (arr[i] <= 0)
                return -1;
            for (j = (i + 2), index = (i + 1); (j - i) <= arr[i]; ++j)
                if ((j + arr[j]) > (index + arr[index]))
                    index = j;
            i = index;
            // cout << index << endl;   // To Show the jump indexs
        }
        return step;
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
        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.minJumps(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends