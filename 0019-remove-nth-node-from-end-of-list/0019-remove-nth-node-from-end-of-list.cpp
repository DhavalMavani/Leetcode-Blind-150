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
        ListNode* curr=new ListNode();
        curr->next=head;

        ListNode* temp=curr;
        int len=0;
        while(head){
            len++;
            head=head->next;
        }
        len=len-n;

        head=curr;
        while(len--) curr=curr->next;
        curr->next=curr->next->next;
        return head->next;
    }
};