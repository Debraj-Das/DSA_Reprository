#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define sp ' '

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0, j; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> arr[i][j];

    for (int i = 1; i < n; i++)
        arr[i][0] += arr[i - 1][0];
    for (int i = 1; i < m; i++)
        arr[0][i] += arr[0][i - 1];

    for (int i = 1, j; i < n; i++)
        for (j = 1; j < m; j++)
            arr[i][j] += min(arr[i - 1][j], arr[i][j - 1]);

    cout << arr[n - 1][m - 1] << el;

    return 0;
}