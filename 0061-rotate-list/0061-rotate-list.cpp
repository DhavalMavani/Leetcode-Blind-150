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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        
        int l=1;
        ListNode* t=head;
        while(t->next){
            l++;
            t=t->next;
        }
        k%=l;
        if(k==0) return head;
        
        t->next=head;
        int jump=l-k-1;

        while(jump){
            jump--;
            head=head->next;
        }
        t=head->next;
        head->next=NULL;
        return t;
    }
};