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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd=new ListNode();
        ListNode* even=new ListNode();
        ListNode* evenFirstNode=even;
        ListNode* oddFirstNode=odd;
        bool toogle=true;

        while(head!=NULL){
            if(toogle){
                odd->next=head;
                head=head->next;
                odd=odd->next;
                odd->next=NULL;
                toogle=false;
            }
            else{
                even->next=head;
                head=head->next;
                even=even->next;
                even->next=NULL;
                toogle=true;
            }
        }
        odd->next=evenFirstNode->next;
        return oddFirstNode->next;
    }
};