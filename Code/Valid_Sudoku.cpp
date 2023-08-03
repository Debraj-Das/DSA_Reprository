#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<bool> v(9);
        // row check
        for (int i = 0, j; i < 9; i++)
        {
            fill(v.begin(), v.end(), false);
            for (j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                if (v[board[i][j] - '1'])
                    return false;
                v[board[i][j] - '1'] = true;
            }
        }
        // column check
        for (int j = 0, i; j < 9; j++)
        {
            fill(v.begin(), v.end(), false);
            for (i = 0; i < 9; i++)
            {
                if (board[i][j] == '.')
                    continue;
                if (v[board[i][j] - '1'])
                    return false;
                v[board[i][j] - '1'] = true;
            }
        }
        // sub-box check
        vector<pair<int, int>> subBox = {{0, 0}, {0, 3}, {0, 6}, {3, 0}, {3, 3}, {3, 6}, {6, 0}, {6, 3}, {6, 6}};
        for (int p = 0, i, j, f, s; p < 9; p++)
        {
            fill(v.begin(), v.end(), false);
            f = subBox[p].first;
            s = subBox[p].second;
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    if (board[f + i][s + j] == '.')
                        continue;
                    if (v[board[f + i][s + j] - '1'])
                        return false;
                    v[board[f + i][s + j] - '1'] = true;
                }
            }
        }

        return true;
    }
};