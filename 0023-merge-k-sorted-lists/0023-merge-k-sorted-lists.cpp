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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode* str = new ListNode();
        ListNode* ans=str;
        while(true){
            int index;
            bool flag=false;
            for(int i=0;i<lists.size();i++){
                if(lists[i]!=NULL){
                    index=i;
                    flag=true;
                    break;
                }
            }
            if(flag){
                for(int i=0;i<lists.size();i++){
                    if(lists[i]!=NULL && lists[i]->val<lists[index]->val){
                        index=i;
                    }
                }
                str->next=lists[index];
                str=str->next;
                lists[index]=lists[index]->next;
            }
            else{
                break;
            }

        }
        return ans->next;
        
    }
};