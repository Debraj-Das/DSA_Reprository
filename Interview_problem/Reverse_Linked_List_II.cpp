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
 * Definition for singly-linked list.
 *  */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
            return head;
        ListNode *prev = nullptr, *cur = head;
        for (int i = 1; i < left; ++i)
        {
            prev = cur;
            cur = cur->next;
        }
        ListNode *leftNode = prev, *leftHead = cur;
        for (int i = left; i < right; ++i)
            cur = cur->next;
        ListNode *rightNode = cur, *rightHead = cur->next;
        rightNode->next = nullptr;
        reverse(leftHead);
        if (leftNode)
            leftNode->next = rightNode;
        else
            head = rightNode;
        leftHead->next = rightHead;
        return head;
    }

    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = nullptr, *cur = head;
        while (cur)
        {
            ListNode *tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;
    }

    // ListNode *reverseBetween(ListNode *head, int left, int right)
    // {
    //     if (left == right)
    //         return head;

    //     ListNode *dummy = new ListNode(0, head);
    //     ListNode *pre = dummy;
    //     for (int i = 0; i < left - 1; ++i)
    //         pre = pre->next;

    //     ListNode *cur = pre->next;
    //     for (int i = 0; i < right - left; ++i)
    //     {
    //         ListNode *tmp = cur->next;
    //         cur->next = tmp->next;
    //         tmp->next = pre->next;
    //         pre->next = tmp;
    //     }

    //     return dummy->next;
    // }
};

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    return 0;
}
