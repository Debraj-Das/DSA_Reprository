//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {
        // code here
        int *rm = new int[2];
        long long int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += arr[i];
            arr[i]--; // for changing the index the element
        }
        int diff = sum - ((n * 1ll * (n + 1)) / 2);
        for (int i = 0; i < n;)
        {
            while (arr[i] == i)
                ++i;
            if (arr[arr[i]] == arr[i])
            {
                rm[0] = arr[i] + 1;
                break;
            }
            else
                swap(arr[i], arr[arr[i]]);
        }
        rm[1] = rm[0] - diff;
        return rm;
    }
};

//{ Driver Code Starts.

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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends




class Solution_author{
public:
    int *findTwoElement(int *arr, int n) {
        int *ans = new int[2], i;
        for (i = 0; i < n; i++) {
            if (arr[abs(arr[i]) - 1] > 0)
                arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
            else
                ans[0] = abs(arr[i]);
        }
        for (i = 0; i < n; i++) {
            if (arr[i] > 0) ans[1] = i + 1;
        }
        return ans;
    }
};