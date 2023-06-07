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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;

        queue<TreeNode *> q;
        q.push(root);
        TreeNode *node;
        int size;
        while (!q.empty())
        {
            size = q.size();
            // for every level of tree
            {
                vector<int> level;
                while (size--)
                {
                    node = q.front();
                    q.pop();
                    level.push_back(node->val);
                    if (node->left)
                        q.push(node->left);
                    if (node->right)
                        q.push(node->right);
                }
                ans.push_back(level);
            }
        }
        return ans;
    }
};

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    return 0;
}
