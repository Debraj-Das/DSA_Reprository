//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        // Your code here
        vector<long long> largeElement(n);
        stack<long long> store;
        for (int i = n - 1; i >= 0; --i)
        {
            while ((!store.empty()) and (store.top() <= arr[i]))
                store.pop();
            if (store.empty())
                largeElement[i] = -1;
            else
                largeElement[i] = store.top();
            store.push(arr[i]);
        }
        return largeElement;
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
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution obj;
        vector<long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

//* author solution

// Function to return Next larger elements

class Solution_author
{
public:
    // Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        stack<long long> s;
        vector<long long> res(n);

        // traversing the array from last element in backward direction.
        for (int i = n - 1; i >= 0; i--)
        {
            // while element at top of stack is less than or equal to
            // current array element, we pop elements from the stack.
            while (!s.empty() and s.top() <= arr[i])
                s.pop();

            // if stack becomes empty, we store -1 in the answer list
            // else we store the top element of the stack.
            if (s.empty())
                res[i] = -1;
            else
                res[i] = s.top();

            // pushing the current array element into the stack.
            s.push(arr[i]);
        }
        // returning the list.
        return res;
    }
};