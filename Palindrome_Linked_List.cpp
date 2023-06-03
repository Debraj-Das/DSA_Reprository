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
 * */
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
    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return true;
         int count = 0 ;
        ListNode *temp = head;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        int mid = (count&1)?(count/2):(count/2)-1;
        ListNode *midNode = head;
        for(int i = 0 ; i < mid ; i++)
            midNode = midNode->next;
        ListNode *rev = reverse(midNode->next);
        ListNode *temp1 = head;
        bool ans = true;
        while (rev != nullptr)
        {
            if (temp1->val != rev->val)
            {
                ans = false;
                break;
            }
            temp1 = temp1->next;
            rev = rev->next;
        }
        midNode->next = reverse(rev);
        return ans;
    }
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

};

int32_t main()
{

    return 0;
}
