class Node{
public:
    int val,key;
    Node *next, *prev;
    Node(){ next=NULL,prev=NULL;}
    Node(int v,int k){key=k,val=v, next=NULL,prev=NULL;}
    Node(int v,int k,Node *p,Node *n){key=k,val=v, next=n,prev=p;}
};


class LRUCache {
public:
    int cap;
    Node *lr; //leastRecent
    Node *mr; //mostRecent
    unordered_map<int,Node*> ump;
    LRUCache(int capacity) {
        cap=capacity;
        lr=new Node(-1,-1);
        mr=new Node(-1,-1,lr,NULL);
        lr->next=mr;
    }
    
    int get(int key) {
        if(!ump.count(key)) return -1;

        Node* n=ump[key];
        n->prev->next=n->next;
        n->next->prev=n->prev;

        mr->prev->next=n;
        n->prev=mr->prev;
        mr->prev=n;
        n->next=mr;
        
        return n->val;
    }
    
    void put(int key, int value) {
        if( ump.count(key) ){

            Node* n=ump[key];
            n->prev->next=n->next;
            n->next->prev=n->prev;

            mr->prev->next=n;
            n->prev=mr->prev;
            mr->prev=n;
            n->next=mr;

            n->val=value;
            return;
        }

        if(cap==0){
            int del=lr->next->key;
            Node* temp=lr->next->next;
            lr->next=temp;
            temp->prev=lr;
            ump.erase(del);
            cap++;
        }

        Node* temp=new Node(value,key,mr->prev,mr);
        ump[key]=temp;
        mr->prev->next=temp;
        mr->prev=temp;
        cap--;
    }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */