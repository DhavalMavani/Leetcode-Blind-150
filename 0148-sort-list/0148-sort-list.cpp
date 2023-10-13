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

private:
    ListNode* merge(ListNode* n1,ListNode* n2){
        ListNode* dummy=new ListNode();
        ListNode* ans=dummy;
        while(n1!=NULL and n2!=NULL){
            if(n1->val < n2->val){
                dummy->next=n1;
                n1=n1->next;
                dummy=dummy->next;
                dummy->next=NULL;
            }
            else{
                dummy->next=n2;
                n2=n2->next;
                dummy=dummy->next;
                dummy->next=NULL;
            }
        }
        if(n1!=NULL){
            dummy->next=n1;
        }
        else{
            dummy->next=n2;
        }

        return ans->next;
    };

    ListNode* mergeSort(ListNode* node){
        if(node->next==NULL){
            return node;
        }

        ListNode* dummy= new ListNode();
        dummy->next=node;
        ListNode* slow=dummy;
        ListNode* fast=dummy;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        fast=slow->next;
        slow->next=NULL;
        ListNode* n1=mergeSort(node);
        ListNode* n2=mergeSort(fast);
        return merge(n1,n2);
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }

        return mergeSort(head);


    }
};