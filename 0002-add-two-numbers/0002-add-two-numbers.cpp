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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=new ListNode();
        ListNode* curr= ans;
        int carry=0;

        while(l1 || l2){

            int num1=0,num2=0;
            if(l1!=NULL) num1=l1->val;
            if(l2!=NULL) num2=l2->val;

            int ans= (num1+num2+carry)%10;
            carry=(num1+num2+carry)/10;

            curr->next=new ListNode(ans);
            curr=curr->next;
            
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        if(carry) curr->next=new ListNode(carry);

        return ans->next;
    }

};