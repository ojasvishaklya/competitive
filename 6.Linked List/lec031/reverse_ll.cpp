class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev=nullptr;
        ListNode* nxt;

        while(head)
        {
            nxt=head->next;
            head->next=prev;
            prev=head;
            head=nxt;
        }
        return prev;
    }
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev=nullptr;
        ListNode* nxt;

        while(head)
        {
            nxt=head->next;
            head->next=prev;
            prev=head;
            head=nxt;
        }
        return prev;
    }

    ListNode* reverseData(ListNode* head)
    {
        //reverse(mid->next)
        //compare
        //reverse(mid->next)
    }
};