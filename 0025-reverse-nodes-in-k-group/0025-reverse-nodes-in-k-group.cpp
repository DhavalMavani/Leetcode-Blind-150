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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        int i=0;
        while(temp && i!=k){
            temp=temp->next;
            i++;
        }
        if(i<k){
            return head;
        }

        ListNode* prev=NULL;
        ListNode* curr=head;
        i=0;
        
        while(curr && i!=k) {
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            i++;
        }
        head->next=reverseKGroup( curr, k);
        return prev;
    }
};