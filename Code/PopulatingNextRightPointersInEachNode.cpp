/*
// Definition for a Node.
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        Node *p = root;

        queue<Node *> q;
        q.push(p);
        int i;
        while (!q.empty())
        {
            i = q.size();
            while ((i--) > 1)
            {
                p = q.front();
                q.pop();

                if (p == nullptr)
                    continue;
                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
                p->next = q.front();
            }
            p = q.front();
            q.pop();
            if (p)
            {
                q.push(p->left);
                q.push(p->right);
                p->next = nullptr;
            }
        }

        return root;
    }

    void print(Node *root)
    {
        if (root == nullptr)
            return;
        cout << root->val << " ";
        print(root->left);
        print(root->right);
    }
};

int main()
{
    Solution s;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    s.connect(root);

    s.print(root);

    return 0;
}