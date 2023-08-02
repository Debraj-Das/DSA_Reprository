/**
 * Definition for singly-linked list.
 * */struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        n = no_of_list(head) - n + 1;
        if(n == 1)
        {
            ListNode *temp = head;
            delete temp;
            head = head->next;
            return head;
        }
        for(ListNode *tmp = head , *temp = nullptr; tmp; tmp = tmp->next)
        {
            n--;
            if(n == 1)
            {
                temp = tmp->next;
                tmp->next = tmp->next->next;
                delete temp;
                break;
            }
        }
        return head;
    }

    int no_of_list(ListNode *head)
    {
        int count = 0;
        while(head != nullptr)
        {
            count++;
            head = head->next;
        }

        return count;
    }
};