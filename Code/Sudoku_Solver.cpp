#include <bits/stdc++.h>
using namespace std;

auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        // check the validity of the given board
        vector<bool> element(9, false);
        // check each row
        for (int i = 0, j; i < 9; ++i)
        {
            fill(element.begin(), element.end(), false);
            for (j = 0; j < 9; ++j)
            {
                if (board[i][j] != '.')
                {
                    if (element[board[i][j] - '1'])
                        return;
                    element[board[i][j] - '1'] = true;
                }
            }
        }
        // check each column
        for (int j = 0, i; j < 9; ++j)
        {
            fill(element.begin(), element.end(), false);
            for (i = 0; i < 9; ++i)
            {
                if (board[i][j] != '.')
                {
                    if (element[board[i][j] - '1'])
                        return;
                    element[board[i][j] - '1'] = true;
                }
            }
        }
        // check each 3*3 sub-box
        for (int i = 0, j, k, l; i < 9; i += 3)
        {
            for (j = 0; j < 9; j += 3)
            {
                fill(element.begin(), element.end(), false);
                for (k = i; k < i + 3; ++k)
                {
                    for (l = j; l < j + 3; ++l)
                    {
                        if (board[k][l] != '.')
                        {
                            if (element[board[k][l] - '1'])
                                return;
                            element[board[k][l] - '1'] = true;
                        }
                    }
                }
            }
        }

        // solve the sudoku
        solve(board, 0, 0);
        return;
    }
    bool solve(vector<vector<char>> &board, int i, int j)
    {
        if (j == 9)
        {
            j = 0;
            i++;
        }
        while (i < 9 and board[i][j] != '.')
        {
            j++;
            if (j == 9)
            {
                j = 0;
                i++;
            }
        }
        if (i == 9)
            return true;

        vector<char> ch = validch(board, i, j);

        for(char c : ch)
        {
            board[i][j] = c;
            if(solve(board, i, j))
                return true;
        }
        board[i][j] = '.';
        return false;
    }
    vector<char> validch(vector<vector<char>> &board, int i, int j)
    {
        vector<bool> element(9, false);
        // check the row
        for (int k = 0; k < 9; ++k)
            if (board[i][k] != '.')
                element[board[i][k] - '1'] = true;
        // check the column
        for (int k = 0; k < 9; ++k)
            if (board[k][j] != '.')
                element[board[k][j] - '1'] = true;
        // check the sub-box
        int row = i / 3 * 3, col = j / 3 * 3;
        for (int k = row , l ; k < row + 3; ++k)
            for (l = col; l < col + 3; ++l)
                if (board[k][l] != '.')
                    element[board[k][l] - '1'] = true;
        vector<char> ch;
        for(int k = 0; k < 9; ++k)
            if(!element[k])
                ch.push_back(k + '1');
        return ch;
    }
};

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    return 0;
}
