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
    
    ListNode* mergeTwoLists(ListNode* curr1, ListNode* curr2) {
        if (curr1 == nullptr || curr2 == nullptr)
            return curr1 == nullptr ? curr2 : curr1;

        ListNode* head = new ListNode(-1);
        ListNode* prev = head;


        while (curr1 != nullptr && curr2 != nullptr) {
            if (curr1->val <= curr2->val) {
                prev->next = curr1;
                prev = curr1;
                curr1 = curr1->next;
            } else {
                prev->next = curr2;
                prev = curr2;
                curr2 = curr2->next;
            }
        }

        if (curr1 != nullptr) {
            prev->next = curr1;
        }

        if (curr2 != nullptr) {
            prev->next = curr2;
        }

        return head->next;
    }
    
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size()==0)
            return nullptr;
        return mergeKLists_(lists,0,lists.size()-1);
    }
    
      ListNode* mergeKLists_(vector<ListNode*>& lists,int si,int ei) {
        
          if(si==ei)
          {
              return lists[si];
          }
          if(si+1==ei)
          {
              return mergeTwoLists(lists[si],lists[si+1]);
          }
          
          int mid=(si+ei)/2;
          
        return mergeTwoLists(mergeKLists_(lists,si,mid),mergeKLists_(lists,mid+1,ei));
    }
};