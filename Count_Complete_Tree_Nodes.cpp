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
    TreeNode *create(vector<int> v)
    {
        TreeNode *root = nullptr;
        if (v.size() == 0)
            return root;
        root = new TreeNode(v[0]);
        queue<TreeNode *> q;
        q.push(root);
        int i = 1;
        while (!q.empty() && i < v.size())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (v[i] != -1)
            {
                temp->left = new TreeNode(v[i]);
                q.push(temp->left);
            }
            i++;
            if (i < v.size() && v[i] != -1)
            {
                temp->right = new TreeNode(v[i]);
                q.push(temp->right);
            }
            i++;
        }
        return root;
    }
    void del()
    {
        if (this->left)
            this->left->del();
        if (this->right)
            this->right->del();
        delete this;
    }
};

class Solution
{
public:
    int height(TreeNode *root)
    {
        int h = -1;
        while (root)
        {
            h++;
            root = root->left;
        }
        return h;
    }

    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int h = height(root);
        int no = (1 << h);
        while (h--)
            if (h == height(root->right))
            {
                no += (1 << h);
                root = root->right;
            }
            else
                root = root->left;
        return no;
    }
};

#include "./Header/debug.hpp"

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    TreeNode *root;
    int n;
    long long int no = 0;
    vector<int> v;
    Solution ob;
    time(1)
    {
        n = getRandomNumber(0, 200);
        v.clear();
        v = RandomVector(n, 1, 200);
        root = root->create(v);
        if (ob.countNodes(root) != n)
        {
            cout << no << " ) Wrong Answer\n";
            cout << "Expected: " << n << "\n";
            cout << "Found: " << ob.countNodes(root) << "\n";
            cout << "Input: ";
            for (int i : v)
                cout << i << " ";
            cout << "\n";
            return 1;
        }
        no++;
    }
    cout << no << " no of test Accepted\n";
    return 0;
}
