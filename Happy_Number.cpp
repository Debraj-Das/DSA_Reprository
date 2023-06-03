#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        int temp ;
        set<int> s;
        while (n != 1)
        {
            temp = 0;
            while (n)
            {
                temp += (n % 10) * (n % 10);
                n /= 10;
            }
            n = temp;
            if (s.find(n) != s.end())
                return false;
            s.insert(n);
        }
        return true;
    }
};

int main()
{

    return 0;
}