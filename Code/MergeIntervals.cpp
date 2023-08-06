#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    bool compare(vector<int> a, vector<int> b) {
        if(a[0] < b[0]) return true;
        else if(a[0] == b[0]) return a[1] < b[1];
        else return false;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector<vector<int>> ans;
        const int n = intervals.size();
        for(int i = 0 , j = 0 , l , r ; i < n ; i = j) {
            l = intervals[i][0];
            r = intervals[i][1];
            j = i + 1;
            while(j < n && intervals[j][0] <= r) {
                r = max(r, intervals[j][1]);
                j++;
            }
            ans.push_back({l, r});
        }
        return ans;
    }
   
};