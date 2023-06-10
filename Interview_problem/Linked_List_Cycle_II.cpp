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
 **/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head || !head->next)
            return NULL;
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next, fast = fast->next->next;
            if (slow == fast)
                break;
        }
        if (slow != fast)
            return NULL;
        slow = head;
        while (slow != fast)
            slow = slow->next, fast = fast->next;
        return slow;
    }
};

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    return 0;
}
