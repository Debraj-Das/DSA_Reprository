#include <bits/stdc++.h>

using namespace std;

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // no of nodes in A = m
        int m = 0 ;
        ListNode *temp = headA;
        while(temp)
        {
            m++;
            temp = temp->next;
        }
        // no of nodes in B = n
        int n = 0;
        temp = headB;
        while(temp)
        {
            n++;
            temp = temp->next;
        }
        // move the pointer of the longer list by |m-n| steps
        if(m > n)
        {
            int diff = m - n;
            while(diff--)
                headA = headA->next;
        }
        else
        {
            int diff = n - m;
            while(diff--)
                headB = headB->next;
        }
        // now both the pointers are at same distance from the intersection point
        // move both the pointers until they meet
        while(headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }
        // return any one of the pointers
        return headA;
    }
};


int main()
{
    return 0;
}