#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int i = 0, j = s.size() - 1;
        while(i<j)
        {
            if(non_alphanumeric(s[i]))
                i++;
            else if(non_alphanumeric(s[j]))
                j--;
            else if(tolower(s[i++]) != tolower(s[j--]))
                return false;
        }

        return true;
    }
    bool non_alphanumeric(char c)
    {
        if (c >= 'A' and c <= 'Z')
            return false;
        if (c >= 'a' and c <= 'z')
            return false;
        if (c >= '0' and c <= '9')
            return false;
        return true;
    }
};

// class Solution
// {
// public:
//     bool isPalindrome(string s)
//     {
//         string str = "";
//         for (int i = 0; s[i]; i++)
//         {
//             if (s[i] >= 'A' and s[i] <= 'Z')
//                 str += s[i] + 32;
//             else if ((s[i] >= 'a' and s[i] <= 'z') or (s[i] >= '0' and s[i] <= '9'))
//                 str += s[i];
//         }

//         for (int i = 0, j = str.size() - 1; i < j; i++, j--)
//             if (str[i] != str[j])
//                 return false;

//         return true;
//     }
// };

int main()
{
    string s = "0P";
    Solution sol;
    cout << sol.isPalindrome(s) << endl;
    return 0;
}