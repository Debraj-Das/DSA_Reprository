#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        const int n = matrix.size();
        for (int m = 0, i, j, prev, k; m < n / 2; m++)
        {
            for (k = 0; k < (n - 1 - 2 * m); k++)
            {
                i = m, j = m + 1, prev = matrix[m][m];
                while (j < n - m)
                {
                    swap(prev, matrix[i][j]);
                    j++;
                }
                j--, i++;
                while (i < n - m)
                {
                    swap(prev, matrix[i][j]);
                    i++;
                }
                i--, j--;
                while (j >= m)
                {
                    swap(prev, matrix[i][j]);
                    j--;
                }
                j++, i--;
                while (i >= m)
                {
                    swap(prev, matrix[i][j]);
                    i--;
                }
            }
        }
    }
};

// Additional solution approach from toppers

class Solution_topper
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        const int n = matrix.size();
        for (register int i = 0 , j; i < n / 2; ++i)
            for (j = i; j < n - 1 - i; ++j)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = tmp;
            }
    }
};