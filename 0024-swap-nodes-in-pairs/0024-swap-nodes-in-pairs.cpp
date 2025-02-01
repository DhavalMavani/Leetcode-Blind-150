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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* dummy=new ListNode(-1,head);
        ListNode* prev=dummy;

        while(head && head->next){
            ListNode* temp=head->next->next;
            head->next->next=head;
            prev->next=head->next;
            head->next=temp;
            prev=head;
            head=head->next;
        }

        return dummy->next;
    }
};