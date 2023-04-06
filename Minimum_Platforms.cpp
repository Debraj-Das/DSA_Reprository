//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.

    int findPlatform(int arr[], int dep[], int n)
    {
        // Your code here
        vector<pair<int, int>> t(2 * n);
        for (int i = 0; i < n; i++)
            t[i] = {arr[i], 1};
        for (int i = n; i < 2 * n; ++i)
            t[i] = {dep[i - n], -1};
        // for (int i = 0; i < n; ++i)
        //     cout << t[i].first << ' ' << t[i].second << ' ' << t[i + n].first << ' ' << t[i + n].second << endl;
        sort(t.begin(), t.end(), [](pair<int, int> a, pair<int, int> b) -> bool
             { return (a.first < b.first) or ((a.first == b.first) and (a.second > b.second)); });
        // for (auto x : t)
        //     cout << x.first << ' ' << x.second << endl;
        int no = 0;
        for (int i = 0, cur_no = 0; i < 2 * n; ++i)
            cur_no += t[i].second, no = max(no, cur_no);
        return no;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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
        int arr[n];
        int dep[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int j = 0; j < n; j++)
        {
            cin >> dep[j];
        }
        Solution ob;
        cout << ob.findPlatform(arr, dep, n) << endl;
    }
    return 0;
}
// } Driver Code Ends