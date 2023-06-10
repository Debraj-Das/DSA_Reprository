//{ Driver Code Starts
// Initial template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// #define int long long

class Solution
{
public:
    long long int p = 1000000007;
    long long int power(long long int x, int y)
    {
        long long int res = 1;
        x = x % p;
        while (y > 0)
        {
            if (y & 1)
                res = (res * x) % p;
            y = y >> 1;
            x = (x * x) % p;
        }
        return res;
    }

    int ncr(int n, int r)
    {
        if (n < r)
            return 0;
        r = min(r, n - r);
        if (r == 0)
            return 1;
        long long int up = 1, down = 1;
        for (int i = n; i > (n - r); --i)
            up = (up * i) % p;
        for (int i = 1; i <= r; i++)
            down = (down * i) % p;

        return (up * power(down, p - 2)) % p;
    }
};

//{ Driver Code Starts.

int32_t main()
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
        int n, r;
        cin >> n >> r;
        Solution ob;
        cout << ob.ncr(n, r) << endl;
    }
    return 0;
}

// } Driver Code Ends

//* author solution

class Solution_author
{
public:
    int nCr(int n, int r)
    {
        int mod = 1000000007;
        int C[r + 1];
        memset(C, 0, sizeof(C));

        C[0] = 1; // Top row of Pascal Triangle

        // One by constructs remaining rows of Pascal
        // Triangle from top to bottom
        for (int i = 1; i <= n; i++)
        {
            // Fill entries of current row using previous
            // row values
            for (int j = min(i, r); j > 0; j--)
            {
                // nCj = (n-1)Cj + (n-1)C(j-1);
                C[j] = (C[j] + C[j - 1]) % mod;
            }
        }
        return C[r] % mod;
    }
};
