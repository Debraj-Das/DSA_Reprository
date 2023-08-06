#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(const vector<string>& strs) {
        unordered_map<string, int> m;
        vector<vector<string>> ans;
        string temp ;
        for (auto str : strs) {
            temp = str;
            sort(temp.begin(), temp.end());

            if (m.find(temp) == m.end()) {
                m[temp] = ans.size();
                ans.push_back({str});
            } else 
                ans[m[temp]].push_back(str);
        }
        return ans;
    }
};
