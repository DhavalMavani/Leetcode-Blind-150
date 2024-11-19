class BrowserNode{
public:
    string url;
    BrowserNode* prev;
    BrowserNode* next;
    BrowserNode(string url, BrowserNode* prev,BrowserNode* next){
        this->url=url;
        this->prev=prev;
        this->next=next;
    }
};

class BrowserHistory {
public:
    BrowserNode* curr=NULL;
    BrowserHistory(string homepage) {
        curr=new BrowserNode(homepage,NULL,NULL);
    }
    
    void visit(string url) {
        BrowserNode* temp=new BrowserNode(url,curr,NULL);
        curr->next=temp;
        curr=temp;
    }
    
    string back(int steps) {
        while(steps-- && curr->prev) curr=curr->prev;
        return curr->url;
    }
    
    string forward(int steps) {
        while(steps-- && curr->next) curr=curr->next;
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

//  ["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
// [["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]
// [null,null,null,null, "facebook.com","google.com","facebook.com",null,"linkedin.com","google.com","leetcode.com"]

// ["leetcode.com"],["google.com"],["facebook.com"],["linkedin.com"]