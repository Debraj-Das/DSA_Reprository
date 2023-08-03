#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v ;
        parenthesis("" , n , n , v);
        return v;
    }

    void parenthesis(string s , int left, int right , vector<string> &v)
    {
        if(right == 0)
        {
            v.push_back(s);
            return;
        }
        if(left > 0)
        {
            parenthesis(s + "(" , left - 1 , right , v);
        }
        if(right > left)
        {
            parenthesis(s + ")" , left , right - 1 , v);
        }
        return ;
    }
};