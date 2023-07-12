//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

int sumDiff(int S[], int n);

// Driver program to test above function
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
        int n;
        cin >> n;
        int S[n];
        for (int i = 0; i < n; i++)
            cin >> S[i];
        cout << sumDiff(S, n) << endl;
        ;
    }

    return 0;
}
// } Driver Code Ends

/*You are required to complete this method */
int sumDiff(int S[], int n)
{
    // Your code here
    int i, sum_of_diff;
    n--;
    for (i = 0; i < n; ++i)
    {
        sum_of_diff = S[i + 1] - S[i];
        S[i] = sum_of_diff;
    }
    for (i = 0, sum_of_diff = 0; i < n; ++i)
        sum_of_diff += ((i + 1) * (n - i) * S[i]);
    return sum_of_diff;
}