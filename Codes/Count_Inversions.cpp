
//? I need to optimized it to O(n^2) to O(n*log(n))
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        multiset<long long> store;
        long long no = 0;
        for (long long i = N - 1; i >= 0; i--)
        {
            store.insert(arr[i]);
            no += distance(store.begin(), store.lower_bound(arr[i]));
        }
        cout << no << endl;
        long long s = 0;
        long long e = N - 1;
        return inversion_count(arr, s, e);
    }

    long long merge(long long array[], long long s, long long e)
    {
        long long i = s;
        long long m = (s + e) / 2;
        long long j = m + 1;

        vector<long long> temp;

        long long cnt = 0;

        while (i <= m and j <= e)
        {
            if (array[i] < array[j])
            {
                temp.push_back(array[i]);
                i++;
            }
            else
            {
                cnt += (m - i + 1);
                temp.push_back(array[j]);
                j++;
            }
        }
        while (i <= m)
        {
            temp.push_back(array[i++]);
        }
        while (j <= e)
        {
            temp.push_back(array[j++]);
        }
        long long k = 0;
        for (long long idx = s; idx <= e; idx++)
        {
            array[idx] = temp[k++];
        }
        return cnt;
    }

    long long inversion_count(long long arr[], long long s, long long e)
    {
        // base case
        if (s >= e)
        {
            return 0;
        }
        // rec case
        long long mid = (s + e) / 2;
        long long C1 = inversion_count(arr, s, mid);
        long long C2 = inversion_count(arr, mid + 1, e);
        long long CI = merge(arr, s, e);
        return C1 + C2 + CI;
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

    long long T;
    cin >> T;

    while (T--)
    {
        long long N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}

// } Driver Code Ends