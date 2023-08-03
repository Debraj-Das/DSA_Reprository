#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(const string &digits)
    {
        const vector<string> map = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;

        if (digits.size() == 0)
            return ans;
        utilize(map, digits, 0, "", ans);
        return ans;
    }

    void utilize(const vector<string> &map, const string &digits, size_t index, string s, vector<string> &ans)
    {
        if (index == digits.size())
        {
            ans.push_back(s);
            return;
        }

        string letters = map[digits[index] - '2'];
        for (char &i : letters)
            utilize(map, digits, index + 1, s + i, ans);
    }
};

int main()
{
    Solution s;
    string digits = "23";
    vector<string> ans = s.letterCombinations(digits);
    for (string s : ans)
    {
        cout << s << endl;
    }

    return 0;
}