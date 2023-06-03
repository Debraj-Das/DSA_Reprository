#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(char a , stack<char> &st) {
        if(st.empty()) return false;
        if(a == ')' && st.top() == '(') return true;
        if(a == '}' && st.top() == '{') return true;
        if(a == ']' && st.top() == '[') return true;
        return false;
    }

    bool isValid(string s) {
        stack<char> st;
        for(int i = 0 ; i < s.size() ; i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
            else {
                if(check(s[i] , st)) st.pop();
                else return false;
            }
        }
        if(st.empty()) return true;
        return false;
    }
};

int main() {
    string s = "()[]{}(";
    Solution sol;
    cout << sol.isValid(s) << endl;
    return 0;
}