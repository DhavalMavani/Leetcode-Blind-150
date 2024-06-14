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
    ListNode* reverse(ListNode* head){
        ListNode *curr=head,*prev=NULL;

        while(curr){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        ListNode *l1=head;
        ListNode *slow=head, *fast= head, *prev=head;
        while(fast->next && fast->next->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }           
        ListNode* l2=slow->next;
        slow->next=NULL;
        l2=reverse(l2);

        while(l1 && l2){
            ListNode* l1_next=l1->next;
            ListNode* l2_next=l2->next;
            
            l1->next=l2;
            l2->next=l1_next;
            
            l2=l2_next;
            l1=l1_next;
        }
        
    }
};