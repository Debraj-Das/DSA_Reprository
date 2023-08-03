#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        vector<string> v = {"1" , "11" , "21" , "1211" , "111221"};
        if(n <= 5)
            return v[n-1];
        string s = v[4];
        for(int i = 5 ; i < n ; i++)
            s = say(s);
        return s ;
    }
    string say(const string &s){
        string ans = "";
        int i = 0 , j = 0 , n = s.size();
        while(i < n){
            while(j < n && s[i] == s[j])
                j++;
            ans += to_string(j-i) + s[i];
            i = j;
        }
        return ans;
    }
};