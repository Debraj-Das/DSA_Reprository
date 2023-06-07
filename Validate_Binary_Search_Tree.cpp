#include <bits/stdc++.h>
using namespace std;

auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

/**
 * Definition for a binary tree node.
 **/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isValidBST(TreeNode *root , long long max_value = LONG_LONG_MAX , long long min_value = LONG_LONG_MIN)
    {
        if(root == nullptr)
            return true;
        if(root->val <max_value and root->val> min_value and isValidBST(root->left , root->val , min_value) and isValidBST(root->right , max_value , root->val))
            return true;
        return false;
    }
    
   
};

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    return 0;
}
