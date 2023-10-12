/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        unordered_set <ListNode*> st;

        while(headA!=NULL){
            st.emplace(headA);
            headA=headA->next;
        }

        while(headB!=NULL){
            if(st.find(headB)==st.end()){
                headB=headB->next;
            }
            else{
                return headB;
            }
        }
        return NULL;
    }
};