/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* helper(Node* head){
        Node* curr= head;
        while(curr && (curr->next!=NULL || curr->child!=NULL)){
            if(curr->child==NULL){
                curr=curr->next;
            }
            else{
                Node* temp=curr->next;

                curr->next=curr->child;
                curr->next->prev=curr;
                Node* tail=helper(curr->child);
                curr->child=NULL;
                if(temp) temp->prev=tail;
                tail->next=temp;
                curr=tail;
            }
        }
        return curr;
    }
    Node* flatten(Node* head) {
        Node* curr=head;
        helper(curr);
        return head;
    }
};