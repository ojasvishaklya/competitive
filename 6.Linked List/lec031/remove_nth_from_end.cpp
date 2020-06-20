/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       
        if(!head || n<0 )return head;
        if(!head->next && n==1)return head->next;
        ListNode* slow=head;
        ListNode* fast=head;
        while(n-->0)
            fast=fast->next;
        if(fast==nullptr)
            return head->next;
        while(fast->next!=nullptr)
        {
            fast=fast->next;
            slow=slow->next;
        }
        cout<<slow->val;
       slow->next=slow->next->next;
        return head;
    }
};