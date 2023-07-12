#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
        vector<TreeNode *> v, v2;
        v.push_back(root);
        TreeNode *temp;
        while (!v.empty())
        {
            cout<<v.size()<<endl;
            for (auto i : v)
               { if (i)
                    cout << i->val << " ";
                else
                    cout << "NULL ";}
            cout << endl;

            if (check(v))
                return false;
            for (auto i : v)
            {
                if (i)
                {
                    v2.push_back(i->left);
                    v2.push_back(i->right);

                    cout<<i->left<<" "<<i->right<<endl;
                }
                v = v2;
                v2.clear();
            }
        }
        return true;
    }
    bool check(vector<TreeNode *> v)
    {
        int n = v.size();
        for (int i = 0; i < n / 2; i++)
        {
            if ((v[i] == nullptr and v[n - i - 1] == nullptr))
                continue;
            else if ((v[i] == nullptr and v[n - i - 1] != nullptr) or (v[i] != nullptr and v[n - i - 1] == nullptr))
                return true;
            else if ((v[i]->val != v[n - i - 1]->val))
                return true;
        }
        return false;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    cout<<root->left<<' '<<root->right<<endl;
    root->left->left = nullptr;
    root->left->right = new TreeNode(3);
    cout<<root->left->left<<' '<<root->left->right<<endl;
    root->right->left = nullptr;
    root->right->right = new TreeNode(3);
    cout<<root->right->left<<' '<<root->right->right<<endl;
    Solution s;
    cout << s.isSymmetric(root) << endl;
    return 0;
}