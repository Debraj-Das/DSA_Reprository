//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find majority element(return if present) in the array if not present then return (-1)
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        // your code here
        int element, frequency, i;
        // If major element present then try to find
        for (i = 1, element = a[0], frequency = 1; i < size; ++i)
        {
            if (a[i] == element)
                frequency++;
            else
            {
                frequency--;
                if (frequency == 0)
                    element = a[i], frequency = 1;
            }
        }
        // calculated the frequency of element, for check element is major or not 
        for (i = 0, frequency = 0; i < size; ++i)
            if (a[i] == element)
                frequency++;
        // if element frequency if more than (size/2) then it major element otherwise not
        return (frequency>(size/2))?element:(-1);
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends


