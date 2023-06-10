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
 * */
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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans ;
        if (root == nullptr)
            return ans;
        helper(root, 1, ans);
        return ans;
    }
    void helper(TreeNode *root, int level, vector<int> &ans)
    {
        if (root == nullptr)
            return;
        if (level > ans.size())
            ans.push_back(root->val);
        helper(root->right, level + 1, ans);
        helper(root->left, level + 1, ans);
        return ;
    }
};

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    return 0;
}
