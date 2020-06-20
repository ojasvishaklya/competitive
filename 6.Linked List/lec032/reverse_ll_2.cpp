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
    
    ListNode* realH=nullptr;
    ListNode* realT=nullptr;
    ListNode* tempH=nullptr;
    ListNode* tempT=nullptr;
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        if(!head || !head->next || m==n)return head;
      
        realH=head;
        
        int i=1;
        
        while(head)
        {
            while(i>=m && i<=n && head)
            {
                if(realT)
                realT->next=nullptr;
                ListNode* temp=head->next;
                head->next=nullptr;
                addNode(head);
                head=temp;
                
                i++;
            }
            
            if(tempH && tempT)
            {
                tempH->next=head;
                if(realT)
                realT->next=tempT;
                else
                realH=tempT;
                break;
            }
            
            realT=head;
            head=head->next;
            i++;
        }
        
        
        return realH;
    }
    
    void addNode(ListNode* head)
    {
        if(!tempH && !tempT)
        {
            tempH=head;
            tempT=head;
        }
        else{
            head->next=tempT;
            tempT=head;
        }
        return;
    }
};