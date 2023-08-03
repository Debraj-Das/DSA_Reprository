
#include <bits/stdc++.h>
using namespace std;

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
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        return symmetric(root->left, root->right);
    }
    bool symmetric(TreeNode *left, TreeNode *right)
    {
        if (left == NULL and right == NULL)
            return true;
        if (left == NULL or right == NULL)
            return false;

        if (left->val != right->val)
            return false;

        return symmetric(left->left, right->right) and symmetric(left->right, right->left);
    }
};