#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(const vector<vector<int>>& matrix) {
    int r1 = 0, r2 = matrix.size()-1 , r ;
    int c1 = 0, c2 = matrix[0].size()-1 , c ;
        vector<int> ans;
        while(r1 <= r2 && c1 <= c2){
            for(c = c1; c <= c2; c++) ans.push_back(matrix[r1][c]);
            for(r = r1+1; r <= r2; r++) ans.push_back(matrix[r][c2]);
            if(r1 < r2 && c1 < c2){
                for(c = c2-1; c > c1; c--) ans.push_back(matrix[r2][c]);
                for(r = r2; r > r1; r--) ans.push_back(matrix[r][c1]);
            }
            r1++; r2--; c1++; c2--;
        }  
        return ans;
    }
};