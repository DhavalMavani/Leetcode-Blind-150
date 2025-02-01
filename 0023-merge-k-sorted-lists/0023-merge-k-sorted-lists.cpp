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

        ListNode* ans= new ListNode();
        ListNode* curr= ans;

        priority_queue <pair<int,int>,vector<pair<int,int>>, greater<> > pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL) pq.emplace(lists[i]->val,i);
        }

        while (!pq.empty()){
            curr->next= lists[pq.top().second];
            curr=curr->next;
            if(lists[pq.top().second]->next!=NULL){
                pq.emplace(lists[pq.top().second]->next->val,pq.top().second);
                lists[pq.top().second]=lists[pq.top().second]->next;
            }
            pq.pop();
        }
        return ans->next;
        
    }
};